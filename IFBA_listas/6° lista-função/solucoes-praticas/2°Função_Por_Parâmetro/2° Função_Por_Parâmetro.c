#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int meses(int mes);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int mesdo_ano=0;

    printf("\n\tInforme o MÊS: ");
    scanf("%d",&mesdo_ano);

    int quat=meses(mesdo_ano);

    if(quat != -1)
    {
        printf("\n\tO MÊS %d TEM %d DIAS\n",mesdo_ano,quat);
    }
    else
    {
        printf("\n\tMÊS INVÁLIDO!\n");
    }
}
int meses(int mes)
{
    int retorno = -1;

    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
    {
        retorno=31;
    }
    else
    {
        if(mes==4 || mes==6 || mes==9 || mes==11)
        {
            retorno=30;
        }
        else
        {
            if(mes==2)
            {
                retorno=28;
            }

        }
    }
    return retorno;
}
