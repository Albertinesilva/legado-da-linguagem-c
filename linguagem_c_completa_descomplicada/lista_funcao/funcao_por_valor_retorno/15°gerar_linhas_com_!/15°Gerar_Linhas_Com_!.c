#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Gerar_linhas(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&num);
    printf("\n");

    Gerar_linhas(num);
}
void Gerar_linhas(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            printf("%!");
        }
       printf("\n");
    }
}
