#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int vetor[20];
    int i=0,aux=0,j=0;

    for(i=0; i<10; i++)
    {
        printf("\nInforme um número para o vetor: ");
        scanf("%d",&vetor[i]);
    }
    i=0;
    j=10-1;

    while(i<j)
    {
        aux=vetor[i];
        vetor[i]=vetor[j];
        vetor[j]=aux;
        j--;
        i++;

    }
    printf("\n\n");
    //printf("%d,",vetor[i]);
    for(i=0; i<10;i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n\n");
}
