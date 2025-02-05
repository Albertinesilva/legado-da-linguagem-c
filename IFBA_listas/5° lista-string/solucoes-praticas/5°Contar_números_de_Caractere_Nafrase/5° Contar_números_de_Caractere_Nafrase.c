#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    char frase[50];
    int cont=0, i=0;

    printf("\n\n\tInforme um nome ou uma frase, para contar a quantidade de CARACTERES ");
    fflush(stdin);
    gets(frase);

    while(frase[i] != '\0')
    {
        i++;
        if(frase[i]==frase[i])
        {
            cont++;
        }

    }
    printf("\n\n\tA string %s: TEM %d CARACTERE:\n",frase,cont);
}
