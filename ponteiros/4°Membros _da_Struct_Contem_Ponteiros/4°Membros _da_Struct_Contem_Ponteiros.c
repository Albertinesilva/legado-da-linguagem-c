#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct horario
{
    int *pHora;
    int *pMinuto;
    int *pSegundo;
};

void main()
{
    struct horario hoje;

    int hora = 200;
    int minuto =300;
    int segundo = 400;

    //Passando os endereços das variaveis para o PONTEIRO DE STRUCT:
    hoje.pHora =&hora;
    hoje.pMinuto = &minuto;
    hoje.pSegundo = &segundo;

    printf("Hora - %d\n",*hoje.pHora);
    printf("Minuto - %d\n",*hoje.pMinuto);
    printf("Segundo - %d\n",*hoje.pSegundo);

    *hoje.pSegundo = 1000;

    printf("Segundo alterado: %d\n",*hoje.pSegundo);
}
