#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){

setlocale(LC_ALL,"portuguese");

float terca_parte;
int num,dobro;
printf("Digite um número: ");
scanf("%d",&num);

dobro = num * 2;

//(FLOAT)NUM/3; --> ISSO SE CHAMA (COERÇÃO) FORÇANDO A (VARIAVEL: NUM) FAZER A OPERAÇÃO COMO FLOAT:
terca_parte = (float)num / 3;

printf("\nAnalisando o número %d, seu dobro é %d e sua terça parte é %.2f\n",num,dobro,terca_parte);


//TAMBÉM PODE SER FEITO O CALCULO DENTRO DA STRING
printf("\n Analisando o número %d, seu dobro é %d e sua terça parte é %.2f\n",num,(num*2),((float)num/3));
}
