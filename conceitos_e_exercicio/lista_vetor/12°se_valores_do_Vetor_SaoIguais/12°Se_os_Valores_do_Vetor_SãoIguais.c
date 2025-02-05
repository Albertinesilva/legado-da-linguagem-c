#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int *A,y=0,i=0;

    A = (int *)malloc(10 * sizeof(int));
    if(A == NULL)
    {
        printf("\nErro: Memória insuficiente!\n");
        system("pause");
        exit(1);
    }
    for(i=0; i<10; i++)
    {
        A[i]=rand()%10+1;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n\n");

    for(int i=0; i<10; i++)
    {
        for(y=i+1; y<10; y++)
        {
            if(A[i] == A[y])
            {
                printf("%d,",A[y]);
            }
        }

    }

}

