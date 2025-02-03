#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct cadastro
{
    char nome[15];
    int idade;
    char endereco[20];
};

int Retorna_Ponteiro(struct cadastro *ponteiro,int n);

struct cadastro* Retorna_Ponteiro2(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;

    printf("\nDigite a quantidade de elementos do vetor: ");
    fflush(stdin);
    scanf("%d",&num);

    struct cadastro *vetor; //(struct cadastro *)malloc(num * sizeof(struct cadastro));
    vetor = Retorna_Ponteiro2(num);

    if(vetor == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");
        system("pause");
        exit(1);
    }

    Retorna_Ponteiro(vetor,num);

    for(int i=0; i<num; i++)
    {
        printf("\nNome: %s",vetor[i].nome);

        printf("\nIdade: %d",vetor[i].idade);

        printf("\nEndereço: %s\n",vetor[i].endereco);
    }
    free(vetor);
}
struct cadastro* Retorna_Ponteiro2(int n)
{
    return (struct cadastro *)malloc(n * sizeof(struct cadastro));
}

int Retorna_Ponteiro(struct cadastro *ponteiro,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\n%d° Cadastro",i+1);

        printf("\nDigite o seu nome: ");
        fflush(stdin);
        gets(ponteiro[i].nome);

        printf("\nDigite sua idade: ");
        fflush(stdin);
        scanf("%d",&ponteiro[i].idade);

        printf("\nInforme seu endereço: ");
        fflush(stdin);
        gets(ponteiro[i].endereco);
    }
    system("cls");
}

