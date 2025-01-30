#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){

setlocale(LC_ALL,"portuguese");

//ESSA OPERAÇÃO É PARA MOSTRAR O VALOR
//DO DESCONTO, DE (-10% DE 1000) QUE VAI SER DE R$:100 REAIS.

printf("***************VALOR DO DESCONTO DE -10%%1000 REAIS***************\n");

float preco = 1000;
float desconto = (preco * 10) / 100;

printf("\nO valor do desconto é %.2f\n ",desconto);


//NESSE CALCULO ABAIXO VAI MOSTRAR O VALOR DO DESCONTO
//QUE EU QUERO DAR PARA PESSOA,(10% DE 1000) VOU COBRAR R$:900 REAIS

printf("\n***************VALOR DO DESCONTO DE 10%% DE 1000 REAIS***************\n");

float preco1 = 1000;
float desconto1 = preco1 - (preco1 * 10)/100;

printf("\nO valor do desconto é %.2f\n ",desconto1);


//AUMENTO DE 10% DE 1000 REAIS

printf("\n**************VALOR DO AUMENTO DE 10%% DE 1000 REAIS***************\n");

float preco2 = 1000;
float desconto2 = preco2 + (preco2 * 10)/100;

printf("\nO valor do aumento é %.2f \n",desconto2);



}
