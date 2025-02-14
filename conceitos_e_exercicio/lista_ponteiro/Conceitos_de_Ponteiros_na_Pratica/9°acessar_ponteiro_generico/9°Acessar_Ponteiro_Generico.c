#include <stdio.h>
#include <stdlib.h>

//Note que o ponteiro gen�rico permite guardar o endere�o de qualquer tipo de
//dado. Essa vantagem tamb�m carrega uma desvantagem: sempre que tivermos de acessar
//o conte�do de um ponteiro gen�rico, ser� necess�rio utilizar o operador de typecast
//sobre ele antes de acessar o seu conte�do.

//Sempre que se trabalhar com um ponteiro gen�rico � preciso convert�-lo para o tipo de
//ponteiro com o qual se deseja trabalhar antes de acessar o seu conte�do.


int main()
{
    void *pp;
    int p2 = 10;
// ponteiro gen�rico recebe o endere�o de um inteiro
    pp = &p2;
//Tenta acessar o conte�do do ponteiro gen�rico
    printf("Conteudo: %d\n",*pp); //ERRO

//converte o ponteiro gen�rico pp para (int *) antes de acessar seu conte�do.
    printf("Conteudo: %d\n",*(int*)pp); //CORRETO
    system("pause");
    return 0;
}
