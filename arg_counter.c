#include "shell.h"
/**
 * arg_counter - count the number of arguments
 * @user_input: string of user input
 * Return: number of arguments
 *     */
int arg_counter(char *inp)
{
	int i, args, k;

	args = 1;
	i = 0;
	k = 0;
	while (inp[i] != '\0' && inp[i] != '\n')
	{
		if (inp[i] != ' ')
			k = 1;
		if (inp[i] == ' ' && inp[i + 1] != ' '
				&& inp[i + 1] != '\n' && k == 1)
			args++;
		i++;
	}
	return (args);
}
