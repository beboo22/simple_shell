#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 1000

void exe(char **argv);

/* Read a line of input from the user. */
ssize_t read_input(char **input) {
	ssize_t chars_read;
	size_t buffer_size = 0;
	printf("cisfun$ ");
	chars_read = getline(input, &buffer_size, stdin);
	if (chars_read == -1) {
		printf("exit\n");
		return -1;
	}
	return chars_read;
}

/* Split a string into tokens and return the number of tokensالتعديلات المقترحة:
 *
 * ```c
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <unistd.h>
 *
 * #define MAX_ARGS 1000
 *
 * void exe(char **argv);
 *
 *//* Read a line of input from the user. */
ssize_t read_input(char **input) {
	ssize_t chars_read;
	size_t buffer_size = 0;

	printf("cisfun$ ");
	chars_read = getline(input, &buffer_size, stdin);
	if (chars_read == -1) {
		printf("exit\n");
		return -1;
	}

	return chars_read;
}

/* Split a string into tokens and return the number of tokens */
int tokenize_input(char *input, char **argv) {
	const char *delim = " \n";
	char *token;
	int num_tokens = 0;

	token = strtok(input, delim);
	while (token != NULL && num_tokens < MAX_ARGS - 1) {
		argv[num_tokens++] = token;
		token = strtok(NULL, delim);
	}
	argv[num_tokens] = NULL;

	return num_tokens;
}

/* Main loop */
int main(int argc, char **argv) {
	char *input = NULL;
	ssize_t chars_read;
	char *argv_copy[MAX_ARGS];
	int num_tokens;

	while (1) {
		chars_read = read_input(&input);
		if (chars_read ==-1) {
			break;
		}

		// Make a copy of the input string to tokenize
		strcpy(input_copy, input);
		// Tokenize the input string
		num_tokens = tokenize_input(input_copy, argv_copy);
		// Execute the command
		if (num_tokens > 0) {
			exe(argv_copy);
		}
	}

	free(input);
	return 0;
}

/* Execute a command */
void exe(char **argv) {
	pid_t pid;

	pid = fork();
	if (pid == 0) {
		execvp(argv[0], argv);
		perror("Error:");
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		fprintf(stderr, "fork failed");
	} else {
		wait(NULL);
	}
}
