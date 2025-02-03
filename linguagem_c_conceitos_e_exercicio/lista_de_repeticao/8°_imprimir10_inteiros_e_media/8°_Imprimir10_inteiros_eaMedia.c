#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;
    float media=0,soma=0;

    for(int i=0; i<10; i++)
    {
        printf("\nDigite um número: ");
        fflush(stdin);
        scanf("%d",&num);

        soma+=num;
    }
    media=soma/10;
    printf("\nSoma = %.0f\nMédia = %.1f\n",soma,media);
}
