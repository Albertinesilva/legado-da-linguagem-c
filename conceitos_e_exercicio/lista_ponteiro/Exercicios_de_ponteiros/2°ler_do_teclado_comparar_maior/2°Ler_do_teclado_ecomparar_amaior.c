#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0;
    int y=0;

    printf("\nDigite o 1� n�mero: ");
    fflush(stdin);
    scanf("%d",&x);

    printf("\nDigite o 2� n�mero: ");
    fflush(stdin);
    scanf("%d",&y);

    if(&x > &y)
    {
        printf("\nX tem o maior endere�o: %d\n",&x);
    }
    else
    {
        printf("\nY tem o maior endere�o: %d\n",&y);
    }
}
