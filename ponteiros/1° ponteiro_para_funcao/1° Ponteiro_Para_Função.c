#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int a,int b)
{
    return a + b;
}
int executa(int (*ponteiro)(int,int),int x, int y)
{
    return ponteiro(x,y);
}
int max(int a,int b)
{
    return (a>b) ? a:b;
}
int soma2(int a,int b)
{
    return a + b;
}

void main()
{
    setlocale(LC_ALL,"portuguese");

    int x,y,z;
    int (*p)(int,int);
    printf("Digite o 1° números: ");
    fflush(stdin);
    scanf("%d",&x);

    printf("Digite o 2° números: ");
    fflush(stdin);
    scanf("%d",&y);


    //Ponteiro recebe endereço da função
    p = soma;
    z = p(x,y);
    printf("Soma = %d\n",z);

    int j,c,l;

    printf("\nDigite 1° números: ");
    fflush(stdin);
    scanf("%d",&j);

    printf("\nDigite 2° números: ");
    fflush(stdin);
    scanf("%d",&c);

    printf("\nMaior: %d\n",executa(max,j,c));
    printf("\nSoma: %d\n",executa(soma2,j,c));
}
