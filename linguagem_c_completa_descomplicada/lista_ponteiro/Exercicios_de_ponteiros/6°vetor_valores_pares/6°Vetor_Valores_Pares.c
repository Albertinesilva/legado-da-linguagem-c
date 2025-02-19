#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int vetor[5];

    for(int i=0; i<5; i++)
    {
        printf("\n\nDigite o %d° número: ",i+1);
        fflush(stdin);
        scanf("%d",&vetor[i]);

        if(vetor[i]%2==0)
        {
            printf("%d é Par, Endereço de memória = %d",vetor[i],&vetor[i]);
        }
    }
}
