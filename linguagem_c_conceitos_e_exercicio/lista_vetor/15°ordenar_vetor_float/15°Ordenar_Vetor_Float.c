#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    float *vetor,aux=0;;

    vetor = (float *)malloc(10 * sizeof(float));
    if(vetor == NULL)
    {
        printf("\nErro: Memória Insuficiente!\n");
        system("pause");
        exit(1);
    }
    for(int i=0; i<10; i++)
    {
        vetor[i]=rand()%100+1;
    }
    for(int i=0; i<10; i++)
    {
        printf("%.2f,",vetor[i]);
    }

    for(int i=0; i<10; i++)
    {
        for(int y=i+1; y<10; y++)
        {
            if(vetor[i] < vetor[y])
            {
                aux=vetor[i];
                vetor[i]=vetor[y];
                vetor[y]=aux;
            }
        }
    }
    printf("\n\n");
    for(int i=0; i<10; i++)
    {
        printf("%.2f,",vetor[i]);
    }
    printf("\n");
}
