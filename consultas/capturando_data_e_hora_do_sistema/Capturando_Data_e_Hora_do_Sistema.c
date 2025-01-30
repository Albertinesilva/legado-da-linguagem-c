#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
// OBRIGATORIAMENTE TEM QUE FAZER A CARGA DA BIBLIOTECA (<TIME.H>)

void main()
{
    setlocale(LC_ALL, "portuguese");

    // TIPO PRIMITIVO: (time_t)
    // VARIAVEL (t)
    time_t t;

    // FUN�AO INTERNA: (time)
    // A FUN��O (time) ESTA RECEBENDO O ENDERE�O DE (&t) PARA PEGAR DATA E HORA DO SISTEMA
    time(&t);

    // COMANDO DE ESTRUTURA: (estruct)
    //(tm): NOME DA ESTRUTURA
    //(*data): PONTEIRO PARA (tm)
    struct tm *data;

    //(localtime): PEGA DATA, HORA, M�S, VARIOS PARAMETROS PARA PODER MOSTRAR NA TELA
    data = localtime(&t);

    //(dia): VARIAVEL
    //(data->tm_mday): PONTEIRO APONTANDO PARA O DIA ATUAL
    int dia = data->tm_mday;

    //(mes): VARIAVEL
    //(data->tm_mon: PONTEIRO APONTANDO PARA O M�S ATUAL
    int mes = data->tm_mon + 1;

    //(ano): VARIAVEL
    //(data->tm_year): PONTEIRO APONTANDO PARA O ANO ATUAL
    int ano = data->tm_year + 1900;

    //(dia_semana): VARIAVEL
    //(data->tm_wday): PONTEIRO APONTANDO PARA O DIA DA SEMANA ATUAL
    int dia_semana = data->tm_wday;

    //(dia_ano): VARIAVEL
    //(data->tm_yday): PONTEIRO APONTA PARA O DIA DO ANO ATUAL
    int dia_ano = data->tm_yday;

    //(hora): VARIAVEL
    //(data->tm_hour): PONTEIRO APONTA PARA O HOR�RIO ATUAL
    int hora = data->tm_hour;

    //(minutos): VARIAVEL
    //(data->tm_min): PONTEIRO APONTA PARA OS MINUTOS ATUAL
    int minutos = data->tm_min;

    //(segundos): VARIAVEL
    //(data->tm_sec): PONTEIRO APONTA PARA OS SEGUNDOS ATUAL
    int segundos = data->tm_sec;

    printf("Estamos no dia %i, no mes %i e no ano de %i\n", dia, mes, ano);
    printf("\nHoje � %i, dia %i do ano! � o hor�rio atual � %i:%i:%i\n", dia_semana, dia_ano, hora, minutos, segundos);
}
