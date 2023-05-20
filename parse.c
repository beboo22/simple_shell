#include "shell.h"
/**
 * parse - parses input
 * @inp: string to tokenize
 * @arrpath: array of dirs
 * @n: name of program
 * Return: an array of arguments
 */
char **parse(char *inp, char **arrpath, char *n)
{
	char **commands, *token, *directory_path = NULL;
	int args = 1, i = 0;

	args = arg_counter(inp);
	commands = malloc(sizeof(char *) * (args + 1));
	if (commands == NULL)
	{
		free_arr(arrpath);
		return (NULL);
	}
	token = strtok(inp, "\n ");
	if (pathch(token) == -1)
	{
		directory_path = fpath(arrpath, token);
		if (directory_path == NULL)
		{
			free(commands);
			free_arr(arrpath);
			cmderror(n, token);
			exnum = 127;
			return (NULL);
		}
		else if (_strcmp("no_access", directory_path) == 0)
		{
			free(commands);
			free_arr(arrpath);
			accesserr(n, token);
			exnum = 126;
			return (NULL);
		}
		commands[0] = _strdup(directory_path);
		free(directory_path);
	}
	else
		commands[0] = _strdup(token);
	for (i = 1; i < args; i++)
	{
		token = strtok(0, "\n ");
		commands[i] = _strdup(token);
	}
	commands[i] = NULL;
	return (commands);
}
