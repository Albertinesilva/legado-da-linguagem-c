#include <stdio.h>
#include <stdlib.h>

/*Ponteiros permitem percorrer as várias dimensões de um array multidimensional como
se existisse apenas uma dimensão. As dimensões mais à direita mudam mais rápido.

Na primeira forma, o nome do array é utilizado para retornar o endereço onde ele
começa na memória. Isso é muito útil quando queremos construir uma função que
possa percorrer um array independentemente do número de dimensões que ele possua.
Para realizar essa tarefa, utilizamos o operador de endereço (&) para retornar o endereço
da primeira posição do array, como mostra o exemplo da Figura 10.11.*/


int main()
{
    int mat[2][2] = {{1,2},{3,4}};
    int * p = &mat[0][0];
    int i;
    for(i=0; i<4; i++)
        printf("%d\n", *(p+i));

    system("pause");
    return 0;
}

