#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int vetor[],int n);

void main()
{
    int vet[5];
    int *ponteiro=vet;

    imprime_vetor(vet,5);
    for(int i=0; i<5; i++)
    {
        printf("%d,",*(ponteiro + i));
    }
}
void imprime_vetor(int vetor[],int n)
{
   for(int i=0; i<5; i++)
   {
       vetor[i]=i+10;
   }
}
