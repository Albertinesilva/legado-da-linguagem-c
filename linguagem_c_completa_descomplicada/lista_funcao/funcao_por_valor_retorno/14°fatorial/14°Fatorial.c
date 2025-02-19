#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorial(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&num);

    int resul = fatorial(num);
    printf("\nFatorial de %d = %d\n",num,resul);
}
int fatorial(int n)
{
    int fatorial_de_n=1;

    for(int i=1; i<=n; i++)
    {
        fatorial_de_n *=i;
    }
    return fatorial_de_n;
}
