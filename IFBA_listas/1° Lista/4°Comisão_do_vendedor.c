#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void main(){
setlocale(LC_ALL,"portuguese");


float salario,vendas,salario_final;

printf("Informe o seu salário. R$");
fflush(stdin);
scanf("%f",&salario);

printf("Informe o total de vendas efetuadas no mês: ");
fflush(stdin);
scanf("%f",&vendas);

float comissao = vendas + (vendas * 15)/100;
salario_final =  salario + comissao;

printf("\nComissão: R$%.2f\n",comissao);
printf("O salário final do vendedor é: R$%.2f\n",salario_final);


}
