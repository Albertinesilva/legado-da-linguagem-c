#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float media(float a,float b,float c, char opcao);

void main()
{
    setlocale(LC_ALL,"portuguese");

    float nota1=0,nota2=0,nota3=0;

    printf("\nDigite a 1° nota: ");
    fflush(stdin);
    scanf("%f",&nota1);

    printf("\nDigite a 2° nota: ");
    fflush(stdin);
    scanf("%f",&nota2);

    printf("\nDigite a 3° nota: ");
    fflush(stdin);
    scanf("%f",&nota3);

    char letra;
    printf("\nESCOLHA\ncalculo da média Aritimética digite [A]\nCalculo da média Ponderada digite   [P]");
    printf("\nEntrada: ");
    fflush(stdin);
    letra=getchar();

    float calculo_media = media(nota1,nota2,nota3,letra);
    if(letra == 'A' || letra == 'a')
    {
        printf("\nMedia Aritmética: %.2f\n",calculo_media);
    }
    else
    {
        if(letra == 'P' || letra == 'p')
        {
            printf("\nMedia Ponderada: %.2f\n",calculo_media);
        }
    }
}
float media(float a,float b,float c,char opcao)
{
    float media=0;

    if(opcao == 'A' || opcao == 'a')
    {
        media=a+b+c;
        return media/3;
    }
    else
    {
        if(opcao == 'P' || opcao == 'p')
        {
            media=(a*5)+(b*3)+(c*2);
            return media/(5+3+2);
        }
        else
        {
            printf("\nOpção Invalida!\n");
        }
    }
}
