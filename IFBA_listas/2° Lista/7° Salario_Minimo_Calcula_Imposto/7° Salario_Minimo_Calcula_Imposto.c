#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main() {
setlocale(LC_ALL,"portuguese");

float salario_minimo, salario, imposto;

printf("Informe o valor do salário mínimo atual: R$ ");
scanf("%f",&salario_minimo);

printf("\nInforme o seu salário: R$ ");
scanf("%f",&salario);

float quant_salario = salario / salario_minimo;

printf("\nEu ganho %.0f salários mínimos\n",quant_salario);
printf("\n\n--------------------CASO GANHE MAIS DE 3 SALÁRIOS, DEVE PAGAR IMPOSTO DE RENDA COM ALÍQUOTA DE %%15--------------------\n\n");

if(quant_salario > 3){
        imposto = salario - (salario * 15 /100);
printf("\nEu ganho %.0f salários mínimos. Tenho que pagar imposto de renda!\nSALÁRIO COM DESCONTO: R$%.2f \n",quant_salario,imposto);

}
    else{
        printf("\nEu ganho %.0f salários minimos, não há imposto a ser pago!\n",quant_salario);
    }
}
