#include "holberton.h"
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int lsh_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		/* cambiar execvp */
		if (execvp(args[0], args) == -1)
		{
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
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
