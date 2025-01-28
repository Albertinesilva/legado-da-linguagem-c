#include <stdio.h>
#include <string.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    char nome[30]="redes";

    strcpy(nome,"analise");

    printf("\n\n\tnome: %s",nome);

    printf("\n\tNome: %s",nome);

    strcpy(nome,"albert");

    printf("\n\tNome: %s",nome);
    printf("\n\tNome: %s",nome);



}
