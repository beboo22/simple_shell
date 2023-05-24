#include "shell.h"
/**
 * func - func
 * @inp: inp
 **/
void func(int inp)
{
	char *z = NULL;
	size_t x = 0;
	ssize_t y = 0;

	while (1)
	{
		if (inp)
			write(STDOUT_FILENO, "$ ", 2);
		y = getline(&z, &x, stdin);
		if (y == EOF)
		{
			free_arr(z);
			exit(0);
		}
		if (_strcmp(z, "\n"))
		{
			exe(z);
			z = NULL;
		}
	}
}
/**
 * main - main
 * Return: 0
 **/
int main(void)
{
	func(isatty(STDIN_FILENO));
	return (0);
}
