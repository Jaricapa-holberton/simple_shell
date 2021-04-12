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

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			//liberar (talvez) args[0]
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
		pid_t wpid;
		/* Parent process */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(args[0]);
	return (1);
}
