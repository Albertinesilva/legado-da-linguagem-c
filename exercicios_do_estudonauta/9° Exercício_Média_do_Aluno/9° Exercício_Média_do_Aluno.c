#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){

float media,nota1,nota2;
char aluno[20];

setlocale(LC_ALL,"portuguese");

printf("Nome do aluno: ");
fflush(stdin);
gets(aluno);

printf("Nota 1: ");
scanf("%f",&nota1);

printf("Nota 2: ");
scanf("%f",&nota2);

media = (nota1 + nota2)/2;

printf("\nO aluno %s tirou notas %.1f e %.1f e ficou com a média %.1f\n",aluno,nota1,nota2,media);

}
