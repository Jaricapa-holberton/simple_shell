#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//int input(char *s,int length);

int main(/*int argc, char *argv[], char *envp[]*/)
{
	char *linebuffer = NULL;
	char *arrcommand[32], *token;
	size_t i = 0, n;
	int status, checkline;
	while (1)
	{
		/* start */
		printf("$ ");
		/* get the line and check if fails */
		checkline = getline(&linebuffer,&n,stdin);
		if (checkline == -1)
			break;
		/* get the tokes of linebuffer to get che commands */
		token = strtok(linebuffer, " \t\n\r");
		while(i < 16 && token != NULL)
		{
			/* save the token in a position of arrcommand */
			arrcommand[i] = token;
			token = strtok(NULL, " ");
		}
		/* create the child process */
		if(fork() == 0)
		{
			/* chek if fails the child */
			if (execve(arrcommand[0], arrcommand, NULL))
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		/* check if the child end */
		if (fork() > 0)
			wait(&status);
	}
	putchar('\n');
	free(linebuffer);
	exit(status);
}
