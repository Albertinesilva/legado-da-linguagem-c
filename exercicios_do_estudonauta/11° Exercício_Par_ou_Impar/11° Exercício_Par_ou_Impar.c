#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){

int num;

setlocale(LC_ALL,"portuguese");
printf("Digite um número qualquer: ");
scanf("%i",&num);

printf("\nO número %i que você digitou é %s\n",num,(num % 2 == 0) ? "PAR" : "IMPAR");

}
