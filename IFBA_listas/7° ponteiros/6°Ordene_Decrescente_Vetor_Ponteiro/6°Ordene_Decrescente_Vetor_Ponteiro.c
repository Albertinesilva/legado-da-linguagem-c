#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    int vetor[20];

    int *ponteiro1,*ponteiro2;
    ponteiro1=vetor;
    int *finalVetor=vetor+20;

    int aux;

    for(int i=0; i<20; i++)
    {
        vetor[i]=rand()%10+100;
    }

    //Utilizando ponteiro no for: Ponteiro1 vai soma +1 ate que o endereço de memória
    //(finalVetor) seja menor que o endereço de memória do ponteiro1
    for(ponteiro1=vetor; ponteiro1<finalVetor; ponteiro1++)
    {
        //Utilizando ponteiro no for: Ponteiro2 vai soma +1 ate que o endereço de memória
        //(finalVetor) seja menor que o endereço de memória do ponteiro2
        for(ponteiro2=vetor; ponteiro2<finalVetor; ponteiro2++)
        {
            if(*ponteiro1>*ponteiro2)
            {
                aux=*ponteiro1;
                *ponteiro1=*ponteiro2;
                *ponteiro2=aux;

            }
        }


    }
    printf("\n");
    printf("\n\n---------------------------------Decrescentemente---------------------------------\n\n");
    for(int i=0; i<20; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");


    for(ponteiro1=vetor; ponteiro1<vetor+20; ponteiro1++)
    {
        for(ponteiro2=vetor; ponteiro2<vetor+20; ponteiro2++)
        {
            if(*ponteiro1<*ponteiro2)
            {
                aux=*ponteiro1;
                *ponteiro1=*ponteiro2;
                *ponteiro2=aux;
            }
        }
    }
    printf("\n\n---------------------------------Crescentemente--------------------------------\n\n");
    for(int i=0; i<20; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n\n");
}
