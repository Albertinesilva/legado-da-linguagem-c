#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){
setlocale(LC_ALL,"portuguese");

int num;

printf("Digite um número (POSITIVO OU NEGATIVO): ");
fflush(stdin);
scanf("%i",&num);

if(num > 0){
    printf("O inverso de %i é igual a %.4f\n",num,(float)1/num);
}
else{
    printf("O oposto de %i é igual a %i\n",num,-1*num);
}


}
