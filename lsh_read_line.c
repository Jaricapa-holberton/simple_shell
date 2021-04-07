#include "holberton.h"
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
/* version without getline */
char *lsh_read_line(void)
{
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		/* cambiar fprintf y stderr */
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* Read a character */
		/* cambiar getchar */
		c = getchar();
		/* If we hit EOF, replace it with a null character and return.*/
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		// If we have exceeded the buffer, reallocate.
		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			/* cambiar realloc */
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				/* cambiar fprintf y stderr */
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
