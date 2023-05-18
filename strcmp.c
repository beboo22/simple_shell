#include "shell.h"
/**
 * _strcmp - comparing between two strings
 * @s1: string
 * @s2: string
 * Return: difference of strings or 0
 */
int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] != '\0' && s2[index] != '\0'; index++)
	{
		if (s1[index] < s2[index])
			return (s1[index] - s2[index]);

		else if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
	}
	return (0);
}
