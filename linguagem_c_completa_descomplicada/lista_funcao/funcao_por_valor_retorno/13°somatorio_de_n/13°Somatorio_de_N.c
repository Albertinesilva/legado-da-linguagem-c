#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somatorio(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&num);

    int soma = somatorio(num);
    printf("\nResultado da soma: %d\n",soma);
}
int somatorio(int n)
{
    int soma=0;
    for(int i=1; i<n; i++)
    {
        soma+=i;
    }
    return soma;
}
