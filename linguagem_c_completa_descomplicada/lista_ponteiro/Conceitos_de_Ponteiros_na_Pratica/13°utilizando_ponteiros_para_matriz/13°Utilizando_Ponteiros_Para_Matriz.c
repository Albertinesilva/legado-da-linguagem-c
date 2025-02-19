#include <stdio.h>
#include <stdlib.h>

/*Ponteiros permitem percorrer as v�rias dimens�es de um array multidimensional como
se existisse apenas uma dimens�o. As dimens�es mais � direita mudam mais r�pido.

Na primeira forma, o nome do array � utilizado para retornar o endere�o onde ele
come�a na mem�ria. Isso � muito �til quando queremos construir uma fun��o que
possa percorrer um array independentemente do n�mero de dimens�es que ele possua.
Para realizar essa tarefa, utilizamos o operador de endere�o (&) para retornar o endere�o
da primeira posi��o do array, como mostra o exemplo da Figura 10.11.*/


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

