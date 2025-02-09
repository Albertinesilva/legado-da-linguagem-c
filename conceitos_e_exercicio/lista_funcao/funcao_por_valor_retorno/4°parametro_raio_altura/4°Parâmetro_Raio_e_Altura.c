#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float Volume_Cilindro(float r,float a);

void main()
{
    setlocale(LC_ALL,"portuguese");

    float altura=0,raio=0;

    printf("\nInforme  o raio do cilindro: ");
    fflush(stdin);
    scanf("%f",&raio);

    printf("\nInforme a altura do cilindro: ");
    fflush(stdin);
    scanf("%f",&altura);

    float VolumeCilindro = Volume_Cilindro(raio,altura);
    printf("\nO volume do Cilindro circular é: %.2f\n",VolumeCilindro);


}
float Volume_Cilindro(float r,float a)
{
    int V = 3.1414592 * (r*r) * a;

    return V;
}
