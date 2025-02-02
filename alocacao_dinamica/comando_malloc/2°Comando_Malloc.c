#include <stdio.h>
#include <stdlib.h>


void main()
{
    /*Se não houver memória suficiente para alocar
    a memória requisitada, a função malloc()retorna NULL*/

    int *p;
    p = (int *)malloc(5*sizeof(int));

    if(p == NULL)
    {
        printf("\nErro: Sem memória!\n");
        exit(1);//Termina o programa
    }

    int i;
    for(i=0; i<5; i++)
    {
        printf("\nDigite p[%d]: ",i);
        scanf("%d",&p[i]);
    }
    printf("\n");
    for(i=0; i<5; i++)
    {
        printf("%d,",p[i]);
    }
    /*A função free(); sempre que alocamos memória é necessário
    liberá-la quando ela não for mais necessária*/
    free(p);
}
