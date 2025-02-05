#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

int num,hora,minutos,segundos;

printf("Informe a quantidade de segundos: ");
fflush(stdin);
scanf("%i",&num);

hora     =  num/3660;
minutos  = (num%3600)/60;
segundos = (num%3600)%60;

printf("\nOs segundos convertidos é: %i Hora: %i minutos = %i segundos\n",hora,minutos,segundos);
}
