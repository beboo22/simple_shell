#include "shell.h"
/**
 * _ls - list files
 * @di: directory
 * @f: option
 * @s: option
 **/
void _ls(const char *di, int f, int s)
{
	struct dirent *d;
	DIR *b = opendir(di);

	if (!b)
	{
		if (errno == ENOENT)
		{
			perror("Directory doesn't exist");
		}
		else
		{
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while ((d = readdir(b)) != NULL)
	{
		if (!f && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if (s)
			printf("\n");
	}
	if (!s)
		printf("\n");
}
/**
 * _env - print env
 * @argv: array of args
 * Return: 1 or 2
 **/
int _env(char **argv __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		if (write(STDOUT_FILENO, environ[i], _strlen(environ[i])) == -1)
		{
			perror("env");
			return (2);
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}
/**
 * _cd - change directory
 * @argv: array of arguments
 * Return: 1 or 2
 **/
int _cd(char **argv)
{
	if (argv[1] == NULL)
	{
		if (chdir(getenv("HOME")) == -1)
		{
			perror("cd");
			return (2);
		}
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			perror("cd");
			return (2);
		}
	}
	return (1);
}
/**
 * fexit - exit
 * @argv: array of args
 * Return: exit
 **/
int fexit(char **argv)
{
	int st;

	if (argv[1] == NULL)
	{
		free_arr(argv);
		exit(0);
	}
	else
	{
		st = _atoi(argv[1]);
		free_arr(argv);
		exit(st);
	}
	return (2);
}
