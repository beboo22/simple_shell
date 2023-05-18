#include "shell.h"
/**
 * cmderror - prints error message
 * @n: n of program
 * @command: command not found
 */
void cmderror(char *n, char *command)
{
	write(STDERR_FILENO, n, _strlen(n));
	write(STDERR_FILENO, ": ", 2);
	print_number(errnum);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 13);

	exnum = 127;
}
/**
 * execerr - prints error message
 * @n: n of program
 * @command: name of command
 */
void execerr(__attribute__((unused))char *n, char *command)
{
	perror(command);
	exnum = 2;
}
/**
 * accesserr - prints error message
 * @n: name of program
 * @command: name of command
 */
void accesserr(char *n, char *command)
{
	write(STDERR_FILENO, n, _strlen(n));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": Permission denied\n", 20);
}
/**
 * exiterr - prints error message
 * @n: name of program
 * @inp: user input read by program
 */

void exiterr(char *n, char *inp)
{
	char *z;

	z = strtok(inp, "\n ");
	z = strtok(NULL, "\n ");

	write(STDERR_FILENO, n, _strlen(n));
	write(STDERR_FILENO, ": ", 2);
	print_number(errnum);
	write(STDERR_FILENO, ": exit: Illegal number: ", 24);
	write(STDERR_FILENO, z, _strlen(z));
	write(STDERR_FILENO, "\n", 1);
}
