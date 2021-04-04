#include <stdio.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	extern char **environ;
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
	
}
