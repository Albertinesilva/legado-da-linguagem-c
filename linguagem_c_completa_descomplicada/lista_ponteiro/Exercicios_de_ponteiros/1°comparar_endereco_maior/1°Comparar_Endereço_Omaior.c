#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0,y=0;

    printf("\nEndereço de X: %d",&x);
    printf("\nEndereço de Y: %d\n",&y);
    if(&x > &y)
    {
        printf("\nO endereço de X é maior: %p\n",&x);
    }
    else
    {
        printf("\nO endereço de Y é maior: %p\n",&y);
    }
}
