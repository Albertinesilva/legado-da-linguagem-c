#include <stdio.h>
#include <locale.h>
#include <stdlib.h>



struct menor
{
    int num;
} teste;


void main()
{
    int aux=0;
    setlocale (LC_ALL, "portuguese");

    struct menor p;
    struct menor x;

    printf("\nDigite um número\n");
    scanf("%d",&teste.num);

    printf("Digite um número\n");
    scanf("%d",&p.num);

    printf("Digite um número\n");
    scanf("%d",&x.num);


    if(teste.num>p.num)
    {
        aux=teste.num;
        teste.num=p.num;
        p.num=aux;

    }

    if(teste.num>x.num)
    {
        aux=teste.num;
        teste.num=x.num;
        x.num=aux;
    }

    if(p.num>teste.num)
    {
        aux=p.num;
        p.num=teste.num;
        teste.num=aux;
    }

    if(p.num>x.num)
    {
        aux=p.num;
        p.num=x.num;
        x.num=aux;
    }
    if(x.num>teste.num)
    {
        aux=x.num;
        x.num=teste.num;
        teste.num=aux;
    }
    if(x.num>p.num)
    {
        aux=x.num;
        x.num=p.num;
        p.num=aux;
    }


    printf("%d,%d,%d",teste.num,p.num,x.num);
}
