#include "holberton.h"
#define SHELL_TOK_BUFFERSIZE 64
#define SHELL_TOK_DELIM " :\t\r\n\a"
/**
 * shell_split_line - splits the line in tokens
 * @line: get the line from input
 * Return: Return an array of strings of args to execute
 */
char **shell_split_line(char *line)
{
	int buffersize = SHELL_TOK_BUFFERSIZE, position = 0;
	char **arraystr = malloc(buffersize * sizeof(char *));
	char *str;

	if (!arraystr)
	{
		perror("lsh");
		exit(EXIT_FAILURE);
	}
	str = strtok(line, SHELL_TOK_DELIM);
	while (str != NULL)
	{
		arraystr[position] = str;
		position++;
		if (position >= buffersize)
		{
			buffersize += SHELL_TOK_BUFFERSIZE;
			str = _realloc(arraystr, buffersize, (buffersize *
							      (2 * sizeof(char *))));
			if (!arraystr)
			{
				perror("lsh");
				exit(EXIT_FAILURE);
			}
		}
		str = strtok(NULL, SHELL_TOK_DELIM);
	}
	arraystr[position] = NULL;
	return (arraystr);
}
