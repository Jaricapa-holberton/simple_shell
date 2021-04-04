#include "exercises.h"

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
list_t *add_node_end(list_t **head, char *str)
{
	list_t *endnode = NULL;
	list_t *end = NULL;

	endnode = malloc(sizeof(list_t));
	if (!endnode)
		return (NULL);
	if (!*head)
	{
		endnode->str = str;
		endnode->next = NULL;
		*head = endnode;
		return (endnode);
		
	}
	end = *head;
	while (end->next)
	{
		end = end->next;
		
	}
	endnode->str = str;
	end->next = endnode;
	endnode->next = NULL;
	return (endnode);
	
}
size_t print_list(list_t *h)
{
	size_t contnodes;

	contnodes = 0;

	while (h)
	{
		if ((*h).str)
			printf("%s\n", (*h).str);
		else
			printf("(nil)\n");
		h = h->next;
		contnodes++;
		
	}
	return (contnodes);
	
}
void free_list(list_t *head)
{
	list_t *mempoint = NULL;

	while (head)
	{
		mempoint = head->next;
		free(head);
		head = mempoint;
		
	}
	
}
int main(int argc, char *argv[])
{
	char **direcs = NULL;
	unsigned int i = 0;
	list_t *head = NULL;

	if (argc != 2)
	{
		printf("ERROR\n");
		return (-1);
		
	}
	if (!argv[1])
	{
		printf("Pase un argumento != NULL\n");
		return (-1);
		
	}

	direcs = get_dir(argv[1]);

	while (direcs[i])
	{
		add_node_end(&head, direcs[i]);
		i++;
		
	}
	print_list(head);
	free_list(head);
	free(direcs);
	head = NULL;
	return (0);
}
