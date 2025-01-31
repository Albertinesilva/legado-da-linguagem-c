#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int vetor(int vet[], int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int vet [10];
    int i=0;

    for(i=0; i<10; i++)
    {
        vet[i]=rand()%50+10;
    }
    printf("\n\t");

    for(i=0; i<10; i++)
    {
        printf("%d,",vet[i]);
    }
    printf("\n");

    vetor(vet,10);
}
int vetor(int vet[], int n)
{
    int i=0,j=0,aux=0;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(vet[i]<vet[j])
            {
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
    printf("\n\t");

    for(i=0; i<10; i++)
    {
        printf("%d,",vet[i]);
    }
    printf("\n");

}
