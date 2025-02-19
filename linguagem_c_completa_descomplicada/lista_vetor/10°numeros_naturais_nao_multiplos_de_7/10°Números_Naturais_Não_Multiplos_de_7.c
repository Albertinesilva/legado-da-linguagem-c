#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int *vetor;

    vetor = (int *)malloc(100 * sizeof(int));

    if(vetor == NULL)
    {
        printf("\nErro: Memória insuficiente!");
        system("pause");
        exit(1);
    }
    for(int i=0; i<=100; i++)
    {
        vetor[i]=i;
    }
    for(int i=0; i<=100; i++)
    {
        if(vetor[i]%7==1)
        {
            printf("%d,",vetor[i]);
        }

    }

}
