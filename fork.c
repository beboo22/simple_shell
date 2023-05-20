#include "shell.h"
/**
 * fork_wait_exec - executes commands by first forking a child process
 * then executing in that child while the parent process waits
 * @commands: commands
 * @arr_path: directories in PATH
 * @env: env var
 * @n: name of program
 * @inp: input
 */
void fork_wait_exec(char **commands, char **arr_path, char **env,
		    char *n, char *inp)
{
	pid_t pid;
	int st, exec_check;

	st = 0;
	pid = fork();
	if (pid == -1)
	{
		perror(n);
		exnum = 1;
		_exit(1);
	}
	else if (pid == 0)
	{
		exec_check = execve(commands[0], commands, env);
		if (exec_check < 0)
		{
			exec_error(n, commands[0]);
			free_array(arr_path);
			free_array(commands);
			free(inp);
			exnum = 126;
			_exit(126);
		}
		exnum = 0;
		_exit(0);

	}
	exnum = 0;
	wait(&st);
}
