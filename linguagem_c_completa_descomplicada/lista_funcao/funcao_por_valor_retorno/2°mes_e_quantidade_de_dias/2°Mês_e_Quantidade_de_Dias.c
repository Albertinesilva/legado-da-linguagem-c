#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Imprime_Mes_QuantDias(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int mes=0;

    printf("\nInforme o n�mero referente ao M�S: ");
    fflush(stdin);
    scanf("%d",&mes);

    Imprime_Mes_QuantDias(mes);
}
void Imprime_Mes_QuantDias(int n)
{
    switch(n)
    {
    case 1:
        printf("\nN�mero 1 � referente ao m�s de Janeiro\nJaneiro tem 31 dias\n");
        break;

    case 2:
        printf("\nN�mero 2 � referente ao m�s de Fevereiro\nFevereiro tem 28 dias\n");
        break;

    case 3:
        printf("\nN�mero 3 � referente ao m�s de Mar�o\nMar�o tem 31 dias\n");
        break;

    case 4:
        printf("\nN�mero 4 � referente ao m�s de Abril\nAbril tem 30 dias\n");
        break;

    case 5:
        printf("\nN�mero 5 � referente ao m�s de Maio\nMaio tem 31 dias\n");
        break;

    case 6:
        printf("\nN�mero 6 � referente ao m�s de Junho\nJunho tem 30 dias\n");
        break;

    case 7:
        printf("\nN�mero 7 � referente ao m�s de Julho\nJulho tem 31 dias\n");
        break;

    case 8:
        printf("\nN�mero 8 � referente ao m�s de Agosto\nAgosto tem 31 dias\n");
        break;

    case 9:
        printf("\nN�mero 9 � referente ao m�s de Setembro\nSetembro tem 30 dias\n");
        break;

    case 10:
        printf("\nN�mero 10 � referente ao m�s de Outubro\nOutubro tem 30 dias\n");
        break;

    case 11:
        printf("\nN�mero 11 � referente ao m�s de Novembro\nNovembro tem 30 dias\n");
        break;

    case 12:
        printf("\nN�mero 12 � referente ao m�s de Dezembro\nDezembro tem 31 dias\n");
        break;

        default:
        printf("\nOp��o invalida!\n");
        break;
    }
}
