#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int mat_primo[5][5];
    int l=0, c=0, i=0;
    int divisivel=0, primo=10;
    bool b = true;


    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            b=true;
            primo++;

            while(b)
            {

                for(i=1; i<=primo; i++)
                {
                    if(primo%i==0)
                    {
                        divisivel++;
                    }
                }

                if(divisivel==2)
                {
                    divisivel=0;
                    b=false;
                }
                else
                {
                    primo++;
                    divisivel=0;
                }
            }
            mat_primo[l][c]=primo;

        }
    }

    printf("\n\n\t------------------------------MATRIZ COM NÚMEROS PRIMOS-----------------------------\n\n");
    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            printf("|%d|",mat_primo[l][c]);
        }
        printf("\n");
    }
    printf("\n\n\t------------------------------------------------------------------------------------\n\n");
}
