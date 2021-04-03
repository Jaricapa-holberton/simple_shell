#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//falta definir el EOF y el ctrl + D

int main()
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("$ ");
    characters = getline(&buffer,&bufsize,stdin);

    //buffer--;
    char *piece = strtok((char *)buffer, " ");
        while(piece != NULL){
        printf("%s\n", piece);
        piece = strtok(NULL, " ");          
    }

    //printf("%zu characters were read.\n",characters);
    //printf("You typed: '%s'\n",buffer);
    free(buffer);
    return(0);
}
