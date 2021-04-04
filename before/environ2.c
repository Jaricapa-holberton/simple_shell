#include <stdio.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	extern char **environ;
	unsigned int i;

	printf("%p\n", &*env);
	printf("%p\n", &*environ);
	i = 0;
	while (environ[i] != NULL && env[i] != NULL)
	{
		/* Env argument */
		printf("Env[%d]: %s\n", i, env[i]);
		/* Environ function */
		printf("Environ[%d]: %s\n", i, environ[i]);
		i++;
	}
	return (0);
	
}
