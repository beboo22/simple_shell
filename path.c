#include "shell.h"
/**
 * g_path - get path
 * @path: path
 * @n: name
 * Return: Path
 **/
char *g_path(char *path, char *n)
{
	char *g;

	if (path == NULL || n == NULL)
		return (NULL);
	g = malloc(sizeof(char) *
		(_strlen(path) + _strlen(n) + 2));
	if (!g)
		return (NULL);
	strcpy(g, path);
	g[_strlen(path)] = '/';
	g[_strlen(path) + 1] = '\0';
	strcat(g, n);

	return (g);
}
/**
 * f_path - find path
 * @exe: execute
 * Return: path
 **/
char *f_path(char **exe)
{
	char **array, *p, *path;
	int i = 0;
	struct stat st;

	path = getenv("PATH");
	if (strlen(path) == 0)
		return (NULL);

	array = _split(path, ':');
	if (!array)
		return (NULL);

	while (array[i] != NULL)
	{
		p = g_path(array[i], *exe);
		if (stat(p, &st) == 0)
		{
			free(*exe);
			*exe = p;
			free_arr(array);
			return (p);
		}
		free(p);
		i++;
	}
	free_arr(array);
	return (NULL);
}
