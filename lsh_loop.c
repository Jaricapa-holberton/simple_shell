#include "holberton.h"
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		/* cambiar printf */
		_puts("$ ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
		  
	}
	while (status);
}
