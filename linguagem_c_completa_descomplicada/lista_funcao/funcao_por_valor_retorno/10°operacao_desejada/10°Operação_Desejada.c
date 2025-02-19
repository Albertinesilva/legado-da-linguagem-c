#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float resultado_operacao(float valor1,float valor2,char operacao);

void main()
{
    setlocale(LC_ALL,"portuguese");

    float num1=0,num2=0;
    char simbolo;

    printf("\nDigite o 1° número: ");
    fflush(stdin);
    scanf("%f",&num1);

    printf("\nDigite o 2° número: ");
    fflush(stdin);
    scanf("%f",&num2);

    printf("\nEscolha o simbolo da operação:\n[+]\n[-]\n[*]\n[/]");
    printf("\nEntrada: ");
    fflush(stdin);
    simbolo=getchar();

    if(simbolo != '+' && simbolo != '-' && simbolo != '*' && simbolo != '/')
    {
        printf("\nSimbolo %c Invalido!\n",simbolo);
    }
    else
    {
        printf("\n%.1f\n",resultado_operacao(num1,num2,simbolo));
    }
}
float resultado_operacao(float valor1,float valor2,char operacao)
{
    if(operacao == '+')
    {
        return valor1+valor2;
    }
    else
    {
        if(operacao == '-')
        {
            return valor1-valor2;
        }
        else
        {
            if(operacao == '*')
            {
                return valor1*valor2;
            }
            else
            {
                if(operacao == '/')
                {
                    return valor1/valor2;
                }
            }
        }
    }
}
