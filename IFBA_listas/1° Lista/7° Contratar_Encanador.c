#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

float dias_trabalhados, valor_pago, valor_liquido;

printf("Informe a quantidade de dias trabalhados: ");
fflush(stdin);
scanf("%f",&dias_trabalhados);

valor_pago = dias_trabalhados * 30.00;
valor_liquido = valor_pago - (valor_pago * 8/100);


printf("\nValor liquido do encanado é R$%.2f\n",valor_liquido);
}
