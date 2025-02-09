#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float Calculo_IMC(float a,float p);

void main()
{
    setlocale(LC_ALL,"portuguese");
    float peso=0;
    float altura=0;

     printf("\nDigite a altura: ");
    fflush(stdin);
    scanf("%f",&altura);

    printf("\nDigite o peso: ");
    fflush(stdin);
    scanf("%f",&peso);

    float IMC=Calculo_IMC(altura,peso);
    printf("\nSeu índice de massa corporal = %f\n",IMC);
}
float Calculo_IMC(float a,float p)
{
    float IMC = p/(a * a);

    return IMC;
}
