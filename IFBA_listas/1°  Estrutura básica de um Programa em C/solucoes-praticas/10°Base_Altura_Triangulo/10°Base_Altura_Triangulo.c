#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

void main() {
setlocale(LC_ALL,"portuguese");

float base,altura,area;

printf("Informe a base do triangulo: ");
fflush(stdin);
scanf("%f",&base);

printf("Informe a altura do triangulo: ");
fflush(stdin);
scanf("%f",&altura);

area = (altura * base)/2;

printf("\n¡rea do triangulo %.1f\n",area);


}
