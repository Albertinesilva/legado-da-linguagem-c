#include <stdio.h>
#include <stdlib.h>

//Na linguagem C, os argumentos para uma função são sempre passados por valor
//(by value), ou seja, uma cópia do dado é feita e passada para a função. Esse tipo de
//passagem de parâmetro é o padrão para todos os tipos básicos predefinidos (int, char,
//float e double) e estruturas definidas pelo programador (struct).
//Mesmo que o valor de uma variável mude dentro da função, nada acontece com o
//valor de fora da função.

void soma_mais_um(int n){
n = n + 1;
printf("Dentro da funcao: x = %d\n",n);
}
int main(){
int x = 5;

printf("Antes da funcao: x = %d\n",x);
soma_mais_um(x);

printf("Depois da funcao: x = %d\n",x);

system("pause");
return 0;

/*Saída
Antes da funcao: x = 5
Dentro da funcao: x = 6
Depois da funcao: x = 5*/
}
