#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void preencher_vetor(int n,int *ponteiro);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int vetor[5];
    int x=10;
    int *p=vetor;
    int vet[5]= {1,2,3,4,5};

    preencher_vetor(x,p);
    for(int i=0; i<5; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n\n");
    for(int i=0; i<5; i++)
    {
        printf("%d,",p[i]);
    }
    printf("\n\n");
    for(int i=0; i<5; i++)
    {
        printf("%d,",*(p + i));
    }
    for(int i=0; i<5; i++)
    {
        *(p + i)=vet[i];
    }
    printf("\n\n");
    for(int i=0; i<5; i++)
    {
        printf("%d,",vetor[i]);
    }




}
void preencher_vetor(int n,int *ponteiro)
{
    for(int i=0; i<5; i++)
    {
        *ponteiro=n;
        ponteiro++;
    }
}
