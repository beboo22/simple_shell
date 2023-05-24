#include "shell.h"
/**
* _exec - execute
* @argv: array of args
* Return: 1 or 2
**/
int _exec(char **argv)
{
	bue buil[] = {{"cd", _cd}, {"exit", fexit},
	{"env", _env}, {NULL, NULL}};
	int i = 0;

	while (buil[i].t)
	{
		if (strcmp(buil[i].t, argv[0]) == 0)
			return (buil[i].o(argv));
		i++;
	}
	return (0);
}
/**
* execute - execute
* @l: l
**/
void execute(char *l)
{
	char **argv, *p;
	char **cm;
	int i = 0;

	l[_strlen(l) - 1] = '\0';
	cm = _split(l, ';');
	free(l);
	while (cm[i])
	{
		argv = _split(cm[i], ' ');
		i++;
		if (argv != NULL)
		{
			if (!_strcmp(argv[0], "exit"))
				free_arr(cm);

			if (!_exec(argv))
			{
				p = _strdup(argv[0]);

				if (_fpath(argv[0]) || f_path(&argv[0]))
				{
					_fork(argv);
				}
				else
					_error(argv[0], "not found\n");
				free(p);
			}
		free_arr(argv);
		}
	}
	free_arr(cm);
}
