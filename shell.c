#include "shell.h"
/**
 * func - fun
 * @inp: input
 **/
void func(int inp)
{
	char *z = NULL;
	size_t x = 0;
	ssize_t a = 0;

	while (1)
	{
		if (inp)
			write(STDOUT_FILENO, "$ ", 2);
		a = getline(&z, &x, stdin);
		if (a == EOF)
		{
			free(z);
			exit(0);
		}
		if (_strcmp(z, "\n"))
		{
			execute(z);
			z = NULL;
		}
	}
}
/**
 * main - main
 * Return: 0 success
 **/
int main(void)
{
	func(isatty(STDIN_FILENO));
	return (0);
}
