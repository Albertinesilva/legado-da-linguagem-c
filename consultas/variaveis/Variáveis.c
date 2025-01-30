#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main(){

setlocale(LC_ALL,"portuguese");

unsigned int idade = 40;
float peso = 73.5;
char sexo = 'M';
char nome[] = "Matutino";
char nome1[] ="Matutin";
char n[]="Redes";
char n1[]="Redes";
int x=0;

printf("%s é do sexo %c tem %d anos é pesa %.2fKg",nome,sexo,idade,peso);




       x=strcmp(nome,nome1 )+ strcmp(n,n1);



printf("\n\tX: %d",x);




}
