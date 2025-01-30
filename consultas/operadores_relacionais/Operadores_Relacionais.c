#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//OS VALORES RELACIONAIS RESULTAM SEMPRE UM VALOR LÓGICO
// TRUE = (1) E FALSE = (0):


void main(){

setlocale(LC_ALL,"portuguese");

// O RESULTADO VAI RETORNAR (ZERO) PORQUE 5 E DIFERENTE DE 6:
int a = 5;
int b = 6;
int c = (a==b);

printf("O resultado e %i \n",c);

// O RESULTADO VAI RETORNAR (UM) PORQUE 6 E IGUAL A 6:
int a1 = 6;
int b1 = 6;
int c1 = (a1==b1);

printf("\nO resultado e %i \n",c1);

// O RESULTADO VAI RETORNAR (UM) PORQUE 8 E MENOR QUE 9:
int a2 = 8;
int b2 = 6;
int c2 = (a2 < b + 3);

printf("\nO resultado e %i \n",c2);



}
