#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main()
{

    int mat[5][5];
    int primo =10, i=0;
    int divisivel=0;
    bool verdadeiro=true;

    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            primo++;

            while(verdadeiro)
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
                    verdadeiro=false;
                    divisivel=0;
                }
                else
                {
                    primo++;
                    divisivel=0;
                }
            }
            mat[l][c]=primo;
            verdadeiro=true;
        }
    }
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            printf(" |%d|",mat[l][c]);
        }
        printf("\n");

    }


}
