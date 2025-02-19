#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Somatorio(int s,int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&num);

    int soma=1;
    soma = Somatorio(soma,num);
    printf("\nResultado da Soma = %d\n",soma);
}
int Somatorio(int s,int n)
{
    if(n == 1)
    {

    }
    else
    {
        return Somatorio(s+n,n-1); //OU Return n + Somatorio(n - 1)
    }

}
