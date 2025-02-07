#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int Somar_Par_e_Impar(int vet[],int n,int *soma_par,int *soma_Impar);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int quant=0;
    int somaPar=0,somaImpar=0;

    printf("\nDigite a quantidade de elementos que você deseja para o vetor: ");
    fflush(stdin);
    scanf("%d",&quant);
    int vetor[quant];

    for(int i=0; i<quant; i++)
    {
        vetor[i]=rand()%10+1;
    }

    Somar_Par_e_Impar(vetor,quant,&somaPar,&somaImpar);
    printf("\nSoma dos número PARES = %d\nSoma dos números IMPARES = %d\n",somaPar,somaImpar);

}
int Somar_Par_e_Impar(int vet[],int n,int *soma_par,int *soma_Impar)
{
    for(int i=0; i<n; i++)
    {
        printf("%d,",vet[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        if(vet[i]%2==0)
        {
            *soma_par+=vet[i];
        }
        else
        {
            *soma_Impar+=vet[i];
        }
    }
}
