#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct horario
{
    int horas;
    int minutos;
    int segundos;
}agora;

struct horario teste (struct horario x);

void main()
{
    setlocale(LC_ALL,"portuguese");

    agora.horas = 10;
    agora.minutos = 42;
    agora.segundos = 58;

    struct horario proxima;

    proxima = teste(agora);

    printf("\n%i:%i:%i\n",proxima.horas,
           proxima.minutos,
           proxima.segundos);
}
struct horario teste (struct horario x)
{
    printf("\n\n---------------A FUNÇÃO RECEBEU E PASSOU OS VALORES DA ESTRUTURA------------------\n");
    printf("\n%i:%i:%i\n",x.horas,
           x.minutos,
           x.segundos);

           printf("\n\n--------------A FUNÇÃO RETORNOU A ESTRUTURA COM OS VALORES MODIFICADOS------------\n");
    x.horas = 15;
    x.minutos = 00;
    x.segundos = 59;

    return x;
};
