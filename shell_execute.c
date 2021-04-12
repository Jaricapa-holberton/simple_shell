#include "holberton.h"
/**
 * shell_execute - execute the comands inserted from input
 * @args: array of strings with the arguments
 * Return: return 1 if success or 0 if exit is called
 */
int shell_execute(char **args)
{
	/* List of builtin commands, followed by their corresponding functions. */
	char *builtin_str[] = {"cd", "help", "exit", "env"};
	int i = 0, c = 0;
	struct stat st;
	char *path = NULL, *pathcat1 = NULL, *pathcat2 = NULL, *argenviron = NULL;
	char **environs = NULL;

	int (*builtin_func[]) (char **) = {&shell_cd, &shell_help, &shell_exit, &shell_env};
	if (args[0] == NULL)
		return (1);
	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
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
		_puts("Command not found\n");
		return(1);
	}
}
