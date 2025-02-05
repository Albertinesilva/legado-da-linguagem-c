#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int soma_divisores(int x);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0, i=0;

    for(i=0; i<5; i++)
    {
        printf("\n\n\tInforme o %d° número positivo para a soma: ",i+1);
        scanf("%d",&num);

        soma_divisores(num);
    }

}
int soma_divisores(int x)
{
    int soma=0;
    int i=1;

    if(x<0)
    {
        printf("\n\tNÚMERO INFORMADO É NEGATIVO!\n");
    }
printf("\n\t-------------------DIVISORES DE %d--------------------\n",x);
    for(i=1; i<x; i++)
    {
        if(x%i==0)
        {
            soma+=i;
            printf("\t%d,",i);
        }
    }
    printf("\n\n\tO RESULTADO DA SOMA ENTRE DIVISORES É: %d\n",soma);
    printf("\n\t-----------------------------------------------------\n");

    return soma;

}
