#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Horario_Convertido_EmSegundos(int h,int m,int s);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int hora=0,minutos=0,segundos=0;

    printf("\nInforme a Hora: ");
    fflush(stdin);
    scanf("%d",&hora);

    printf("\nInforme os Minutos: ");
    fflush(stdin);
    scanf("%d",&minutos);

    printf("\nInforme os segundos: ");
    fflush(stdin);
    scanf("%d",&segundos);

    int convertido = Horario_Convertido_EmSegundos(hora,minutos,segundos);
    printf("\nHorário convertido em segundos: %d\n",convertido);
}
int Horario_Convertido_EmSegundos(int h,int m,int s)
{
    int segundos = (h * 3600) + (s * m) ;

    return segundos;
}
