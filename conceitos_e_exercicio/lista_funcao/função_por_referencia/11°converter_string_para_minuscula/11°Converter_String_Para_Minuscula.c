#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char Converter_Maiuscula(char Maiuscula);

void main()
{
    setlocale(LC_ALL,"portuguese");
    char Maiusc;

    printf("\nInforme uma letra: ");
    fflush(stdin);
    Maiusc=getchar();

    char Minuscula = Converter_Maiuscula(Maiusc);
    printf("\nMinuscula de %c = %c \n",Maiusc,Minuscula);
}
char Converter_Maiuscula(char Maiuscula)
{
    char minuscula = Maiuscula + 32;
    return minuscula;
}
