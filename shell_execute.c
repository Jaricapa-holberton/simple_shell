#include "holberton.h"

/**
 * shell_execute - execute the comands inserted from input
 * @args: array of strings with the arguments
 * Return: return 1 if success or 0 if exit is called
 */
int shell_execute(char **args)
{
	char *builtin_str[] = {"cd", "help", "exit"};
	int i = 0, c = 0;
	struct stat st;
	char *path = NULL, *pathcat1 = NULL;
	char *enviroment = NULL;
	char **environs = NULL, *pathcat2 = NULL, *argenviron = NULL;

	int (*builtin_func[]) (char **) = {&shell_cd, &shell_help, &shell_exit};
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
	else if (c == -1)
	{
		for (i = 0; i < shell_num_builtins(); i++)
		{
			if (_strcmp(args[0], builtin_str[i]) == 0)
				return ((*builtin_func[i])(args));
		}
		c = 1;
	}
	if (c == 1)
	{
		enviroment = _getenv(args[0]);
		if (enviroment != NULL)
		{
			write(STDOUT_FILENO, enviroment, _strlen(enviroment));
			write(STDOUT_FILENO, "\n", 2);
			return (1);
		}
	}
	else
	{
		return (shell_launch(args));
	}
}
