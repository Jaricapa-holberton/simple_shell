#include "holberton.h"
#define SHELL_TOK_BUFSIZE 64
#define SHELL_TOK_DELIM " :\t\r\n\a"

/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
char **shell_split_line(char *line)
{
	int bufsize = SHELL_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		/* cambiar fprintf y stderr */
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, SHELL_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			/* cambiar realloc */
			bufsize += SHELL_TOK_BUFSIZE;
			tokens = _realloc(tokens, bufsize, (bufsize * (2 * sizeof(char*))));
			if (!tokens)
			{
				/* cambiar fprintf y stderr */
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, SHELL_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
