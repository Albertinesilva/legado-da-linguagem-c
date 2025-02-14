#include <stdio.h>
#include <stdlib.h>

//Note que o ponteiro genérico permite guardar o endereço de qualquer tipo de
//dado. Essa vantagem também carrega uma desvantagem: sempre que tivermos de acessar
//o conteúdo de um ponteiro genérico, será necessário utilizar o operador de typecast
//sobre ele antes de acessar o seu conteúdo.

//Sempre que se trabalhar com um ponteiro genérico é preciso convertê-lo para o tipo de
//ponteiro com o qual se deseja trabalhar antes de acessar o seu conteúdo.


int main()
{
    void *pp;
    int p2 = 10;
// ponteiro genérico recebe o endereço de um inteiro
    pp = &p2;
//Tenta acessar o conteúdo do ponteiro genérico
    printf("Conteudo: %d\n",*pp); //ERRO

//converte o ponteiro genérico pp para (int *) antes de acessar seu conteúdo.
    printf("Conteudo: %d\n",*(int*)pp); //CORRETO
    system("pause");
    return 0;
}
