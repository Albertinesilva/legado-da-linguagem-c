#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct aluno
{
    int matricula;
    char nome[15];
    float nota[3];
};

int Indice_com_Maior_Media(struct aluno p[],int n,int *x);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int quant=0,i=0;

    printf("\nInforme a quantidade de alunos: ");
    fflush(stdin);
    scanf("%d",&quant);

    struct aluno vetor[quant];

    Indice_com_Maior_Media(vetor,quant,&i);
    printf(" é do %d° Aluno: %s\n",i,vetor[i-1].nome);
}
int Indice_com_Maior_Media(struct aluno p[],int n,int *x)
{
    float media=0,soma=0,maior=0;

    for(int i=0; i<n; i++)
    {
        printf("\n%d° ALUNO:\n",i+1);
        printf("\nDigite o número da matricula: ");
        fflush(stdin);
        scanf("%d",&p[i].matricula);

        printf("\nDigite o seu nome: ");
        fflush(stdin);
        gets(p[i].nome);

        for(int y=0; y<3; y++)
        {
            printf("\nDigite a %d° Nota: ",y+1);
            fflush(stdin);
            scanf("%f",&p[i].nota[y]);
            soma+=p[i].nota[y];
        }
        media=soma/3;
        if(media > maior)
        {
            maior=media;
            *x=i+1;
        }
        soma=0;
    }
    for(int i=0; i<n; i++)
    {
        printf("\n%d° ALUNO:\n",i+1);
        printf("\nNúmero da matricula: %d",p[i].matricula);

        printf("\nNome do Aluno: %s",p[i].nome);

        for(int y=0; y<3; y++)
        {
            printf("\nNota do Aluno: %.2f",p[i].nota[y]);
        }
        printf("\n");

    }
    printf("\nMaior Média = %.2f",maior);
}

