#include "holberton.h"
/**
 * shell_loop - make a infinite loop
 * Return: return void
 */
void shell_loop(char **args)
{
	char *promptline = NULL;
	char **lineargs = NULL;
	int status = 0;

	do {
		if (isatty(STDIN_FILENO))
		{
			/* print the prompt */
			_puts("#cisfun$ ");
		}
		/* read the line from input */
		promptline = shell_read_line();
		/* tokenize the args from input */
		lineargs = shell_split_line(promptline);
		/* execute the program as the args says */
		status = shell_execute(lineargs);

	if (status == 2)
    {
      _puts((char *)args[0]);
      _puts(": ");
      _puts("1");
      _puts(": ");
      _puts(lineargs[0]);
      _puts(": ");
      _puts("not found\n");
      status = 1;
    }
    		/* free before new iteration */
		
		free(promptline);
		free(lineargs);
							
		/* infinite loop minewhile status = 1 */
	} while (status);


}
