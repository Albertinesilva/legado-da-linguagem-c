#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int Maior_e_Menor_Valor(int vet[],int n,int *Mai,int *Men);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int quant=0;
    int Maior=0,Menor=0;

    printf("\nInforme a quantidade de elementos do vetor: ");
    fflush(stdin);
    scanf("%d",&quant);

    int vetor[quant];

    for(int i=0; i<quant; i++)
    {
        vetor[i]=rand()%100+1;
    }
    for(int i=0; i<quant; i++)
    {
        printf("%d,",vetor[i]);
    }
    Menor=vetor[0];

    Maior_e_Menor_Valor(vetor,quant,&Maior,&Menor);
    printf("\n\nMaior = %d\nMenor = %d\n",Maior,Menor);
}
int Maior_e_Menor_Valor(int vet[],int n,int *Mai,int *Men)
{
    for(int i=0; i<n; i++)
    {
        if(vet[i]>*Mai)
        {
            *Mai=vet[i];
        }
        if(vet[i]<*Men)
        {
            *Men=vet[i];
        }

    }
}

