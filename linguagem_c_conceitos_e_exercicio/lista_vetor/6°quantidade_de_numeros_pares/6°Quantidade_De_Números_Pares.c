#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int *vetor;
    int pares=0;

    vetor=(int *)malloc(10*sizeof(int));

    if(vetor == NULL)
    {
        printf("\nErro: Memória insuficiente!\n");
        system("pause");
        exit(1);
    }
    for(int i=0; i<10; i++)
    {
        vetor[i]=rand()%10+100;
    }
    printf("\n");
    for(int i=0; i<10; i++)
    {
        printf("%d,",vetor[i]);

        if(vetor[i]%2==0)
        {
            pares++;
        }
    }
    free(vetor);
    printf("\n\nQuantidade de números pares no vetor = %d\n",pares);


    return 0;
}
