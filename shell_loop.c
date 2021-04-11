#include "holberton.h"
/**
 * shell_loop - make a infinite loop
 * Return: return void
 */
void shell_loop(void)
{
	char *promptline = NULL;
	char **lineargs = NULL;
	int status = 0;

	do
	{
		/* print the prompt */
		_puts("#cisfun$ ");
		/* read the line from input */
		promptline = shell_read_line();
		/* tokenize the args from input */
		lineargs = shell_split_line(promptline);
		/* execute the program as the args says */
		status = shell_execute(lineargs);
		/* free before new iteration */
		free(promptline);
		free(lineargs);		  
	}
	/* infinite loop minewhile status = 1 */
	while (status);
}
