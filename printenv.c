#include "shell.h"
/**
 * pr_env - print env var
 * @env: array of env var
 */
void pr_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
