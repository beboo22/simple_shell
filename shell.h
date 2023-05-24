#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <wait.h>
#include <stddef.h>
#include <errno.h>
#include <dirent.h>

/**
 * struct fs - the shell builtins
 * @t: name of builtins
 * @o: what the builtins do (or function)
 **/
typedef struct fs
{
	char *t;
	int (*o)(char **p);

} bue;
int _env(char **av);
int _cd(char **av);
int fexit(char **av);
char **_split(const char *st, const char d);
void free_arr(char **tow);
char *_genv(const char *n);
char *f_path(char **exe);
int _fpath(char *path);
void execute(char *l);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *s);
void free_arr(char **array);
int _putchar(char c);
void printnum(int n);
int _atoi(char *s);
int _fork(char **argv);
int _exec(char **argv);
void _error(char *n, char *err);
#endif
