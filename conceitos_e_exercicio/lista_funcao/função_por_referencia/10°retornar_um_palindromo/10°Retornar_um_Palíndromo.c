#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int Palindromo(char palavra[]);

void main()
{
    setlocale(LC_ALL,"portuguese");
    char string[15];

    printf("\nInforme um palavra: ");
    fflush(stdin);
    gets(string);

    int polindromo=Palindromo(string);
    if(polindromo == 0)
    {
        printf("\nA palavra %s não é um POLÍNDROMO!\n",string);
    }
    else
    {
        printf("\nA palavra %s é um POLÍNDROMO!\n",string);
    }
}
int Palindromo(char palavra[])
{
    int tam=strlen(palavra);
    char copia[15];
    int y=tam,i=0,j=0;

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
            return 1;
        }
        else
        {
            return 0;
        }
        j--;
    }
}

