#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int numero_habitantes=0, contador=0;
    float valor_kwh=0, consumo_mes=0,codigo_consumidor=0;
    float soma_consumo=0, media_consumo_habita=0;
    float maior=0, menor=99999,residencial=0, comercial=0, industrial=0;



    printf("\n\tInforme o número de habitantes da cidade: ");
    scanf("%i",&numero_habitantes);

    printf("\n\tInforme o valor R$: KWH  ");
    scanf("%f",&valor_kwh);

    while(contador!=numero_habitantes)
    {
        contador++;

        printf("\n\t%d° habitante, Informe o consumo do mês: ",contador);
        scanf("%f",&consumo_mes);

        soma_consumo += consumo_mes;

        printf("\n\n\t-------------------------CÓDIGO DO CONSUMIDOR-------------------------\n\n\t1: RESIDENCIAL\n\t2: COMERCIAL\n\t3: INDUSTRIAL\n ");
        scanf("%f",&codigo_consumidor);

        if(consumo_mes > maior)
        {
            maior = consumo_mes;

        }

        if(consumo_mes < menor)
        {
            menor = consumo_mes;
        }


        if(codigo_consumidor==1)
        {
            residencial += consumo_mes;
        }
        else
        {
            if(codigo_consumidor==2)
            {
                comercial += consumo_mes;
            }

            else
            {
                if(codigo_consumidor==3)
                {
                    industrial += consumo_mes;
                }

                else
                {
                    printf("\n\nCódigo inexistente!\n\n");
                }
            }
        }


    }

    media_consumo_habita=soma_consumo/numero_habitantes;
    system("cls");

    printf("\n\tMaior consumo: %.1f\n\tMenor consumo: %.1f\n",(maior*valor_kwh),(menor*valor_kwh));
    printf("\n\tMedia de consumo por habitantes: %.2f\n",(media_consumo_habita*valor_kwh));
    printf("\n\t-------------------------TOTAL DE CONSUMO DE CADA CATEGORIA-------------------------\n\n\n\tRESIDENCIAL %.2f\n\tCOMERCIAL: %.2f\n\tINDUSTRIAL: %.2f\n",residencial*valor_kwh,comercial*valor_kwh,industrial*valor_kwh);

}
