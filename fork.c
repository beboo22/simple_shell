#include "shell.h"
/**
* _fork - fork
* @argv: array of args
* Return: return
**/
int _fork(char **argv)
{
	pid_t _pi, ch;
	int st;

	ch = fork();
	if (ch == -1)
		perror("hsh");

	if (ch == 0)
	{
		_pi = execve(argv[0], argv, environ);
		if (_pi == -1)
			exit(1);
	}
	else
		wait(&st);

	return (WEXITSTATUS(st));
}
