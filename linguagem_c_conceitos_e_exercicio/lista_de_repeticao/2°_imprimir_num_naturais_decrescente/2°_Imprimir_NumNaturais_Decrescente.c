#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"Portuguese");

    int numero=0,i=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&numero);
    printf("\n");

    i=numero;
    do
    {
     printf("%d,",i);
     i--;
    }
    while(i!=-1);
    printf("\n");
}
