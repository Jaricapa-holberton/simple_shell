#include "holberton.h"
/**
 * shell_read_line - get a line from the input in interative mode
 * Return: Return the line saved from the input
 */
char *shell_read_line(void)
{
	char *line = NULL;
	size_t  buffersize = 0;
	//* restrict
	/* have getline allocate a buffer for us */
	if (getline(&line, &buffersize, stdin) < 0)
	{
		if (feof(stdin))
		{
			/* We recieved an EOF */
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	// else
	// {
	// 	if (line[0] == '/')
	// 	{
	// 		while (i <_strlen(line))
	// 		{
	// 			if (line[i] == '\n'){
	// 			line[i] = '\0';
	// 			}else{
	// 				i++;
	// 			}				
	// 		}

	// 		execve(line, *line, NULL);
	// 		//shell_launch((char **)line);
	// 	}
		return (line);
}
