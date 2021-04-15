
#include "holberton.h"
/**
 * shell_read_line - get a line from the input in interative mode
 * Return: Return the line saved from the input
 */
char *shell_read_line(void)
{
	char *line = NULL, *array = NULL;
	size_t  buffersize = 0;
	/* have getline allocate a buffer for us */
	if (getline(&line, &buffersize, stdin) < 0)
	{
		if (*line == EOF)
		{
			/* We recieved an EOF */
			exit(EXIT_SUCCESS);
		}
		else
		{
			return ((char *)array);
		}
	}

	return (line);
}
