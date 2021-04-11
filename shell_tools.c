#include "holberton.h"
/**
 * _strlen - this functions prints the lenght of a string
 * @s: string to print.
 * Description: this function prints the lenght of a string
 * section header: the header of this function is hsh.h
 * Return: retunrn the lenght in int
 **/
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
/**
 * _strdup - this functions copy a string.
 * @str: the string to copy
 * Description: this function copy a string)?
 * section header: the header of this function is hsh.
 * Return: this is a void function no return
 **/
char *_strdup(char *str)
{
	char *p;
	int i, s;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	p = malloc(i * sizeof(*str) + 1);
	if (p == NULL)
		return (NULL);
	for (s = 0; s < i; s++)
		*(p + s) = *(str + s);
	*(p + s) = '\0';
	return (p);
}
/**
 * _strncmp - this function compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: number to compare
 (* a blank line
 * Description: this function comparing two strings using the first value)?
(* section header: the header of this function is holberton.h)*
* Return: return a number depends os the resul fo comparation.
*/
int _strncmp(char *s1, char *s2, int n)
{

	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; (s1[i] != '\0' || s2[i] != '\0') &&	 i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * str_concat - concatenate to strings
 *@s1: string
 *@s2: string
 * Return: the string concat
 */
char *str_concat(char *s1, char *s2)
{
  char *array;
  int i = 0, l1 = 0, l2 = 0;

  if (s1 == NULL)
    s1 = "";
  if (s2 == NULL)
    s2 = "";

  while (s1[l1] != '\0')
  {
    l1++;
  }

  while (s2[l2] != '\0')
  {
    l2++;
  }

  array = malloc(sizeof(*array) * (l1 + l2 + 1));
  if (array == NULL)
    return (NULL);

  while (*s1)
  {
    array[i] = *s1;
    i++;
    s1++;
  }

  while (*s2)
  {
    array[i] = *s2;
    i++;
    s2++;
  }
  array[i] = '\0';
  return (array);
}
/**
 *_puts - prints a string
 *
 *@str: pointer that will store the string's location
 *
 *Return: nothing
 */
void _puts(char *str)
{
	while (*str != 0)
	{
		_putchar(*str);
		str++;
	}
}
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: is the size, in bytes, of the allocated space
 * @new_size: new size, in bytes of the new memory block
 * Return: pointer to the new memory block
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *ptr_cp, *r;

	if (new_size == old_size)
		return (ptr);

	if (!ptr)
		return (malloc(new_size));

	if (!new_size && ptr)
	{
		free(ptr);
		return (0);
	}

	ptr_cp = ptr;
	r = malloc(new_size);

	if (!r)
		return (0);

	for (i = 0; i < old_size; i++)
		r[i] = ptr_cp[i];

	free(ptr);
	return ((void *)r);
}
