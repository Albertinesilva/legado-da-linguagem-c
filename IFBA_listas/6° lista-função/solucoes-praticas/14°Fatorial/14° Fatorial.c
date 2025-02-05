#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int fatorial (int fat);
int menu (char pesquisa[],int n);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0,continuar=1;
    char sim_ou_nao[4];
    char opcao='1';

    while(opcao!='0')
    {

        printf("\n\tDigite um número para calcular o fatorial: ");
        scanf("%d",&num);

        fatorial(num);

        do
        {
            printf("\n\tDeseja continuar com a pesquisa de fatorial:\n\n\tDigite [sim] para continuar ou [não] para encerrar: ");
            fflush(stdin);
            gets(sim_ou_nao);

            int result=menu(sim_ou_nao,4);
            printf("\n\tResultado: %d",result);

            if(result==2)
            {
                continuar=-1;
            }
            else
            {
                if(result==3)
                {
                    continuar=-1;
                    opcao='0';
                }
                else
                {
                    if(result==0)
                    {
                        continuar=1;
                    }
                }
            }
        }
        while(continuar>0);
    }
}

int fatorial (int fat)
{
    int i=0;
    int resultado=1;

    for (i=1; i<=fat; i++)
    {
        resultado=resultado*i;
    }
    printf("\n\t-------------------------RESULTADO DO FATORIAL-------------------------\n");
    printf("\n\tFATORIAL DE %d É: %d\n",fat,resultado);
}
int menu(char pesquisa[], int n)
{
    int i=0,encerrar=0;
    char nao[4]="não",sim[4]="sim",m_nao[4],m_sim[4];
    strcpy(m_nao,strupr(nao));
    strcpy(m_sim,strupr(sim));

    for(i=0; i<strlen(pesquisa); i++)
    {
        if(pesquisa[i]=='s')
        {
            encerrar=0;
        }
        else
        {
            if(pesquisa[i]=='n')
            {
                encerrar=0;
            }
            else
            {
                if(pesquisa[i]==nao[i]||pesquisa[i]==m_nao)
                {
                    encerrar=3;
                }
                else
                {
                    if(pesquisa[i]==sim[i]||pesquisa[i]==m_sim)
                    {
                        encerrar=2;
                    }

                }

            }
        }
    }

    return encerrar;
}
