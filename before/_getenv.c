
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char *_getenv(const char *name)
{
	int len = _strlen((char *)name);
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		if (_strncmp(*env, (char *)name, len) == 0 && env[0][len] == '=')
			return (*env + len + 1);
		env++;
		
	}
	return (NULL);
	
}
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		else
			i++;
		
	}
	return (0);
	
}
int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
		
	}
	return (l);
	
}
int main(void)
{
	printf("real getenv: %s\n", getenv("NAME"));
	printf("my getenv: %s\n", _getenv("NAME"));
	return (0);
	
}
