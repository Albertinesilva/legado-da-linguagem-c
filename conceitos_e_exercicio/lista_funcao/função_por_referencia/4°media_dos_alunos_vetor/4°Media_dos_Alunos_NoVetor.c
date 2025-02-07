#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

float Media_dos_Alunos(float vetor[],int n,float *m);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    float vet[10];
    float media=0;

    for(int i=0; i<10; i++)
    {
        vet[i]=rand()%10+1;
    }
    Media_dos_Alunos(vet,10,&media);
    printf("\n\nMédia dos Alunos: %.2f\n",media);
}
float Media_dos_Alunos(float vetor[],int n,float *m)
{
    int soma=0;
    for(int i=0; i<10; i++)
    {
        printf("(%.2f),",vetor[i]);
        soma=soma+vetor[i];
    }
    *m=(float)soma/10;

    return *m;
}
