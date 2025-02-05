#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    srand (time(NULL));
    int i=0,l=0,aux=0;//n=100;
    int crescente[10];

    for(i=0; i<10; i++)
    {  //crescente[i]=rand()%100+1;
        printf("\nInforme um número inteiro: ");
        scanf("%d",&crescente[i]);
    }
    for(i=0; i<10; i++)
    {
        for(l=i; l<10; l++)
        {
            if(crescente[i]>crescente[l])
            {
                aux=crescente[i];
                crescente[i]=crescente[l];
                crescente[l]=aux;
            }
        }
    }
    printf("\n\n");
    for(i=0; i<10; i++)
    {
        printf("%d,",crescente[i]);
    }
    printf("\n");
}
