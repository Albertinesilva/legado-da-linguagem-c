#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    char string2[50];
    char string1;
    int tam=0,i=0,cont=0;

    printf("\n\n\tInforme uma LETRA: ");
    fflush(stdin);
    string1=getchar();

    printf("\n\tInforme outra STRING: ");
    fflush(stdin);
    gets(string2);

    tam=strlen(string2);

    for(i=0; i<tam; i++)
    {
        if(string2[i]==string1)
        {
            cont++;
        }
    }
    printf("\n\n\tLETRA [%c] APARECE NA STRING %s %d VEZES\n",string1,string2,cont);
}
