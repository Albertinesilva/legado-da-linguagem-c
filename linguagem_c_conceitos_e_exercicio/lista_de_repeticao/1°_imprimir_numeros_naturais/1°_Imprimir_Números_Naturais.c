#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int naturais=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&naturais);
    printf("\n");

    for(int i=0; i<=naturais; i++)
    {
        printf("%d,",i);
    }
    printf("\n");

}
