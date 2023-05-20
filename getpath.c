#include "shell.h"
/**
 * getpath - n of dirs
 * @path: PATH
 * Return: n of dirs
 */
int getpath(char *path)
{
	int i, counter;

	i = 0;
	counter = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '=' || path[i] == ':')
			counter++;
		i++;
	}

	return (counter);
}
/**
 * arrpath - array of PATH
 * @env: env
 * Return: array of strings
 */
char **arrpath(char **env)
{
	unsigned int a, b, cpath;
	int compare = 0;
	char *t1, *t2,  *currentpath;
	char **pathar;

	a = 0;
	b = 0;
	while (env[a] != NULL)
	{
		compare = _strcmp(env[a], "PATH");
		if (compare == 0)
		{
			currentpath = _strdup(env[a]);
			cpath = getpath(currentpath);
			t1 = strtok(currentpath, "=");
			t1 = strtok(NULL, "=");
			pathar = malloc(sizeof(char *) * (cpath + 1));
			if (pathar == NULL)
				return (NULL);
			if (t1[0] == ':')
			{
				pathar[b] = _strdup("./");
				b++;
				t2 = strtok(t1, ":");
				t2 = strtok(NULL, ":");
			}
			else
				t2 = strtok(t1, ":");
			while (b < cpath)
			{
				pathar[b] = _strdup(t2);
				b++;
				t2 = strtok(NULL, ":");
			}
		}
		a++;
	}
	pathar[cpath] = NULL;
	free(currentpath);
	return (pathar);
}
