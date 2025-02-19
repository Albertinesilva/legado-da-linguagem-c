#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int Maior_Elemento_Repetiu_Numero_deVezes(int vet[],int n,int *Mai,int *y);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int quant=0;
    int ocorreu=0;
    int Maior=0;

    printf("\nInforme a quantidade de elementos do vetor: ");
    fflush(stdin);
    scanf("%d",&quant);

    int vetor[quant];
    for(int i=0; i<quant; i++)
    {
        vetor[i]=rand()%10+100;
    }
    Maior=vetor[0];
    for(int i=0; i<quant; i++)
    {
        printf("%d,",vetor[i]);
    }

    Maior_Elemento_Repetiu_Numero_deVezes(vetor,quant,&Maior,&ocorreu);
    printf("\nMaior elemento = %d\nNúmero de vezes que ocorreu = %d\n",Maior,ocorreu);
}
int Maior_Elemento_Repetiu_Numero_deVezes(int vet[],int n,int *Mai,int *y)
{
    int x=0;
    for(int i=0; i<n; i++)
    {
        if(vet[i]>*Mai)
        {
            *Mai=vet[i];

        }
    }
    for(int i=0; i<n; i++)
    {
        if(vet[i] == *Mai)
        {
            x++;
        }
    }
    *y=x;
}

