#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    for(int i=10; i>=0; i--)
    {
        printf("\n  %d",i);
    }
    printf("\n\n  FIM\n");

}
