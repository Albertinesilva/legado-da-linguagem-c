#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main()
{
    setlocale(LC_ALL,"portuguese");

    char palavra[30],copia[30];
    int i=0, j=0, tam=0;

    printf("\nInforme uma palavra para saber se ela é PALÍNDROMO: ");
    fflush(stdin);
    gets(palavra);

    printf("\n\n\t------------------------------A PALAVRA: %s------------------------------\n",palavra);

    while(palavra[i] != '\0')
    {

        if(palavra[i] != ' ' && palavra[i] != '\n')
        {
            copia[j]=palavra[i];
            j++;
        }
        i++;
    }

    copia[j]='\0';
    strcpy(palavra,copia);
    tam=strlen(palavra);
    j=tam - 1;

    for(i=0; i<tam; i++)
    {
        if(palavra[i]==copia[j])
        {
            printf("\n\n\tÉ PALÍNDROMO!\n");
            printf("\n\tTamanho da palavra: %d caractere\n\tPalavra informada: %s\n",tam,palavra);

        }
        else
        {
            printf("\n\n\tNÃO É PALÍNDROMO\n");
            printf("\n\tTamanho da palavra: %d caractere\n\tPalavra informada: %s\n",tam,palavra);
        }

        j--;
        return 0;
    }


}
