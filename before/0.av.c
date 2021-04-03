#include <stdio.h>

int main(int ac, char **av)
{
   int count = 0;
   ac = ac;
   if(av != NULL){
      while (av[count])
      count++;
   }
   count--;
printf("Cantidad de parametros recibidos: %d\n", count);
return (count);
}