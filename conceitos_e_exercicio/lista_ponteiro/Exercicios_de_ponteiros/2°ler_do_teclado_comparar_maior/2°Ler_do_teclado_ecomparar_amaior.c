#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0;
    int y=0;

    printf("\nDigite o 1° número: ");
    fflush(stdin);
    scanf("%d",&x);

    printf("\nDigite o 2° número: ");
    fflush(stdin);
    scanf("%d",&y);

    if(&x > &y)
    {
        printf("\nX tem o maior endereço: %d\n",&x);
    }
    else
    {
        printf("\nY tem o maior endereço: %d\n",&y);
    }
}
