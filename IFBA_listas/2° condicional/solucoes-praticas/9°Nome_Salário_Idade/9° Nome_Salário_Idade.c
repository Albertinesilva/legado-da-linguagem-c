#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){
setlocale(LC_ALL,"portuguese");

char nome[20];
float salario;
int idade;

printf("Informe o seu nome: ");
fflush(stdin);
gets(nome);

printf("\nInforme a sua idade: ");
scanf("%i",&idade);

printf("\nInforme o seu salário: R$");
scanf("%f",&salario);


if(idade >= 18 && salario > 1000){

    printf("\n%s pode se cadastrar\n",nome);
}
    else{
        printf("\nVocê não preencheu os requisitos\n");
    }
}
