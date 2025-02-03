#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int n=-1;

    while(n<0)
    {
        printf("\nInforme um número maior que zero: ");
        fflush(stdin);
        scanf("%d",&n);
    }
    int *vetor;

    vetor=(int *)malloc(n * sizeof(int));
    if(vetor==NULL)
    {
        printf("\nErro: Memória Insuficiente!");
        system("pause");
        exit(1);
    }

    for(int i=0; i<n; i++)
    {
        vetor[i]=0;
        while(vetor[i]<=1)
        {
            printf("\nInforme o %d° elemento do vetor: ",i+1);
            fflush(stdin);
            scanf("%d",&vetor[i]);
        }

    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");
}
