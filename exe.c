#include "shell.h"

/**
 * exe - Execute a command.
 *
 * @argv: The command to execute and its arguments.
 */
void exe(char **argv)
{
	pid_t pid;
	int exe;

	pid = fork();
	if (pid == 0)
	{
		exe = execve(argv[0], argv, NULL);
		if (exe == -1)
			perror("Error:");
	} else if (pid < 0)
	{
		fprintf(stderr, "fork failed");
	} else
	{
		wait(NULL);
	}
}
