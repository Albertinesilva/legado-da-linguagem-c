#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    FILE *f;
    f=fopen("arquivo.txt","r");

    if(f == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }
    char c = fgetc(f);

    while(c != EOF)
    {
        printf("%c",c);
        c = fgetc(f);
    }
    printf("\nFim!\n");
    fclose(f);
}
