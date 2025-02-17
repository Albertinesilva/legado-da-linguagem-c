#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void multiplicacao(int vet[],int n,int *p);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int vetor[5];
    int *ponteiro=vetor;
    int i=0;

    for(int i=0; i<5; i++)
    {
        printf("\nDigite o %d° número: ",i+1);
        fflush(stdin);
        scanf("%d",&vetor[i]);
    }
    printf("\n\n");
    /*for(int i=0; i<5; i++)
    {
        vetor[i]=*ponteiro*2;
        ++ponteiro;
    }*/

    multiplicacao(vetor,5,ponteiro);

    for(int i=0; i<5; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");
}
void multiplicacao(int vet[],int n,int *p)
{
   for(int i=0; i<n; i++)
    {
        vet[i]=*p*2;
        ++p;
    }
}
