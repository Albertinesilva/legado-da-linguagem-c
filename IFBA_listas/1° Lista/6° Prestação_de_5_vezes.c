#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>


void main(){
setlocale(LC_ALL,"portuguese");

float parcelas, valorcompra;

printf("Informe o valor da compra: R$");
fflush(stdin);
scanf("%f",&valorcompra);

parcelas = valorcompra / 5;

printf("1° Parcela R$%.2f\n2° Parcela R$%.2f\n3° Parcela R$%.2f\n4° Parcela R$%.2f\n5° Parcela R$%.2f\n",parcelas,parcelas,parcelas,parcelas,parcelas);

}
