#include "shell.h"
/**
 * _fpath - path
 * @path: path
 * Return: 1 or 0
 **/
int _fpath(char *path)
{
	if (_strlen(path) > 3)
	{
		if ((path[0] == '.' && path[1] == '/') || path[0] == '/' ||
			(path[0] == '.' && path[1] == '.' && path[2] == '/'))
			return (1);
	}
	return (0);
}
