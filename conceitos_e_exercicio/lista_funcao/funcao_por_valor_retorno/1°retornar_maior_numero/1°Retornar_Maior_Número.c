#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Maior_numero(int x,int y);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int a=0,b=0;

    printf("\nDigite o 1° número: ");
    fflush(stdin);
    scanf("%d",&a);

    printf("\nDigite o 2° número: ");
    fflush(stdin);
    scanf("%d",&b);

    int maior=Maior_numero(a,b);

    printf("\nMaior %d\n",maior);


}
int Maior_numero(int x,int y)
{
    int maior=0;

    if(x > y)
    {
        maior=x;
    }
    else
    {
        maior=y;
    }
    return maior;
}

