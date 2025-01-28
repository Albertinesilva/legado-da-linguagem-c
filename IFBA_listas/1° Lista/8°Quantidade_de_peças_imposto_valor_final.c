#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


void main() {
setlocale(LC_ALL,"portuguese");

float codigo_peca, valor_peca, porcentagem, valor_final, quantidade_peca;

printf("Informe o codigo da peça: ");
fflush(stdin);
scanf("%f",&codigo_peca);

printf("Informe a quantidade de peças: ");
fflush(stdin);
scanf("%f",&quantidade_peca);

printf("informe o valor da peça R$:");
fflush(stdin);
scanf("%f",&valor_peca);

printf("Informe o valor do imposto R$:");
fflush(stdin);
scanf("%f",&porcentagem);



float imposto_peca = (valor_peca * porcentagem)/100;
float peca_com_imposto = imposto_peca + valor_peca;

valor_final =  (quantidade_peca * peca_com_imposto);

printf("\nValor do imposto %.0f%%",imposto_peca);
printf("\nValor final da compra R$:%.1f\n",valor_final);


}
