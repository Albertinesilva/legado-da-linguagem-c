#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int primo[10];
    int i=0,num=0,divisivel=0,p=0;
    bool b=true;

    num=10;
    for(i=0; i<10; i++)
    {
        b=true;
        num++;
        while(b)
        {

            for(p=1; p<=num; p++)
            {

                if(num%p==0)
                {
                    divisivel++;
                }
            }

            if(divisivel==2)
            {
                b=false;
                divisivel=0;

            }
            else
            {
                num++;
                divisivel=0;
            }

        }
        primo[i]=num;

    }
    printf("\n\t-----------------------------------NÚMEROS PRIMOS-----------------------------------\n");
    printf("\n\n");
    for(i=0; i<10; i++)
    {
        printf("\t%d,",primo[i]);

    }

    printf("\n\n");
}
