#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    char s[20];
    char ch1,ch2,aux;
    int tam=0,i=0;

    printf("\n\tInforme uma string: ");
    fflush(stdin);
    gets(s);

    printf("\n\tInforme um caractere: ");
    fflush(stdin);
    ch1=getchar();

    printf("\n\tInforme outro caractere: ");
    fflush(stdin);
    ch2=getchar();

    tam=strlen(s);
    aux=ch1;
    ch1=ch2;
    ch2=aux;

    for(i=0; i<tam; i++)
    {
        s[i]=ch1;
    }

    printf("\n\n\tString: %s\n\tCaractere ch1: %c\n\tCaractere ch2: %c\n\n",s,ch1,ch2);
}
