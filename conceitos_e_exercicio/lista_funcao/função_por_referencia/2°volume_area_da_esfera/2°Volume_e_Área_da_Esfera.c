#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float Calculo_Volume_Esfera(float r,float *v,float *a);

void main()
{
    setlocale(LC_ALL,"portuguese");
    float raio=0;
    float volume=0,area=0;

    printf("\nInforme o RAIO DA ESFERA: ");
    fflush(stdin);
    scanf("%f",&raio);

    Calculo_Volume_Esfera(raio,&volume,&area);
}
float Calculo_Volume_Esfera(float r,float *v,float *a)
{
    *v = (4*3.1414592)*(r*r*r)/3;
    *a = (4*3.1414592)*(r*r);

    printf("\nVolume da Esfera: %f",*v);
    printf("\n¡rea da Esfera  : %f\n",*a);
}
