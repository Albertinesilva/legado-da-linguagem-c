#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int primo_vs_divisivel (int prim,int div);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int primo=100,soma=0;
    int divisivel=0;
    bool verdade=true;

    printf("\n");

    while(verdade)
    {
        divisivel=primo_vs_divisivel(primo,divisivel);

        if(divisivel==2)
        {
            printf("%d,",primo);
            soma+=primo;

            primo++;
            divisivel=0;
        }
        else
        {
            divisivel=0;
            primo++;
        }
        if(primo==200)
        {
            verdade=false;
        }
    }
    printf("\n\nResultado da soma entre os números primos: %d\n",soma);
}
int primo_vs_divisivel (int prim,int div)
{
    int i=0;

    for(i=1; i<=prim; i++)
    {
        if(prim%i==0)
        {
            div++;
        }
    }

    return div;
}


