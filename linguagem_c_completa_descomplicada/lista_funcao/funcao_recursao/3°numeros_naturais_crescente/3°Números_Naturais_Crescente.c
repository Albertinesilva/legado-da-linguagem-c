#include <stdio.h>
#include <locale.h>

int Numeros_Naturais(int n,int y);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0,a=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&x);
    printf("\n");

    Numeros_Naturais(x,a);
    printf("\n");
}
int Numeros_Naturais(int n,int y)
{
    printf("%d,",y);
    if(n==y)
    {
        return y;
    }
    y + Numeros_Naturais(n,y+1);

}
