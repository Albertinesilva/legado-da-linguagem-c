#include <stdio.h>
#include <stdlib.h>

//Cada posi��o de um array de ponteiros pode armazenar o endere�o de uma vari�vel ou
//o endere�o da posi��o inicial de um outro array.

int main()
{
    int *pvet[2];
    int x = 10, y[2] = {20,30};
    pvet[0] = &x;
    pvet[1] = y;
//imprime os endere�os das variaveis
    printf("Endereco pvet[0]: %p\n",pvet[0]);
    printf("Endereco pvet[1]: %p\n",pvet[1]);
//imprime o conte�do de uma vari�vel
    printf("Conteudo em pvet[0]: %d\n",*pvet[0]);
//imprime uma posi��o do vetor
    printf("Conteudo pvet[1][1]: %d\n",pvet[1][1]);

   /* A linguagem C tamb�m permite que declaremos arrays de ponteiros como fazemos
com qualquer outro tipo de dado. A declara��o de um array de ponteiros segue esta
forma geral:
tipo_dado *nome_array[tamanho];

Esse comando define um array de nome nome_array contendo tamanho elementos
adjacentes na mem�ria. Cada elemento do array � do tipo tipo_dado*, ou seja, � um
ponteiro para tipo_dado. Assim, a declara��o de um array de ponteiros para inteiros de
tamanho 10 seria:
int *p[10];

Quanto ao seu uso, n�o existem diferen�as entre um array de ponteiros e um ponteiro.
Basta lembrar que um array � sempre indexado. Assim, para atribuir o endere�o
de uma vari�vel x a uma posi��o do array de ponteiros, escrevemos:
p[indice] = &x;

E para retornar o conte�do guardado nessa posi��o de mem�ria:
*p[�ndice]*/

    system("pause");
    return 0;
}
