#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct data
{
    int dia, mes, ano;
} Data;

int retornaQuantidadeDeDias(int mes)
{
    switch(mes)

    {

    case 1:
        return 31;
        break;
    case 2:
        return 28;
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    }
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    Data d1,d2;
    int numeroDias=0,mesAtual=0,aux=0;

    printf("1° Data\n");
    printf("Digite o dia: ");
    scanf("%d",&d1.dia);
    printf("\nDigite o Mês: ");
    scanf("%d",&d1.mes);
    printf("\nDigite o Ano: ");
    scanf("%d",&d1.ano);

    printf("\n2° Data\n");
    printf("Digite o dia: ");
    scanf("%d",&d2.dia);
    printf("\nDigite o Mês: ");
    scanf("%d",&d2.mes);
    printf("\nDigite o Ano: ");
    scanf("%d",&d2.ano);

    if(d1.ano == d2.ano)
    {
        if(d1.mes == d2.mes)
        {
            numeroDias = d2.dia - d1.dia;
        }
        else
        {
            mesAtual = d1.mes;
            aux = retornaQuantidadeDeDias(mesAtual);
            numeroDias += (aux - d1.dia);

            if(mesAtual != d2.mes)
            {
                mesAtual++;
                while(mesAtual < d2.mes)
                {
                    aux = retornaQuantidadeDeDias(mesAtual);
                    numeroDias += aux;
                    mesAtual++;
                }
            }
            numeroDias += d2.dia;
        }
    }
    else
    {
        mesAtual = d1.mes;
        aux = retornaQuantidadeDeDias(mesAtual);
        numeroDias += (aux - d1.dia);
        int anoAtual = d1.ano;


        if(anoAtual != d2.ano)
        {
            mesAtual++;
            while(mesAtual <= 12)
            {
                aux = retornaQuantidadeDeDias(mesAtual);
                numeroDias += aux;
                mesAtual++;
            }
        }

        anoAtual = d1.ano + 1;
        while(anoAtual < d2.ano)
        {
            numeroDias += 365;
            anoAtual++;
        }

        mesAtual = 1;
        while(mesAtual < d2.mes)
        {
            aux = retornaQuantidadeDeDias(mesAtual);
            numeroDias += aux;
            mesAtual++;
        }
        numeroDias += d2.dia;
    }
    printf("\nNúmero de dias = %d\n", numeroDias);
    return 0;
}
