#include <stdio.h>
#include <stdlib.h>

//A função sizeof() é usada para saber o número de bytes necessários para alocar um
//único elemento de determinado tipo de dado.

//A função sizeof() é usada para se saber o tamanho em bytes de variáveis ou de
//tipos. Ela pode ser usada de duas formas:

//sizeof nome_da_variável
//sizeof (nome_do_tipo)

struct ponto
{
    int x,y;
};
int main()
{
    printf("\nTamanho char: %d\n",sizeof(char));
    printf("Tamanho int: %d\n",sizeof(int));
    printf("Tamanho float: %d\n",sizeof(float));
    printf("Tamanho double: %d\n",sizeof(double));
    printf("Tamanho struct ponto: %d\n",sizeof(struct ponto));
    int x;
    double y;
    printf("Tamanho da variavel x: %d\n",sizeof x);
    printf("Tamanho da variavel y: %d\n\n",sizeof y);

    system("pause");
    return 0;
}
