#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main (){
setlocale(LC_ALL,"portuguese");

int n1,n2;
int conjucao,disjuncao,exclusiva;

printf("Digite o primeiro valor: ");
scanf("%i",&n1);
printf("Digite o segundo valor: ");
scanf("%i",&n2);

printf("\n---------------OPERAÇÕES BITWISE---------------\n");
conjucao  = n1 & n2;
disjuncao  = n1 | n2;
exclusiva = n1 ^ n2;

printf("Calculando %i & %i é igual a %i: ",n1,n2,conjucao);
printf("\nCalculando %i | %i é igual a %i:\n",n1,n2,disjuncao);
printf("Calculando %i ^ %i é igual a %i:\n ",n1,n2,exclusiva);



}
