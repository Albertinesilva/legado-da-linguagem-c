#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int multiplos_de_3=0;

    printf("\n");
    for(int i=0; i<=5; i++)
    {
        printf("%d,",multiplos_de_3+=3);
    }
    printf("\n");
}
