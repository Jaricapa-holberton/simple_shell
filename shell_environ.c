#include "holberton.h"
/**
 * _getenv - Get the string of a environtment varible
 * @name: The name of the varible to find
 * Return: return the string founded
 */
char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	int len = _strlen((char *)name);
	char **env = environ;
	char *str = malloc(sizeof(str) * 1024);

	while (env[i][j] != '\0')
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
					str[k] = (env[i][len + j + 1]);
					k++;
					j++;
				}
				return ((char *)str);
			}
		}
	}
}
