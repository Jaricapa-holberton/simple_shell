#include "holberton.h"
/**
 * shell_launch - execute a binary file with commands
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fails
 */
int shell_launch(char **args)
{
	pid_t pid;
	int status;
	pid_t wpid;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			free(args[0]);
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */

		perror("lsh");
	}
	else
	{
		/* Parent process */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		wpid = 0;
	}
	free(args[0]);
	if (wpid == 0)
	{
		wpid = 1;
		return (wpid);
	}
	else
	{
		return (1);
	}
}
