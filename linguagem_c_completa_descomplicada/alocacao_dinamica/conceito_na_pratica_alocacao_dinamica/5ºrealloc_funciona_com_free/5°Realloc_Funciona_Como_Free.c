#include <stdio.h>
#include <stdlib.h>

//Se o tamanho de mem�ria solicitado (num) for igual a zero, a mem�ria apontada por
//*ptr ser� liberada.
//Nesse exemplo, a fun��o realloc() funciona da mesma maneira que a fun��o free(),
//que veremos na pr�xima se��o.
int main()
{
    int *p;
    p = (int *) malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = i+1;
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d,",p[i]);
    }
//libera a mem�ria alocada
    p = (int *) realloc(p,0);

    system("pause");
    return 0;
}
