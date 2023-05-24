#include "shell.h"
/**
 * _split - split string
 * @st: string
 * @d: delimeter
 * Return: array of strings
 **/
char **_split(const char *st, const char d)
{
	char **s = NULL;
	int i = 0, j, y = 0;

	while (st[i] != '\0' && st[i] == d)
		i++;
	if (!st[i])
		return (NULL);
	i = 0;
	while (st[i])
	{
		j = i;
		if (st[i] != d)
		{
			s = _realloc(s, sizeof(char *) * y,
						 sizeof(char *) * (y + 1));
			s[y] = NULL;
			while (st[j] && st[j] != d)
			{
				s[y] = _realloc(s[y], (j - i), ((j - i) + 1));
				s[y][j - i] = st[j];
				j++;
			}
			s[y] = _realloc(s[y], (j - i), ((j - i) + 1));
			s[y][j - i] = '\0';
			i += (j - i);
			y++;
		}
		else
			i++;
	}
	s = _realloc(s, sizeof(char *) * y, sizeof(char *) * (y + 1));
	s[y] = NULL;

	return (s);
}
