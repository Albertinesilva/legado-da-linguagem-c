#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Numeros_Naturais(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&x);
    printf("\n");

    Numeros_Naturais(x);
    printf("\n");
}
int Numeros_Naturais(int n)
{
    if(n == -1)
    {
        return n;
    }
    printf("%d,",n);
    n + Numeros_Naturais(n-1);

}
