#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    char nome[20];
    int dia,mes,ano;

} dados;


int main()
{

    dados pessoa[6];
    dados maioridade,menoridade;

    for(int i=0; i<6; i++)
    {
        printf("\nDigite o seu nome: ");
        fflush(stdin);
        gets(pessoa[i].nome);

        printf("\nDigite o dia: ");
        fflush(stdin);
        scanf("%d",&pessoa[i].dia);

        printf("\nDigite o mes: ");
        fflush(stdin);
        scanf("%d",&pessoa[i].mes);

        printf("\nDigite o ano: ");
        fflush(stdin);
        scanf("%d",&pessoa[i].ano);
    }
    menoridade=pessoa[0];
    maioridade=pessoa[0];

    for(int i=0; i<6; i++)
    {
        if(maioridade.ano >= pessoa[i].ano)
        {
            if(maioridade.ano > pessoa[i].ano)
            {
                maioridade=pessoa[i];
            }
        }
        else
        {
            if(maioridade.mes >= pessoa[i].mes)
            {
                if(maioridade.mes == pessoa[i].mes)
                {
                    if(maioridade.dia > pessoa[i].mes)
                    {
                        maioridade=pessoa[i];
                    }
                    else
                    {
                        maioridade=pessoa[i];
                    }
                }
            }
        }

        if(menoridade.ano <= pessoa[i].ano)
        {
            if(menoridade.ano < pessoa[i].ano)
            {
                menoridade=pessoa[i];
            }
        }
        else
        {
            if(menoridade.mes <= pessoa[i].mes)
            {
                if(menoridade.mes == pessoa[i].mes)
                {
                    if(menoridade.dia < pessoa[i].mes)
                    {
                        menoridade=pessoa[i];
                    }
                    else
                    {
                        menoridade=pessoa[i];
                    }
                }
            }
        }
    }

    printf("\nPessoa mais velha\nNome: %s\nPessoa mais nova\nNome: %s\n",menoridade.nome,maioridade.nome);
    system("pause");
    return 0;
}



