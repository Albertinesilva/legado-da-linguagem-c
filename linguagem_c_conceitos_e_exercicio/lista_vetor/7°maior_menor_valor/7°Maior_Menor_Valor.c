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
    int maior=0,menor=0;

    vetor = (int *)malloc(10 * sizeof(int));

    if(vetor == NULL)
    {
        printf("\nErro: Memória insuficiente!");
        system("pause");
        exit(1);
    }
    for(int i=0; i<10; i++)
    {
        vetor[i]=rand()%10+100;
        menor=vetor[i];
    }
    for(int i=0; i<10; i++)
    {
        printf("%d,",vetor[i]);
        if(vetor[i] > maior)
        {
            maior=vetor[i];
        }
        else
        {
            if(vetor[i] < menor)
            {
                menor=vetor[i];
            }
        }
    }
    free(vetor);
    printf("\n\nMaior Elemento = %d\nMenor Elemento = %d\nSoma dos dois Elementos %d\n",maior,menor,maior+menor);

 return 0;
}
