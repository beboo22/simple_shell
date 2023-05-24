#include "shell.h"
/**
* _error - print error
* @n: name
* @err: string
**/
void _error(char *n, char *err)
{
	write(STDOUT_FILENO, "hsh: ", 5);
	write(STDOUT_FILENO, n, _strlen(n));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err, _strlen(err));
}
