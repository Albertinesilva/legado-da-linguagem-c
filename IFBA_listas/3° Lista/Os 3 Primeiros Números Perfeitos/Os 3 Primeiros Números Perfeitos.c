#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int numero=1,soma=0,divisivel=0,perfeitos=0;
    bool b=true;

    printf("\n\t*************************OS TRÊS PRIMEIROS NÚMEROS PERFEITOS*************************\n\n");


    while(b)
    {

        divisivel++;
        if(numero%divisivel==0)
        {
            soma=soma+divisivel;
        }

        if(numero==divisivel)
        {  soma=0;
            divisivel=0;
            numero++;
        }

        if(soma==numero && soma != 1 && soma != 24)
        {
            soma=0;
            divisivel=0;
            printf("\n\t%d\n",numero);
            perfeitos++;
            numero++;
        }

        if(perfeitos==3)
        {
            b = false;
        }
    }
}
