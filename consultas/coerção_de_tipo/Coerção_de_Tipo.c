#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main (){

setlocale(LC_ALL,"portuguese");

// COERÇÃO DE TIPO OU TYPECAST: FORÇA UM DETERMINADO
//TIPO MESMO QUE ESSA VARIAVEL NÃO SEJA DESSE TIPO.


//EXEMPLO:
int a = 5;
int y = 2;

float z = (float) a / y;
printf("O resultado e %.1f: \n",z);



// 2° EXEMPLO:

int n;
float t;
printf("\nDigite um número: ");
scanf("%d",&n);

t = (float) n / 3;
printf("\nA terça parte de %d e igual a %.2f\n ",n,t);


//3° EXEMPLO COM CARACTERE: TRANSFORMAR O NÚMERO iNTEIRO EM CARACTERE:
printf("\n--------------------Transformar um número inteiro em caractere--------------------\n");
int x = 65;
//VAI IMPRIMIR A LETRA (A) PORQUE O CODIGO DA LETRA (A) E 65:
printf("\nEu tenho %c ", (char)x);
}
