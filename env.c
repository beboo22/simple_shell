#include "shell.h"
/**
 * _genv - env
 * @n: name
 * Return: env
 **/
char *_genv(const char *n)
{
	int i = 0, j;

	if (!n)
		return (NULL);
	while (environ[i])
	{
		j = 0;
		while (n[j] && n[j] == environ[i][j])
			j++;
		if (!n[j] && environ[i][j] == '=')
		{
			return (environ[i] + (j + 1));
		}
		i++;
	}
	return (NULL);
}
