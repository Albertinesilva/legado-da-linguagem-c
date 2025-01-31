#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    char string[20];
    char *ponteiro[20];

    printf("\nInforme um nome: ");
    fflush(stdin);
    gets(string);

    for(int i=0; i<7; i++)
    {
        ponteiro[i]=&string[i];

    }
    printf("\nPonteiro = %s\n",*ponteiro);

    strrev(*ponteiro);
    printf("\nPonteiro Invertido = %s\n",*ponteiro);

    printf("\nSTRING INVERTIDA = %s\n",string);
}

