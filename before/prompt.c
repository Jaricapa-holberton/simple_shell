#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	/* int bytes_leidos; */
	/* size_t numero_bytes = 0; */
	//ssize_t y size_t son sinónimos de unsigned int
	char *cadena = NULL; /* *input */

	printf("$ ");
	gets(cadena);
	/* cadena = getline(&input, &numero_bytes, stdin); */
	/* if (bytes_leidos == -1) */
	/*{ */
	/* printf("Error."); */
	/* } */
	/* else */
	/* { */
		/* puts("La línea es:"); */
	printf("%s\n", cadena);
	/*} */
	free(cadena);
	return 0;
}
