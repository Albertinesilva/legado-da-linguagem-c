#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int Ordene_os_Valores(int vet[],int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int quant=0;

    printf("\nInforme a quantidade de elementos do vetor: ");
    fflush(stdin);
    scanf("%d",&quant);

    int vetor[quant];
    for(int i=0; i<quant; i++)
    {
        vetor[i]=rand()%10+1;
    }
    for(int i=0; i<quant; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");

    Ordene_os_Valores(vetor,quant);
    printf("\n");
    for(int i=0; i<quant; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");
}
int Ordene_os_Valores(int vet[],int n)
{
    int aux=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(vet[i]>vet[j])
            {
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
}

