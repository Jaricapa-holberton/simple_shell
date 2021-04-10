#include "holberton.h"
/* Function Declarations for builtin shell commands: */
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
/* List of builtin commands, followed by their corresponding functions. */
char *builtin_str[] = {"cd", "help", "exit"};
int (*builtin_func[]) (char **) = {&shell_cd, &shell_help, &shell_exit};
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int shell_num_builtins()
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
int shell_cd(char **args)
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
int shell_help(char **args)
{
	int i;
	*args = *args;
	/* cambiar los printf */
	_puts("Jaime Aricapa and Frank Grijalba\n");
	_puts("Type program names and arguments, and hit enter.\n");
	_puts("The following are built in:\n");
	for (i = 0; i < shell_num_builtins(); i++)
	{
		_puts(builtin_str[i]);
		_puts(" \n");
	}
	_puts("Use the man command for information on other programs.\n");
	return (1);
}
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int shell_exit(char **args)
{
	*args = *args;
	return (0);
}

/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int shell_execute(char **args)
{
	int i = 0, c = 0;
	struct stat st;
	char *path = NULL, *pathcat1 = NULL, *pathcat2 = NULL, *argenviron = NULL;
	char **environs = NULL;
	
if (args[0] == NULL)
	{
		/* An empty command was entered.*/
		return (1);
	}

	//Trae el contenido de el entorno PATH
	path = _getenv("PATH");
	//Split para cada ":" de las rutas de entorno
	environs = shell_split_line(path);

		/*for (i = 0; i < _strlen(*environs); i++){
			printf("environs[%i]--> %s\n", i, environs[i]);
		}*/

	for (i = 0; i < _strlen(*environs); i++){
	
	pathcat1 = str_concat(environs[i], "/");
	pathcat2 = str_concat(pathcat1, args[0]);
		
	c = stat(pathcat2,&st);

	if (c == 0){
	argenviron = pathcat2;
	break;
	}
	pathcat1 = "";
	pathcat2 = "";
}

if (c == 0){
	//free(pathcat2);
	args[0] = argenviron;
	return (shell_launch(args));
}else{
	//free(pathcat2);
	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0) 
			return ((*builtin_func[i])(args));
	}
}
	return (shell_launch(args));
}
