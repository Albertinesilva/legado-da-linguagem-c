#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main (){

setlocale(LC_ALL,"portuguese");

//PODE SER ATRIBUIDO UM DETERMINADO VALOR NA EXPRESSÃO DESSA FORMA ABAIXO:
int a = 5;
a = a + 2;
printf("O valor de a é %i\n ",a);

//PODE SER ATRIBUIDO VALOR TAMBÉM DE OUTRA FORMA, LOGO ABAIXO:
int b = 5;
b += 2;
printf("\nO valor de b é %i\n ",b);

//SERVE PARA TODOS OS TIPOS DE OPERAÇÃO, ex:(a *= 5 , a /= 5, a -= 5).
}
