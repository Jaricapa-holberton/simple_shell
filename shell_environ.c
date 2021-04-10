#include "holberton.h"


char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	int len = _strlen((char *)name);
	extern char **environ;
	char **env = environ;
	char *str = malloc (sizeof(str) * 1024);

	while (*env[i] != '\0')
	{
		if (_strncmp(env[i], (char *)name, len) != 0)
		{
			i++;
		}
		else
		{
			if (env[i][len] == '=')
			{
				while (env[i][len + j] != '\0')
				{
					str[k] = (env[i][len + j]);
					k++;
					j++;
				}
				return ((char *)str);
			}
		}
	}
}
