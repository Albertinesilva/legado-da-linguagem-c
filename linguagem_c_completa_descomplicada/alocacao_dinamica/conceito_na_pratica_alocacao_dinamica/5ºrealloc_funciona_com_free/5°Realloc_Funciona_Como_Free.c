#include <stdio.h>
#include <stdlib.h>

//Se o tamanho de memória solicitado (num) for igual a zero, a memória apontada por
//*ptr será liberada.
//Nesse exemplo, a função realloc() funciona da mesma maneira que a função free(),
//que veremos na próxima seção.
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
//libera a memória alocada
    p = (int *) realloc(p,0);

    system("pause");
    return 0;
}
