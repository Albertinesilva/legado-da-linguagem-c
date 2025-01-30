#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void main(){

char nome [10];
setlocale(LC_ALL,"portuguese");
printf("Qual é o seu nome?\n");
scanf("%s",&nome);
printf("Muito prazer em lhe conhecer %s\n",nome);
system ("pause");
}
