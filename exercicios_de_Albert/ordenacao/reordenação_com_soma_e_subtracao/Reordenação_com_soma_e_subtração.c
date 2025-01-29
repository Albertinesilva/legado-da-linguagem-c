#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int a=3,b=2;
    int c=1,d=4;

    if(a>b)
    {
        b=a-b;

        a=a-b;

        b=a+b;

    }



    if(a>c)
    {
        c=a-c;

        a=a-c;

        c=a+c;
    }


    if(a>d)
    {
        d=a-d;

        a=a-d;

        d=a+d;
    }


    if(b>a)
    {
        a=b-a;

        b=b-a;

        a=b+a;

    }


    if(b>c)
    {
        c=b-c;

        b=b-c;

        c=b+c;

    }


    if(b>d)
    {
        d=b-d;

        b=b-d;

        d=b+d;

    }


    if(c>a)
    {
        a=c-a;

        c=c-a;

        a=c+a;

    }


    if(c>b)
    {
        b=c-b;

        c=c-b;

        b=c+b;

    }


    if(c>d)
    {
        d=c-d;

        c=c-d;

        d=c+d;

    }


    if(d>a)
    {
        a=d-a;
        d=d-a;
        a=d+a;
    }


    if(d>b)
    {
        b=d-b;
        d=d-b;
        b=d+b;
    }


    if(d>c)
    {
        c=d-c;
        d=d-c;
        c=d+c;
    }

    printf("A: %d, B: %d, C: %d, D: %d\n",a,b,c,d);


}
