#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_strdup(char *s);

void print_number(int n);
int _atoi(char *s);

extern int exnum;
extern int errnum;

void exe(char **argv);
void cmderror(char *n, char *command);
void accesserr(char *n, char *command);
void exiterr(char *n, char *inp);
void execerr(char *n, char *command);

void fork_wait_exec(char **commands, char **arr_path, char **env,
		    char *n, char *inp);

int exitch(char *inp, char *n);
int blankch(char *inp);
int pathch(char *command);
int envch(char *inp);
#endif
