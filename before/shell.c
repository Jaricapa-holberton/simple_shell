#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//int input(char *s,int length);

int main()
{
	while (1)
	{
		char *buffer;
		size_t bufsize = 32;
		size_t characters;
		
		buffer = malloc(bufsize * sizeof(char));
		if( buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
			
		}
		
		printf("$ ");
		characters = getline(&buffer,&bufsize,stdin);
		
		//buffer--;
		char *piece = strtok((char *)buffer, " ");
		while(piece != NULL){
			printf("%s\n", piece);
			piece = strtok(NULL, " ");
			printf("%lu", characters);
		}
		
		//printf("%zu characters were read.\n",characters);
		//printf("You typed: '%s'\n",buffer);
		int status;

		if(fork() == 0)
		{
			execve((char)piece[0], (char)piece, NULL);
			exit(0);
		}
		wait(&status);
		free(buffer);
	}
	return(0);
}
