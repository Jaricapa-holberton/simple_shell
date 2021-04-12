#ifndef SHELL_BASIC_H
#define SHELL_BASIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

/* File prototypes */
void shell_loop(void);
char *shell_read_line(void);
char **shell_split_line(char *line);
int shell_launch(char **args);
int shell_execute(char **args);

/* Functions for Built-in commands*/
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
int shell_num_builtins(void);
/* Environment variables and Function´s */
char *_getenv(const char *name);
extern char **environ;

/* Functions for strings */
int _strlen(char *string);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif