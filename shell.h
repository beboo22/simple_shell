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
#endif
