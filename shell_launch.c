#include "holberton.h"
/**
 * main - function main balblabla
 * @var1: balbla
 * @var2: balblab
 * Return: return balblabva
 */
int shell_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		/* cambiar execvp */
		if (execve(args[0], args, NULL) == -1)
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
		pid_t wpid;
		/* Parent process */
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
