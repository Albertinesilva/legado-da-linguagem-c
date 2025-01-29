#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


void main ()
{
    setlocale(LC_ALL,"portuguese");

    int a=0,b=0,c=0;

    printf("\nInforme 3 números: ");
    scanf("%d,",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    printf("\na = %d\n",a);
    printf("b = %d\n",b);
    printf("c = %d\n",c);


    if(a > b && a > c)
    {
        printf("\n a é o maior número: %d\n",a);
    }
    else
    {
        if(b > a && b > c)
        {
            printf("\nb é o maior número: %d\n",b);
        }
        else
        {
            printf("\nc é o maior número: %d\n",c);
        }
    }
}
