#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    float *vetor;
    int negativos=0,soma_possitivo=0;

    vetor = (float *)malloc(10 * sizeof(float));

    if(vetor == NULL)
    {
        printf("\nErro: Memória Insuficiente!\n");
        system("pause");
        exit(1);
    }
    for(int i=0; i<10; i++)
    {
        vetor[i]=rand()%50+-20;
    }
    for(int i=0; i<10; i++)
    {
        printf("%.0f,",vetor[i]);

        if(vetor[i] < 0)
        {
            negativos++;
        }
        if(vetor[i] > 0)
        {
            soma_possitivo+=vetor[i];
        }

    }
    free(vetor);
    printf("\n\nQuantidade de números Negativos = %d\nSoma dos números possitivos = %d\n",negativos,soma_possitivo);


    return 0;
}
