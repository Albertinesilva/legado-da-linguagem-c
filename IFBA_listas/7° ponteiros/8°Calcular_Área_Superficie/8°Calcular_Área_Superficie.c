#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void esfera(float r,float* area,float* volume);

void main()
{
    setlocale(LC_ALL,"portuguese");
    float Raio=0;
    float Area=0;
    float Volume=0;

    printf("\nInforme o RAIO: ");
    fflush(stdin);
    scanf("%f",&Raio);

    esfera(Raio,&Area,&Volume);
    printf("\nResultado do VOLUME: %f\n",Volume);
    printf("\nResultado do VOLUME: %f\n",Area);

}
void esfera(float r,float* area,float* volume)
{
    *volume=(4*3.14)*(r*r*r)/3;
    *area=(4*3.14)*(r*r);
}

