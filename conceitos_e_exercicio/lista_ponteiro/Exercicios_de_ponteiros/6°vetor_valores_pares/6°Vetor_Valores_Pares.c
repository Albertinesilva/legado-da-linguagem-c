#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int vetor[5];

    for(int i=0; i<5; i++)
    {
        printf("\n\nDigite o %d� n�mero: ",i+1);
        fflush(stdin);
        scanf("%d",&vetor[i]);

        if(vetor[i]%2==0)
        {
            printf("%d � Par, Endere�o de mem�ria = %d",vetor[i],&vetor[i]);
        }
    }
}
