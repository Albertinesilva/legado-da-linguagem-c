#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num,x;

    x=0;
    num=100;

    while(x!=num)
    {
        x+=1;

        printf("\nNúmeros entre 1 e 100: %d\n",x);


    }



}
