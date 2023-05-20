#include "shell.h"

int exnum = 0;
int errnum = 0;
/**
 * main - main
 * @argc: args
 * @argv: array of args
 * @env: array of env var
 * Return: 0 always
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char *inp = NULL;
	char **commands = NULL;
	char **arr_path = NULL;
	size_t n_of_bytes = 0;
	ssize_t bytes = 0;
	char *n = argv[0];
	int atty = isatty(0);

	while (1)
	{
		errnum++;
		if (atty)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		bytes = getline(&inp, &n_of_bytes, stdin);
		if (bytes == -1)
		{
			free(inp);
			exit(exnum);
		}
		if (exitch(inp, n) == -1)
			continue;
		if (blankch(inp) == 1)
			continue;
		if (envch(inp) == 1)
		{
			pr_env(env);
			continue;
		}
		arr_path = arrpath(env);
		commands = parse(inp, arr_path, n);
		if (commands != NULL)
		{
			fork_then_wait_then_exec(commands, arr_path, env, n, inp);
			free_arr(commands);
			free_arr(arr_path);
		}
	}
	return (0);
}
