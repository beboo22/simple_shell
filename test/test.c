#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1) {
		printf("$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1) {
			break;
		}

		printf("%s", line);
	}

	free(line);
	return 0;
}
