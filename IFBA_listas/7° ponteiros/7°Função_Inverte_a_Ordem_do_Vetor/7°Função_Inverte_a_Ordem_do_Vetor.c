#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int inverte_vetor(int n, int* vet)
{
    int aux,x;
    int vetor[n];

    for(int i=0,j=n-1; i<n; i++,j--)
    {
        vetor[j]=vet[i];
    }
    for(int y=0; y<n; y++)
    {
        vet[y]=vetor[y];
    }

}

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int inverte_vetor(int n,int* vet);
    int x;

    printf("\nInforme a quantidade do vetor: ");
    fflush(stdin);
    scanf("%d",&x);

    int vetor[x];


    for(int i=0; i<x; i++)
    {
        vetor[i]=rand()%10+100;
    }
    printf("\n");

    for(int i=0; i<x; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");
    inverte_vetor(x,vetor);
    printf("\n");
    for(int j=0; j<x; j++)
    {
        printf("%d,",vetor[j]);
    }
    printf("\n");
}



