#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void maiuscula (char caractere[20]);

void main()
{
    setlocale(LC_ALL,"portuguese");

    char palavra[20];

    printf("\n\tDigite uma palavra: ");
    fflush(stdin);
    gets(palavra);

    maiuscula(palavra);
}


void maiuscula (char caractere[20])
{
    char palavra[20];
    int i=0;
    int tam=strlen(caractere);

    for(i=0; i<tam; i++)
    {
     palavra[i]=caractere[i]-32;
    }
    palavra[i]='\0';

    printf("\n\tPalavra informada: %s\n\tConvertida para MAIUSCULA: %s\n",caractere,palavra);

}
