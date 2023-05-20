#include "shell.h"

/**
 * exitch - checks if input is "exit"
 * @inp: "exit"
 * @n: name of program
 * Return: 0 , -1
 */
int exitch(char *inp, char *n)
{
	int i, j, l, si, st;
	char *num;
	char *check = "exit";

	j = 0;
	l = _strlen(inp);
	si = l - 5;
	st = 0;
	for (i = 0; i < 4; i++)
	{
		if (check[i] != inp[i])
			return (0);
	}
	if (inp[4] != '\n' && inp[4] != ' ')
		return (0);

	if (l > 5)
	{
		num = malloc(sizeof(char) * si);
		for (i = 5; i < l - 1; i++)
		{
			if (inp[i] >= '0' && inp[i] <= '9')
			{
				num[j] = inp[i];
				j++;
			}
			else
			{
				exit_error(n, inp);
				free(num);
				exnum = 2;
				return (-1);
			}
		}
		num[j] = '\0';
		st = _atoi(num);
		free(num);
	}
	free(inp);
	exit(st);
}
/**
 * blankch - checks if input is blank (just a return)
 * @inp: "\n"
 * Return: 1 if inp is '\n', 0
 */
int blankch(char *inp)
{
	if (inp[0] == '\n')
		return (1);

	return (0);
}
/**
 * pathch - checks if command contains path
 * @command: check slash
 * Return: 0, -1
 */
int pathch(char *command)
{
	if (command[0] == '/')
		return (0);

	return (-1);
}
/**
 * envch - checks if command is env
 * @inp: "env"
 * Return: 1 if string is 'env' or 0
 */
int envch(char *inp)
{
	int i = 0;
	char *env = "env";

	if (_strlen(inp) != 4)
		return (0);

	while (env[i] != '\0')
	{
		if (env[i] != inp[i])
			return (0);
		i++;
	}
	return (1);
}
