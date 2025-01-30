#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){

setlocale(LC_ALL,"portuguese");

int num,antecessor,sucessor;

printf("Digite um número: ");
scanf("%d",&num);

antecessor = num - 1;
sucessor   = num + 1;

printf("\nAnalisando o número %d, seu antecessor é %d e seu sucessor é %d.\n ",num,antecessor,sucessor);

}
