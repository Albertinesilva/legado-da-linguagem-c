#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){

char antes,depois,letra;

setlocale(LC_ALL,"portuguese");

printf("Digite uma letra: ");
fflush(stdin);
letra = getchar();

antes = letra - 1;
depois = letra + 1;

printf("\nAntes da letra %c temos a letra %c. Depois temos a letra %c.\n",letra,antes,depois);

//FUNCIONA TAMBÉM DENTRO DA STRING
printf("\nAntes da letra %c temos a letra %c. Depois temos a letra %c.\n",letra,(letra-1),(letra+1));

}
