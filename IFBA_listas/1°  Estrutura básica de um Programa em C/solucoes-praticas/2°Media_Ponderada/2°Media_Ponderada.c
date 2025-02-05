#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

float nota1,nota2,nota3,media;

printf("Informe a primeira nota. ");
fflush(stdin);
scanf("%f",&nota1);

printf("\nInforme a segunda nota. ");
fflush(stdin);
scanf("%f",&nota2);

printf("\nInforme a terceira nota. ");
fflush(stdin);
scanf("%f",&nota3);

media = ((nota1*1) + (nota2*1) + (nota3*2)) /4;

printf("\nA média final do aluno foi: %.0f\n",media);

}
