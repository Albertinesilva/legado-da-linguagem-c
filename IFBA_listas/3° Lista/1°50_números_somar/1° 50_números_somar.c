#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int num,x,soma;
    char continuar;
    bool b = true;
    x=0;
    soma=0;

    do
    {

        do
        {
            x += 1;
            printf("\nInforme %d° número para a SOMA: ",x);
            scanf("%d",&num);

            soma = soma + num;

        }
        while(x!=5);

        printf("\nTotal da SOMA %d\n",soma);

        if(x==5)
        {
            x=0;
            num=0;
            soma=0;
            printf("\nDeseja continuar a SOMA? SIM[S], NÃO[N]  ");
            fflush(stdin);
            continuar = getchar();
        }
        if(continuar == 'n')
        {
            b = false;
            printf("\nA soma terminou.\nObrigado!\n");
        }
    }
    while(b);


}
