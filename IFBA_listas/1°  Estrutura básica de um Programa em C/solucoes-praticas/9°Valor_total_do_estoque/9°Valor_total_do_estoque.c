#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

void main() {
setlocale(LC_ALL,"portuguese");

float codigo_produto, quant_estoque,valor_unitario,valor_total;

printf("Informe o codigo do produto: ");
fflush(stdin);
scanf("%f",&codigo_produto);

printf("\nInforme a quantidade no estoque do produto: ");
fflush(stdin);
scanf("%f",&quant_estoque);

printf("\nInforme o valor unitario do produto R$:");
fflush(stdin);
scanf("%f",&valor_unitario);

valor_total = quant_estoque * valor_unitario;

printf("\nO valor total em estoque é R$%.2f\n",valor_total);


}
