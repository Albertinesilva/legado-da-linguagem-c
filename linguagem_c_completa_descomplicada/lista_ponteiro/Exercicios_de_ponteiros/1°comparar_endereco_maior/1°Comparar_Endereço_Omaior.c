#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0,y=0;

    printf("\nEndere�o de X: %d",&x);
    printf("\nEndere�o de Y: %d\n",&y);
    if(&x > &y)
    {
        printf("\nO endere�o de X � maior: %p\n",&x);
    }
    else
    {
        printf("\nO endere�o de Y � maior: %p\n",&y);
    }
}
