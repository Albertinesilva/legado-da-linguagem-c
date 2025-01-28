#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main() {
setlocale(LC_ALL,"portuguese");

int num, centena,dezena,unidade,invertido;

printf("Informe um número com 3 digitos: ");
fflush(stdin);
scanf("%i",&num);

centena = num/100;
dezena  = num/10%10;
unidade = num%10;

invertido = (unidade*100) + (dezena*10) + centena;

printf("\nUnidade: %i * 100 = 900\nDezena:  %i * 10 = 80\nCentena: %i (900 + 80) + 4 = 984\n",unidade,dezena,centena);
printf("\nO número invertido é %i: \n",invertido);

}
