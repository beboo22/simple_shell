#include "shell.h"
/**
 * fpath - find PATH of
 * @arrpath: array of dirs
 * @command: command to find path
 * Return: path or NULL
 */
char *fpath(char **arrpath, char *command)
{
	int a, b, f = 0, x = 0, directory_length, command_length, total_length;
	char *path;

	for (a = 0; arrpath[a] != NULL; a++)
	{
		directory_length = _strlen(arrpath[a]);
		command_length = _strlen(command);
		total_length = directory_length + command_length;
		path = malloc(sizeof(char) * (total_length + 2));
		if (path == NULL)
		{
			free_array(arrpath);
			return (NULL);
		}
		b = 0;
		while (b < directory_length)
		{
			path[b] = arrpath[a][b];
			b++;
		}
		path[b] = '/';
		b = 0;
		while (b < command_length)
		{
			path[directory_length + b + 1] = command[b];
			b++;
		}
		path[total_length + 1] = '\0';
		f = access(path, F_OK);
		x = access(path, X_OK);
		if (f == 0)
		{
			if (x == 0)
				return (path);
			free(path);
			return ("no_access");
		}
		free(path);
	}
	return (NULL);
}
