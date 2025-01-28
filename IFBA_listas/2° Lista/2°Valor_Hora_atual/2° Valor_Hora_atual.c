#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

time_t t;
time(&t);
struct tm*data;
data = localtime(&t);
int hora = data->tm_hour;
int min  = data->tm_min;
int seg  = data->tm_sec;

int hora_atual;

printf("\t\t-------------------------HORÁRIO ATUAL %i:%i : %i-------------------------\n",hora,min,seg);

printf("\nInforme a hora atual: ");
scanf("%i",&hora_atual);

int minutos = hora_atual * 60;

if (minutos > 720){
    printf("\nO horario atual é %i, já passou do meio dia. Minutos registrados até o momento: %i\n",hora_atual,minutos);

}else{

printf("\nMinutos registrados: %i\n",minutos);
}

}
