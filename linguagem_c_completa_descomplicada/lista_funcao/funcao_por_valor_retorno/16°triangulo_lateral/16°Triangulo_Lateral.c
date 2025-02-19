#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void triangulo_lateral(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&num);

    triangulo_lateral(num);

}
void triangulo_lateral(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("*");
        for(int j=0; j<i; j++)
        {
            printf("*");

        }
        printf("\n");
    }
    for(int i=1; i<n; i++)
    {
    printf("*");
        for(int j=2; j<n+1-i; j++)
        {
           printf("*");

        }
        printf("\n");
    }
}
