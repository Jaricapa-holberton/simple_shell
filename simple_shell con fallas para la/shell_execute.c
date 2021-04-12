#include "holberton.h"

int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
int shell_env(char **environ);


char *built_in_name[] = {"cd", "help", "exit"};
		int (*builtin_func[]) (char **) = {&shell_cd, &shell_help, &shell_exit};
/**
 * shell_num_builtins - count the amount of builtins avalibe
 * Return: return the number of builtins
 */
int shell_num_builtins(void)
{
	return (sizeof(built_in_name) / sizeof(char *));
}
/* Builtin function implementations. */
/**
 * shell_cd - change directory
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("expected argument to \"cd\"\n");
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
 * shell_help - display a help text of the shell
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int shell_help(char **args)
{
	int i;
	*args = *args;
	_puts("Jaime Aricapa and Frank Grijalba\n");
	_puts("Type program names and arguments, and hit enter.\n");
	_puts("The following are built in:\n");
	for (i = 0; i < shell_num_builtins(); i++)
	{
		_puts(built_in_name[i]);
		_puts(" \n");
	}
	_puts("Use the man command for information on other programs.\n");
	return (1);
}
/**
 * shell_exit - exit of the shell
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int shell_exit(char **args)
{
	return (0);
}
/**
 * shell_env - prints the environment
 * @environ: environ
 * Return: void
 */
int shell_env(char **environ)
{
	unsigned int i, length;

	i = 0;
	while (environ[i])
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
	return (1);
}

/**
 * shell_execute - execute the comands inserted from input
 * @args: array of strings with the arguments
 * Return: return 1 if success or 0 if exit is called
 */
int shell_execute(char **args)
{

	
	/* List of builtin commands, followed by their corresponding functions. */
	
	int i = 0, c = 0;
	struct stat st;
	char *path = NULL, *pathcat1 = NULL, *pathcat2 = NULL, *argenviron = NULL;
	char **environs = NULL;

	
	if (args[0] == NULL)
		return (1);
	path = _getenv("PATH");
	environs = shell_split_line(path);
	for (i = 0; i < _strlen(*environs); i++)
	{
		pathcat1 = str_concat(environs[i], "/");
		pathcat2 = str_concat(pathcat1, args[0]);
		c = stat(pathcat2, &st);
		if (c == 0)
		{
			argenviron = pathcat2;
			break;
		}
		pathcat1 = "";
		pathcat2 = "";
	}
	if (c == 0)
	{
		args[0] = argenviron;
		return (shell_launch(args));
	}
	else
	{

		
		for (i = 0; i < shell_num_builtins(); i++)
		{
			if (_strcmp(args[0], built_in_name[i]) == 0)
				return ((*builtin_func[i])(args));
		}
	}
	return (shell_launch(args));
}
