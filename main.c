#include "holberton.h"
/**
 * main - function main
 * @argc: get a count of arguments
 * @argv: get a array of arguments
 * Return: return EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
/* Run command loop. */
  shell_loop(argv);
  /* Perform any shutdown/cleanup. */
  return (EXIT_SUCCESS);
}
