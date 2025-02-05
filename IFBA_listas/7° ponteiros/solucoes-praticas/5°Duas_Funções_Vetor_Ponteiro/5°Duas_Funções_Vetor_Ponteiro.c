#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int leitura_do_vetor(int vet[],int i)
{

    for(i=0; i<4; i++)
    {
        printf("Digite um número: ");
        fflush(stdin);
        scanf("%d",&vet[i]);
    }

}

float Calculo_Media_Vetor(int vetor[],int x)
{
    int *ponteiro;
    int *finalEndereco = vetor + x;
    float media=0;
    int soma=0;


    for(ponteiro=vetor; ponteiro<finalEndereco; ponteiro++)
    {
        soma += *ponteiro;
    }
    media=(float)soma/4;

    return media;
}


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int vetor[4];

    int leitura_do_vetor(int vet[],int i);
    float Calculo_Media_Vetor(int vetor[],int x);

    leitura_do_vetor(vetor,4);

    Calculo_Media_Vetor(vetor,4);
    printf("\nResultado da Média: %.1f\n",Calculo_Media_Vetor(vetor,4));




}
