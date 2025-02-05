#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int n=0;

    printf("\nQuantos elementos o vetor vai ter? ");
    fflush(stdin);
    scanf("%d",&n);

    int *vetor;

    vetor=(int *)malloc(n * sizeof(int));
    if(vetor==NULL)
    {
        printf("\nErro: Memória insuficiente!");
        system("pause");
        exit(1);
    }
    for(int i=0; i<n; i++)
    {
        printf("\nInforme o %d° elemento: ",i+1);
        fflush(stdin);
        scanf("%d",&vetor[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");

}
