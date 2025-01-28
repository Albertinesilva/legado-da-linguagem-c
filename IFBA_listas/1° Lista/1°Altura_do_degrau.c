#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

float degrau, altura, resultado;

printf("Qual a altura do degrau de uma escada? ");
fflush(stdin);
scanf("%f",&degrau);

printf("Qual a altura que você deseja alcansar subindo a escada? ");
fflush(stdin);
scanf("%f",&altura);


resultado = altura / degrau;

printf("\nO usuário deverar subir %.0f degraus para atingir seu objetivo\n",resultado);


}
