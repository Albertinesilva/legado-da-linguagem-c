#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    char string[50];
    int palavras=0, i=0, tam=0;

    printf("\n\n\tInforme uma STRING: ");
    fflush(stdin);
    gets(string);

    tam=strlen(string);

    while(tam!=i)
    {
        i++;
        printf("\n\nI %d",i);
        if(string[i]==' ' || string[i]=='\0' || string[i] == '\n')
        {
            palavras++;
        }

    }

    printf("\n\n\tA FRASE: %s ,TEM %d PALAVRAS\n",string,palavras);
}
