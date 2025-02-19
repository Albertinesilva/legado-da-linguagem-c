#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Fatorial(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0;
    int Fat=0;

    printf("\nDigite um número para o Fatorial: ");
    fflush(stdin);
    scanf("%d",&x);

    Fat = Fatorial(x);
    printf("\nResultado do fatorial = %d\n",Fat);
}
int Fatorial(int n)
{
    if(n!=0)
    {
        return n*Fatorial(n-1);
    }
    else
    {
        return 1;
    }
}
