#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int Calculo_Volume_Esfera(int vetor[],int n,int *s);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int vet[10];
    int soma=0;

    for(int i=0; i<10; i++)
    {
        vet[i]=rand()%10+1;
    }
    Calculo_Volume_Esfera(vet,10,&soma);
}
int Calculo_Volume_Esfera(int vetor[],int n,int *s)
{
    for(int i=0; i<10; i++)
    {
        printf("%d,",vetor[i]);
        *s=*s+vetor[i];
    }
    printf("\n\nResultado da SOMA: %d\n",*s);
}
