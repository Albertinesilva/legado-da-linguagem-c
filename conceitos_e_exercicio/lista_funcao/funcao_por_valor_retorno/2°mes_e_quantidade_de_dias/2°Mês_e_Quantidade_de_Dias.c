#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Imprime_Mes_QuantDias(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int mes=0;

    printf("\nInforme o número referente ao MÊS: ");
    fflush(stdin);
    scanf("%d",&mes);

    Imprime_Mes_QuantDias(mes);
}
void Imprime_Mes_QuantDias(int n)
{
    switch(n)
    {
    case 1:
        printf("\nNúmero 1 é referente ao mês de Janeiro\nJaneiro tem 31 dias\n");
        break;

    case 2:
        printf("\nNúmero 2 é referente ao mês de Fevereiro\nFevereiro tem 28 dias\n");
        break;

    case 3:
        printf("\nNúmero 3 é referente ao mês de Março\nMarço tem 31 dias\n");
        break;

    case 4:
        printf("\nNúmero 4 é referente ao mês de Abril\nAbril tem 30 dias\n");
        break;

    case 5:
        printf("\nNúmero 5 é referente ao mês de Maio\nMaio tem 31 dias\n");
        break;

    case 6:
        printf("\nNúmero 6 é referente ao mês de Junho\nJunho tem 30 dias\n");
        break;

    case 7:
        printf("\nNúmero 7 é referente ao mês de Julho\nJulho tem 31 dias\n");
        break;

    case 8:
        printf("\nNúmero 8 é referente ao mês de Agosto\nAgosto tem 31 dias\n");
        break;

    case 9:
        printf("\nNúmero 9 é referente ao mês de Setembro\nSetembro tem 30 dias\n");
        break;

    case 10:
        printf("\nNúmero 10 é referente ao mês de Outubro\nOutubro tem 30 dias\n");
        break;

    case 11:
        printf("\nNúmero 11 é referente ao mês de Novembro\nNovembro tem 30 dias\n");
        break;

    case 12:
        printf("\nNúmero 12 é referente ao mês de Dezembro\nDezembro tem 31 dias\n");
        break;

        default:
        printf("\nOpção invalida!\n");
        break;
    }
}
