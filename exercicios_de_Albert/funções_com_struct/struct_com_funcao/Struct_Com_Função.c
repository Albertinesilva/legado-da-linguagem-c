#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct horario
{
    int hora;
    int minuto;
    int segundos;
} listahorarios[5];


void main()
{
    setlocale(LC_ALL,"portuguese");

    void receberhorarios(struct horario lista[5]);

    void printhorario(struct horario lista[5]);

    receberhorarios(listahorarios);
    printf("\n");
    printhorario(listahorarios);
}

void receberhorarios(struct horario lista[5])
{
    int i=0;

    for(i=1; i<=5; i++)
    {
        printf("\n\n-------------------------INFORME O %d° HORARIO (hh:mm:ss)------------------------- ",i);
        printf("\nDigite a HORA: ");
        scanf("%d",&lista[i].hora);
        printf("\nDigite os MINUTOS: ");
        scanf("%d",&lista[i].minuto);
        printf("\nDigite os SEGUNDOS: ");
        scanf("%d",&lista[i].segundos);
        printf("---------------------------------------------------------------------------------\n");
    }
}

void printhorario(struct horario lista[5])
{
    int i=0;

    for(i=1; i<=5; i++)
    {
        printf("O %d° horario é = %d:%d:%d\n",i,
               lista[i].hora,
               lista[i].minuto,
               lista[i].segundos);
    }
}
