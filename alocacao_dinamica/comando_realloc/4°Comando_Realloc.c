#include <stdio.h>
#include <stdlib.h>

void main()
{
    //Função realloc():Serve para mudar o tamanho do vetor no decorrer do codigo.
    /*serve para alocar ou realocar memória durante a execução do programa.
    Ela faz o pedido de memória ao computador e retorna um ponteiro com
    o endereço do início do espaço de memória alocado.

    CUIDADO: Se não houver a memória suficiente para
    alocar a memória requisitada, a função realloc() retona NULL*/

    int *p = (int *) malloc(5* sizeof (int));
    int *p1 = (int *) realloc (p,15* sizeof (int));

    if(p1 != NULL)//Realocação deu certo
    {
        p = p1;
    }
}

