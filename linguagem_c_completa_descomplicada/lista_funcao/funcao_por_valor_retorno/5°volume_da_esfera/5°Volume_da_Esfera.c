#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void Calculo_Volume_Esfera(float r);

void main()
{
    setlocale(LC_ALL,"portuguese");
    float raio=0;

    printf("\nInforme o RAIO DA ESFERA: ");
    fflush(stdin);
    scanf("%f",&raio);

    Calculo_Volume_Esfera(raio);

}
void Calculo_Volume_Esfera(float r)
{
    float V = (4*3.1414592)*(r*r*r)/3;

    printf("\nVolume da ESFERA: %f\n",V);
}
