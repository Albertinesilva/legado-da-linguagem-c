#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

//ler um arquivo contendo um texto em minúsculo e criar outro
//arquivo com texto em maiúsculo

void main()
{
    setlocale(LC_ALL,"portuguese");

    FILE *f1,*f2;
    f1 = fopen("arquivo.txt","r");
    f2 = fopen("maiusculo.txt","w");

    if(f1 == NULL || f2 == NULL)
    {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }

    char c = fgetc(f1);
    while(c!= EOF)
    {
        printf("%c",c);
        fputc(toupper(c),f2);
        c = fgetc(f1);
    }
    fclose(f1);
    fclose(f2);

    printf("\n\n");
    f2 = fopen("maiusculo.txt","r");
    char a=fgetc(f2);

    while(a != EOF)
    {
        printf("%c",a);
        a=fgetc(f2);
    }
    fclose(f2);
    printf("\n");
}
