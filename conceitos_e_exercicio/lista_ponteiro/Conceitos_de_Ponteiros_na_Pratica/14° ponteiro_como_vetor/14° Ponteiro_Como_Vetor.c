#include <stdio.h>
#include <stdlib.h>

//Cada posição de um array de ponteiros pode armazenar o endereço de uma variável ou
//o endereço da posição inicial de um outro array.

int main()
{
    int *pvet[2];
    int x = 10, y[2] = {20,30};
    pvet[0] = &x;
    pvet[1] = y;
//imprime os endereços das variaveis
    printf("Endereco pvet[0]: %p\n",pvet[0]);
    printf("Endereco pvet[1]: %p\n",pvet[1]);
//imprime o conteúdo de uma variável
    printf("Conteudo em pvet[0]: %d\n",*pvet[0]);
//imprime uma posição do vetor
    printf("Conteudo pvet[1][1]: %d\n",pvet[1][1]);

   /* A linguagem C também permite que declaremos arrays de ponteiros como fazemos
com qualquer outro tipo de dado. A declaração de um array de ponteiros segue esta
forma geral:
tipo_dado *nome_array[tamanho];

Esse comando define um array de nome nome_array contendo tamanho elementos
adjacentes na memória. Cada elemento do array é do tipo tipo_dado*, ou seja, é um
ponteiro para tipo_dado. Assim, a declaração de um array de ponteiros para inteiros de
tamanho 10 seria:
int *p[10];

Quanto ao seu uso, não existem diferenças entre um array de ponteiros e um ponteiro.
Basta lembrar que um array é sempre indexado. Assim, para atribuir o endereço
de uma variável x a uma posição do array de ponteiros, escrevemos:
p[indice] = &x;

E para retornar o conteúdo guardado nessa posição de memória:
*p[índice]*/

    system("pause");
    return 0;
}
