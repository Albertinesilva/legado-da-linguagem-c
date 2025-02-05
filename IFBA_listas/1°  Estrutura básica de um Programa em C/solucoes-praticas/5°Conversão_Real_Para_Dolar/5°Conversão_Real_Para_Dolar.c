#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>


void main(){
setlocale(LC_ALL,"portuguese");

float quantidade_dolar,cotacao_dolar;

printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ CONVERSÃO EM REAL $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

printf("\nInforme a cotação do dolar R$ ");
fflush(stdin);
scanf("%f",&cotacao_dolar);

printf("\nInforme a quantidade de dolar disponivel R$ ");
fflush(stdin);
scanf("%f",&quantidade_dolar);

float conversaoreal = quantidade_dolar * cotacao_dolar;

printf("\nO valor da conversão: DOLAR PARA REAL É R$ %.2f:\n",conversaoreal);
printf("\nTa ruim Jackson?\nClaro que nao!\nEntao fique na Nigeria$$$$! kkkkkkkk\n");

}
