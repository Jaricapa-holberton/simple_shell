#include "holberton.h"
/* Function Declarations for builtin shell commands: */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
/* List of builtin commands, followed by their corresponding functions. */
char *builtin_str[] = {"cd", "help", "exit"};
int (*builtin_func[]) (char **) = {&lsh_cd, &lsh_help, &lsh_exit};
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int lsh_num_builtins()
{
	return (sizeof(builtin_str) / sizeof(char *));
}
/* Builtin function implementations. */
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		/* cambiar fprintf y stderr */
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int lsh_help(char **args)
{
	int i;
	/* cambiar los printf */
	printf("Stephen Brennan's LSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return (1);
}
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int lsh_exit(char **args)
{
	return (0);
}

/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int lsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		/* An empty command was entered.*/
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0) 
			return ((*builtin_func[i])(args));
	}
	return (lsh_launch(args));
}
