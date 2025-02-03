#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"Portuguese");
    int naturais_impares=0,i=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&naturais_impares);
    printf("\n");

    while(i<=naturais_impares)
    {
        if(i%2==1)
        {
            printf("%d,",i);
        }
        i++;
    }
    printf("\n");
}
