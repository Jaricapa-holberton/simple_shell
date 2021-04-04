#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
/**
 * get_dir - This function tokenize the directory.
 * @line: String input
 * Return: Array
 */

char **get_dir(char *line)
{
	const char limit[2] = ":";
	int i;
	int contpnt = 0;
	char **array = NULL;

	for (i = 0; line[i] != 0; i++)
	{
		if (line[i] == limit[0])
			contpnt++;
		
	}

	array = malloc(sizeof(char *) * (contpnt + 2));

	array[0] = strtok(line, limit);
	for (i = 1; i <= contpnt; i++)
	{
		array[i] = strtok(NULL, limit);
		
	}
	array[i] = NULL;
	return (array);
	
}

/**
 * main - This function that prints each directory contained in
 * the environment variable PATH, one directory per line.
 * @argc: Number of arguments
 * @argv: String of arguments
 * Return: Value 0
 */

int main(int argc, char *argv[])
{
	struct dirent *pDirent;
	DIR *pDir;
	char **sDir;
	int dirs = 0;

	/*Ensure correct argument count.*/
	if (argc != 2)
	{
		printf("Usage: testprog <dirname>\n");
		return (1);
		
	}

	if (argv[1] == NULL)
	{
		printf("ERROR NULL ARGUMENT");
		
	}

	sDir = get_dir(argv[1]);
	while (sDir[dirs] != 0)
	{
		/* Ensure we can open directory.*/
		pDir = opendir(sDir[dirs]);
		if (pDir == NULL)
		{
			printf("Cannot open directory '%s'\n", sDir[dirs]);
			return (1);
			
		}
		/*Process each entry.*/
		while ((pDirent = readdir(pDir)) != NULL)
		{
			printf("[%s]\n", pDirent->d_name);
			
		}
		dirs++;

		printf("+---------------------------------------+\n");
		/* Close directory and exit.*/
		closedir(pDir);
		
	}
	free(sDir);
	printf("TOTAL DIRECTORIES %d\n", dirs);
	return (0);
	
}
