#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    float vetor[10];

     for(int i=0; i<10; i++)
     {
         printf("\n%d° Elemento, Endereço: %p",i+1,&vetor[i]);
     }

}
