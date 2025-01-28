#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    char palavra1[50];
    char palavra2[50];
    char palavra3[50];
    char palavra4[50];
    char p[10]=" ";

    printf("\nInforme 1° palavras: ");
    fflush(stdin);
    gets(palavra1);

    printf("\nInforme 2° palavras: ");
    fflush(stdin);
    gets(palavra2);

    printf("\nInforme 3° palavras: ");
    fflush(stdin);
    gets(palavra3);

    printf("\nInforme 4° palavras: ");
    fflush(stdin);
    gets(palavra4);

    strcat(palavra1,p);
strcat(palavra1, palavra2);
strcat(palavra1,p);
strcat(palavra1, palavra3);
strcat(palavra1,p);
strcat(palavra1, palavra4);

 printf("\n%s\n",palavra1);



}
