#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int i;
	pid_t pid;

	for (i = 0; i < 5; i++) {
		pid = fork();
		if (pid == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			execlp("ls", "ls", "-l", "/tmp", NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		} else {
			/* Parent process */
			int status;
			waitpid(pid, &status, 0);
			if (WIFEXITED(status)) {
				printf("Child %d exited with status %d\n", pid, WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("Child %d terminated by signal %d\n", pid, WTERMSIG(status));
			} else {
				printf("Child %d exited abnormally\n", pid);
			}
		}
	}

	return 0;
}
