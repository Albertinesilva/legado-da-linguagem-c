#include <stdio.h>
#include <locale.h>

int Invertido(int n);

void main()
{
    setlocale(LC_ALL,"Portuguese");
    int x=0;
    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&x);

    Invertido(x);
    printf("\n");
}
int Invertido(int n)
{
    if(n==0)
        return n;
    else
    {
        printf("%d", n % 10);
        n=n / 10;
        return Invertido(n);
    }
}

