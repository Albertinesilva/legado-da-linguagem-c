#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int linhas=0,piramide=0, cont=0, num=0;

    printf("\nInforme a quantidade de linhas da pirâmide: ");
    scanf("%d",&linhas);
printf("\n\n");
    //system("cls");

    while(piramide!=linhas)
    {
        piramide++;

        while(cont!=piramide)
        {
            cont++;
            printf("%.2d ",piramide);
        }
        printf("\n");

        cont=0;
    }

    // 2° Exemplo: COM COMANDO (FOR)

    printf("\n\nInforme um número para formar outra pirâmide: ");
    scanf("%d",&num);
    printf("\n");



    for(int i=1; i<=num; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf("%.2d",i);
        }
        printf("\n");
    }

}
