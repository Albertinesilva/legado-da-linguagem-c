#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int quant_voltas=0, contador=0, voltaque_melhor_tempocorreu=0;
    float tempo_cadavolta=0,melhortempo=1000,tempomedio_dasvoltas=0;
    float soma_tempo_cadavolta=0;


    printf("\n\tInforme quantas voltas tem a corrida de interlagos: ");
    scanf("%d",&quant_voltas);

    while(contador!=quant_voltas)
    {
        contador++;

        printf("\n\tQual foi o tempo feito pelo piloto Albert na %d° volta? ",contador);
        scanf("%f",&tempo_cadavolta);

        soma_tempo_cadavolta += tempo_cadavolta;

        if(tempo_cadavolta < melhortempo)
        {
            voltaque_melhor_tempocorreu = contador;
            melhortempo=tempo_cadavolta;
        }


    }

    tempomedio_dasvoltas = soma_tempo_cadavolta/tempo_cadavolta;

    printf("\n\n\n\t\t-------------------------TEMPOS DAS VOLTAS-------------------------\n\n");
    printf("\n\n\tMelhor tempo feito pelo piloto ALBERT DA FERRARY em Interlagos: %.1f \n",melhortempo);
    printf("\n\tMelhor tempo occoreu na %d° VOLTA\n",voltaque_melhor_tempocorreu);
    printf("\n\tTempo médio das voltas feitas pelos pilotos: %.2f\n",tempomedio_dasvoltas);
}
