#include "shell.h"
/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **argv)
{
	char *str = NULL;
	char *str_cpy = NULL;
	char *token;
	const char *dlem = "\n";
	size_t n = 0;
	ssize_t npchar;
	int n_tok = 0;
	int i;
	(void)ac;

	while (1)
	{
		printf("cisfun$ ");
		npchar = getline(&str, &n, stdin);
		if (npchar == -1)
		{
			printf("exit\n");
			return (-1);
		}
		str_cpy = malloc(sizeof(char) * npchar);
		if (str_cpy == NULL)
		{
			printf("tsh: memory allocation error");
			return (-1);
		}
		strcpy(str_cpy, str);
		token = strtok(str, dlem);
		while (token != NULL)
		{
			n_tok++;
			token = strtok(NULL, dlem);
		}
		n_tok++;
		argv = malloc(sizeof(char *) * n_tok);
		token = strtok(str_cpy, dlem);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, dlem);
		}
		argv[i] = NULL;
		if (argv)
			exe(argv);
		}
	free(str);
	free(str_cpy);
	return (0);
}
