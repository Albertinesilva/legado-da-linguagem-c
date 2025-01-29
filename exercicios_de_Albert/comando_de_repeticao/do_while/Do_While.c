#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int divisivel,x,primo;
    bool b = true;
    char continuar;


    do
    {
        printf("\nInforme um número para saber se é PRIMO: ");
        scanf("%d",&primo);
        x = 0;
        divisivel = 0;
        do
        {
            x += 1;
            if(primo%x==0)
            {
                divisivel += 1;
            }
        }
        while(x != primo);

        if(divisivel==2)
        {
            printf("\nO número %d é PRIMO\n",primo);
            printf("\nDeseja continuar? SIM[S], NÃO[N] ");
            fflush(stdin);
            continuar = getchar();

        }
        else
        {
            printf("\nO número %d não e PRIMO\n",primo);
            printf("\nDeseja continuar? SIM[S], NÃO[N] ");
            fflush(stdin);
            continuar = getchar();
        }

        if(continuar=='n')
        {
            b=false;
            printf("\nA consulta terminou.\nObrigado!!\n");
        }

    }
    while(b);




}

