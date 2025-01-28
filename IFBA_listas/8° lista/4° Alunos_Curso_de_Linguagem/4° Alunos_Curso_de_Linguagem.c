#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

//ESTRUTURA DE CADASTRO DE ALUNOS
struct cadastro_curso
{
    float num_matricula;
    char nome[30];
    float nota[15];
} vetor[5];

//FUNÇÃO QUE RECEBE INSTRUÇÕES DA ESTRUTURA, PARA SABER QUAL A MAIOR NOTA NA 1° PROVA
struct cadastro_curso primeira_maiornota(struct cadastro_curso notas[],int i,float primeira[],int y,float maior_nota);

//FUNÇÃO QUE RECEBE INSTRUÇÕES DA ESTRUTURA PARA SABER QUAL MAIOR E MENOR MÉDIA
struct cadastro_curso media_geral (struct cadastro_curso media_geral[],int x);

void main()
{
    setlocale(LC_ALL,"portuguese");


    int i=0,y=0,cont=1,x=0;
    float primeira_nota[5],maior=0;
    bool verdade=true;

    printf("\n\n\t\t------------------------------CURSO DE LINGUAGEM C------------------------------\n\n");

    for(i=0; i<5; i++)
    {

        printf("\nInforme a matrícula do %d° aluno: ",i+1);
        scanf("%f",&vetor[i].num_matricula);

        printf("\nInforme o nome do %d° aluno: ",i+1);
        setbuf(stdin, NULL);
        gets(vetor[i].nome);

        verdade=true;


        //INSTRUÇÃO PARA DESCOBRIR A MAIOR NOTA
        while(verdade)

        {
            printf("\nInforme a %d° nota do aluno: ",cont);
            setbuf(stdin, NULL);
            scanf("%f",&vetor[y].nota[y]);

            cont++;
            maior=vetor[0].nota[0];

            //O VETOR É ABASTECIDO SEMPRE COM A 1° NOTA DE TODOS OS ALUNOS
            if(y==0||y==3||y==6||y==9||y==12)
            {
                primeira_nota[i]=vetor[y].nota[y];
            }

            y++;

            //INSTRUÇÃO PARA SAIR DO LAÇO DE REPETIÇÃO
            if(y==3||y==6||y==9||y==12||y==15)
            {
                cont=1;
                verdade=false;
            }
        }
        printf("\n---------------------------------\n");
    }

    printf("\n\n*************************************RESULTADO*************************************\n\n");

    //IMPRIME A MAIOR NOTA COM O NOME DO ALUNO
    primeira_maiornota(vetor,i,primeira_nota,y,maior);

    //IMPRIME A MAIOR MÉDIA E MENOR MÉDIA COM O NOME DOS ALUNOS
    media_geral(vetor,i);


}
//FUNÇÃO QUE RECEBE E PASSA INSTRUÇÕES
struct cadastro_curso primeira_maiornota(struct cadastro_curso notas[],int i,float primeira[],int y,float maior_nota)
{
    char nome[40];

    //INSTRUÇÃO PARA DESCOBRIR A MAIOR NOTA DA 1° PROVA
    for(y=0; y<5; y++)
    {
        if(primeira[y]>maior_nota)
        {
            maior_nota=primeira[y];
            strcpy(nome,vetor[y].nome);
        }
    }

    printf("\n%s tirou a maior nota na primeira prova: %.2f \n",nome,maior_nota);

};
//FUNÇÃO QUE RECEBE E PASSA INSTRUÇÕES
struct cadastro_curso media_geral (struct cadastro_curso media_geral[],int x)
{
    float soma=0,media=0,y=0;
    float maior_media=0,menor_media=999;
    int cont=0,candidato_maior=0,candidato_menor=0;
    char nome_menor[40],nome_maior[40];
    bool verdade=true;

    //LAÇO DE REPETIÇÃO (FOR): DOS CINCO ALUNOS
    for(x=0; x<5; x++)
    {
        verdade=true;

        //FAZ A SOMA DAS TRÊS PROVAS DE CADA ALUNO
        while(verdade)
        {
            soma+=vetor[cont].nota[cont];
            cont++;

            //TIRA A MÉDIA E SAI DO LAÇO DE REPETIÇÃO
            if(cont==3||cont==6||cont==9||cont==12||cont==15)
            {
                media=soma/3;
                verdade=false;
            }

        }

        //FAZ A VERIFICAÇÃO DA MAIOR MÉDIA E ABASTECE UMA VARIAVEL PARA SER TESTADA LOGO ABAIXO.
        if(media>maior_media)
        {
            maior_media=media;
            candidato_maior=x;
        }
        //FAZ A VERIFICAÇAO DA MENOR MÉDIA E ABASTECE UMA VARIAVEL PARA SER TESTADA LOGO ABAIXO
        if(media<menor_media)
        {
            menor_media=media;
            candidato_menor=x;
        }

        media=0;
        soma=0;
    }

    //INSTRUÇÃO PARA DESCOBRIR A MAIOR MÉDIA, PARA IMPRIMIR COM O NOME DO ALUNO
    for(x=0; x<=candidato_maior; x++)
    {
        if(x==candidato_maior)
        {
            strcpy(nome_maior,media_geral[candidato_maior].nome);
        }

    }

    printf("\n%s ficou com a maior média %.2f\n",nome_maior,maior_media);

    //INSTRUÇÃO PARA DESCOBRIR A MENOR MÉDIA, PARA IMPRIMIR COM O NOME DO ALUNO
    for(y=0; y<=candidato_menor; y++)
    {
        if(y==candidato_menor)
        {
            strcpy(nome_menor,media_geral[candidato_menor].nome);
        }

    }

    printf("\n%s ficou com a menor média %.2f\n\n",nome_menor,menor_media);


};
