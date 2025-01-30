#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){

float velo;
setlocale(LC_ALL,"portuguese");

printf("Qual foi sua velocidade na Br324? ");
scanf("%f",&velo);

if (velo > 80){

    printf("\nVocê passou acima de 80 km, %.1fkm multado\n",velo);
}
printf("Se beber não dirija\n");

}
