#include <stdio.h>
#include <stdlib.h>

//Na linguagem C, os argumentos para uma fun��o s�o sempre passados por valor
//(by value), ou seja, uma c�pia do dado � feita e passada para a fun��o. Esse tipo de
//passagem de par�metro � o padr�o para todos os tipos b�sicos predefinidos (int, char,
//float e double) e estruturas definidas pelo programador (struct).
//Mesmo que o valor de uma vari�vel mude dentro da fun��o, nada acontece com o
//valor de fora da fun��o.

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

/*Sa�da
Antes da funcao: x = 5
Dentro da funcao: x = 6
Depois da funcao: x = 5*/
}
