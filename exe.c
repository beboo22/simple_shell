#include "shell.h"
void exe(char **argv)
{
	pid_t pid;
	int exe;

	char *command = NULL, *check = NULL;
	command = argv[0];
	check = get_location(command);
	pid = fork();
	if (pid == 0)
	{
		exe = execve(argv[0], argv, NULL);
		if (exe == -1)
			perror("Error");
	} else if (pid < 0)
	{
		fprintf(stderr, "fork failed");
	} else
	{
		wait(NULL);
	}
}
