#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main (){

setlocale(LC_ALL,"portuguese");

char nome[40];
int idade;
float peso;

printf("Qual o seu nome? ");
fflush(stdin);
gets(nome);

printf("Quantos anos você tem? ");
scanf("%i",&idade);

printf("Qual é o seu peso? ");
scanf("%f",&peso);

printf("\n-------<<<<PROCESSANDO>>>>--------\n");

printf("Muito prazer, %s. Você tem %i anos e pesa %.2fKg correto?\n ",nome,idade,peso );
printf("\nFIM");
}
