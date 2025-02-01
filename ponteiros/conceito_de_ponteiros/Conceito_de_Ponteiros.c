#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>


void main()
{

    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    //Imprime o valor e o endereço de memória de (a).
    int a=10;
    printf("\nValor da variável (a) = %d\n",a);
    //A variável (a) com (&) imprime o endereço de memória.
    printf("Endereço de memória da variável (a) = %d\n",&a);
    printf("\n------------------------------------------------------------------------------\n");

    //O ponteiro aponta para o endereço de memoria da variável (b)
    int b=15;
    int *ponteiro;
    ponteiro=&b;

    //Com o asterico o ponteiro vai acessar o valor da memória da variável (b).
    printf("O PONTEIRO está apontando para o valor da variável (b) = %d\n",*ponteiro);

    //Sem o asterisco(*) imprime o número do endereço de memória da variavel (b).
    printf("O PONTEIRO está apontando para o endereço de memória da variável (b) = %d\n",ponteiro);

    printf("------------------------------------------------------------------------------");

    //O valor de Y não vai alterar.
    int x=10;
    int y=x;
    x=20;

    printf("\nX: %d\nY: %d\n",x,y);

    printf("------------------------------------------------------------------------------");
    //O valor da variavel (Z) vai alterar porque o
    //ponteiroo esta apontando para o endereço de memória da variável (J).
    int z=10;
    int *ponteiroo;
    ponteiroo=&z;

    int j=20;
    *ponteiroo=j;

    printf("\nZ: %d\nJ: %d\n",z,j);



}
