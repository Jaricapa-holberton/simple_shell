#include "holberton.h"
/**
 * shell_read_line - get a line from the input in interative mode
 * Return: Return the line saved from the input
 */
char *shell_read_line(void)
{
  char *line = NULL;
  ssize_t buffersize = 0;

  /* have getline allocate a buffer for us */
  if (getline(&line, &buffersize, stdin) == -1)
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
  return (line);
}
