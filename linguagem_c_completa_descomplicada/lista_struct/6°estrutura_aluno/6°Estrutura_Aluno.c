#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int matricula;
    char nome[30];
    float nota[3];
}disciplina;

int main()
{
    setlocale(LC_ALL,"portuguese");
    disciplina aluno[5];
    float soma=0,media=0,Maior_media=0;
    int indice=0;

    for(int i=0; i<5; i++)
    {
        printf("\nDigite o número da matricula do %d° Aluno: ",i+1);
        fflush(stdin);
        scanf("%f",&aluno[i].matricula);

        printf("\nDigite seu nome: ");
        fflush(stdin);
        gets(aluno[i].nome);

        for(int y=0; y<3; y++)
        {
            printf("\nDigite a %d° Nota: ",y+1);
            fflush(stdin);
            scanf("%f",&aluno[i].nota[y]);
            soma+=aluno[i].nota[y];
        }
        media=soma/3;
        if(media > Maior_media)
        {
            indice=i;
            Maior_media=media;
        }

        media=0;
        soma=0;
    }

    printf("\nNome: %s\n",aluno[indice].nome);
    for(int j=0; j<3; j++)
    {
        printf("Notas = %.2f\n",aluno[indice].nota[j]);
    }
    printf("Média do aluno = %f\n",Maior_media);

    system("pause");
    return 0;
}
