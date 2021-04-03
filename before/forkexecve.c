#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i;
	int status;
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	for(i = 0 ; i < 5; i++) /*loop will run n times (n=5)*/
	{
		if(fork() == 0)
		{
			execve(argv[0], argv, NULL);
			printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
			exit(0);
			    
		}
		/*else if (fork() == -1)
    {
      perror("Error");
      return (-1);
      
      }*/
	}
	for(i = 0 ; i < 5 ; i++) /* loop will run n times (n=5)*/
		wait(&status);

	return (0);
	
}
