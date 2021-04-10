#include "holberton.h"
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
void shell_loop(void)
{
	char *line = NULL;
	char **args = NULL;
	int status = 0;
	

	do
	{
		/* cambiar printf */
		_puts("$ ");
		line = shell_read_line();
		args = shell_split_line(line);
		status = shell_execute(args);

		free(line);
		free(args);		  
	}
	while (status);
}
