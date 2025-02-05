#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void menu(void);
int imprime_dias (int quant);
int imprime_mes (int mes);
void imprime_dia_mes_ano (void);
void imprime_meses30_dias(void);
void imprime_meses31_dias(void);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int opcao=0, quantdias=0, num=0;
    int data=0;
    char dias[50];


    while(opcao!=6)
    {

        menu();

        printf("\n\tOPÇÃO: ");
        scanf("%d",&opcao);
        system ("cls");
        switch(opcao)
        {
        case 1:
            printf("\n\t1-Janeiro\n\t2-Feverreiro\n\t3-Março\n\t4-Abril\n\t5-Maio\n\t6-Junho\n\t7-Julho\n\t8-Agosto\n\t9-Setembro\n\t10-Outubro\n\t11-Novembro\n\t12-Dezembro\n");
            printf("\n\t");
            scanf("%d",&quantdias);
            imprime_dias(quantdias);
            break;

        case 2:
            printf("\n\tInforme um número referente ao mês desejado: ");
            scanf("%d",&num);
            imprime_mes(num);
            break;

        case 3:
           imprime_dia_mes_ano();
            break;

        case 4:
            imprime_meses30_dias();
            break;

        case 5:
            imprime_meses31_dias();
            break;

        case 6:

            printf("\n\tObrigado, volte sempre!\n");
            break;
        }
    }
}
void menu (void)
{
    printf("\n\t--------------------------------MANIPULAÇÃO DE DATAS---------------------------------\n");
    printf("\n\tESCOLHA A OPÇÃO DESEJADA:\n\n\t1-Imprime a quantidade de dias de um mês.");
    printf("\n\t2-Imprime o mês por extenso.\n\t3-Imprime uma data (DIA/MÊS/ANO) por estenso.");
    printf("\n\t4-Imprime por extenso todos os meses que possuem 30 dias.\n\t5-Imprime por estenso todos os meses que possuem 31 dias.");
    printf("\n\t6-Sair do programa.\n");
    printf("\n\t");
}
int imprime_dias(int quant)
{
    switch(quant)
    {
    case 1:
        printf("\n\tJaneiro tem 30 dias\n");
        break;

    case 2:
        printf("\n\tFeverreiro tem 28 dias\n");
        break;

    case 3:
        printf("\n\tMarço tem 31 dias\n");
        break;

    case 4:
        printf("\n\tAbril tem 30 dias\n");
        break;

    case 5:
        printf("\n\tMaio tem 31 dias\n");
        break;

    case 6:
        printf("\n\tJunho tem 30 dias\n");
        break;

    case 7:
        printf("\n\tJulho tem 31 dias\n");
        break;

    case 8:
        printf("\n\tAgosto tem 31 dias\n");
        break;

    case 9:
        printf("\n\tSetembro tem 30 dias\n");
        break;

    case 10:
        printf("\n\tOutubro tem 31 dias\n");
        break;

    case 11:
        printf("\n\tNovembro tem 30 dias\n");
        break;

    case 12:
        printf("\n\tDezembro tem 31 dias\n");
        break;
    }

}
int imprime_mes(int mes)
{
    if(mes==1)
    {
        printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE JANEIRO!\n",mes);
    }
    else
    {
        if(mes==2)
        {
            printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE FEVERREIRO!\n",mes);
        }
        else
        {
            if(mes==3)
            {
                printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE MARÇO!\n",mes);
            }
            else
            {
                if(mes==4)
                {
                    printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE ABRIL!\n",mes);
                }
                else
                {
                    if(mes==5)
                    {
                        printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE MAIO!\n",mes);
                    }
                    else
                    {
                        if(mes==6)
                        {
                            printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE JUNHO!\n",mes);
                        }
                        else
                        {
                            if(mes==7)
                            {
                                printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE JULHO!\n",mes);
                            }
                            else
                            {
                                if(mes==8)
                                {
                                    printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE AGOSTO!\n",mes);
                                }
                                else
                                {
                                    if(mes==9)
                                    {
                                        printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE SETEMBRO!\n",mes);
                                    }
                                    else
                                    {
                                        if(mes==10)
                                        {
                                            printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE OUTUBRO!\n",mes);
                                        }
                                        else
                                        {
                                            if(mes==11)
                                            {
                                                printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE NOVEMBRO!\n",mes);
                                            }
                                            else
                                            {
                                                if(mes==12)
                                                {
                                                    printf("\n\tO NÚMERO %d É REFERENTE AO MÊS DE DEZEMBRO!\n",mes);
                                                }
                                                else
                                                {
                                                    printf("\n\tO NÚMERO %d É INVALIDO!\n",mes);
                                                }

                                            }

                                        }

                                    }

                                }

                            }

                        }

                    }

                }

            }

        }

    }

}
void imprime_dia_mes_ano(void)
{
    time_t t;
    time(&t);
    struct tm*data;
    data=localtime(&t);
    int d=data->tm_mday;
    int m=data->tm_mon +1;
    int a=data->tm_year +1900;
    printf("\n\t%d/%d/%d",d,m,a);
}
void imprime_meses30_dias(void)
{
    printf("\n\tMESES COM 30 DIAS:\n\n\tAbril\n\tJunho\n\tSetembro\n\tNovembro\n");
}
void imprime_meses31_dias(void)
{
    printf("\n\tMESES COM 31 DIAS:\n\n\tJaneiro\n\tMarço\n\tMaio\n\tJulho\n\tAgosto\n\tSetembro\n\tOutubro\n\tDezembro\n");
}



