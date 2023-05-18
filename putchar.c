#include "shell.h"
/**
* _putchar - prints a single character
* @c: character
* Return: 1 
*/
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
