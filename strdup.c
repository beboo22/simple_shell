#include "shell.h"
/**
 * _strdup - returns a pointer to new allocated space
 * @s: string
 * Return: pointer to new allocated space
 */

char *_strdup(char *s)
{
	int l, i;
	char *arr;

	l = 0;
	if (s == NULL)
		return (NULL);

	l = _strlen(s);

	arr = malloc((l + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < l; i++)
		arr[i] = s[i];

	arr[i] = '\0';

	return (arr);
}
