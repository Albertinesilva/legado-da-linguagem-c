#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct horario{

    int hora;
    int minuto;
    int segundo;
};

void main(){

    setlocale(LC_ALL,"Portuguese");

    //O ponteiro aponta para a (STRUCT AGORA), podendo manipular a struct com operações matematicas
    struct horario agora,*ponteiro;
    ponteiro=&agora;

    ponteiro->hora=20;
    ponteiro->minuto=80;
    ponteiro->segundo=50;

    int somatorio=100;

    //struct horario do tipo Antes: Recebe a soma utilizando ponteiros.
    struct horario antes;

    antes.hora = somatorio + ponteiro->segundo;
    antes.minuto = agora.hora + ponteiro->minuto;
    antes.segundo = ponteiro->minuto + ponteiro->segundo;

    printf("%i:%i:%i",antes.hora,antes.minuto,antes.segundo);

}
