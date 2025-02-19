#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float Convertida_em_Graus_Celsius(float F);

void main()
{
    setlocale(LC_ALL,"portuguese");

    float Fahrenheit=0;

    printf("\nInforme a temperatura: ");
    fflush(stdin);
    scanf("%f",&Fahrenheit);

    float Graus_Celsius=Convertida_em_Graus_Celsius(Fahrenheit);
    printf("\nA temperatura em Celsius = %f\n",Graus_Celsius);

}
float Convertida_em_Graus_Celsius(float F)
{
    float Temperatura_Celsius=0;

    Temperatura_Celsius=(F-32.0)*(5.0/9.0);

    return Temperatura_Celsius;
}
