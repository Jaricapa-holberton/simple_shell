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

void sig_handler(int sig_c);

/* Structure for function pointers to Built-in commands*/
/**
 * struct builtins_func - Structure for function pointers to Built-in commands
 * @indic: Command given.
 * @function: The function associated to command given.
 */
typedef struct builtins_func
{
	char *indic;
	int (*function)(char **);
	
} built;

void lsh_loop(void);
char *lsh_read_line(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_launch(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

/* Functios for Built-in commands*/
int env_func(__attribute__((unused))char **p);
int exit_func(__attribute__((unused))char **pr);
int cd_func(char **pr);
int wrong_built(__attribute__((unused))char **pr);
int (*get_built_func(char **gu))(char **);

/* Environment variables and Function´s */
extern char **environ;
char *_getenv(char *name);
char **search_in_path(char **arr);
char *check_path(char *route);


/* Functions for strings */
int _strlen(char *string);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **get_pointers_array(char *line, char *limit);
char *_pathcat(char *argument, char *route);
int _putchar(char c);
void _puts(char *str);

/* Create and execute new process */
int new_process(char **argument);
void status_exec(char **argument);

#endif
