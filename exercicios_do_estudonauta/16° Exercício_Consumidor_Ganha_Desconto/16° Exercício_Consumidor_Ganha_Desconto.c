#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

float valor_compra,desconto,valor_pago;

printf("Qual foi o valor total das compras? R$");
fflush(stdin);
scanf("%f",&valor_compra);

    desconto = (valor_compra*10)/100;
    valor_pago = valor_compra - desconto;


    printf("----------------------------------\n");
    printf("Você comprou R$%.2f na nossa loja.\n", valor_compra);

if (valor_compra >= 500){

    printf("===============ATENÇAO===============\n");
    printf("Por fazer mais de R$500 em compras, você vai receber R$%.2f de desconto\n",desconto);
    printf("O valor total a ser pago será de R$%.2f!\n",valor_pago);
}
    printf("Volte sempre!\n");
    printf("-----------------------------------\n");

}
