#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct cadastro
{
    char nome[30];
    char endereco[50];
    char telefone[20];
    char ddd[5];
}agenda[5];


void main()
{
    setlocale(LC_ALL,"portuguese");

    int i=0;

    for(i=0; i<5; i++)
    {
        printf("\nDigite o nome do %d° cliente: ",i+1);
        fflush(stdin);
        gets(agenda[i].nome);

        printf("\nDigite o endereço de %s: ",agenda[i].nome);
        fflush(stdin);
        gets(agenda[i].endereco);

        printf("\nInforme o telefone de %s com DDD: ",agenda[i].nome);
        fflush(stdin);
        gets(agenda[i].telefone);
        printf("\n");
    }

    for(i=0; i<5; i++)
    {
        printf("\nNOME----------: %s",agenda[i].nome);
        printf("\nENDEREÇO------: %s",agenda[i].endereco);
        printf("\nTELEFONE------: %s",agenda[i].telefone);
        printf("\n");
    }
}

