#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    FILE *f;
    f = fopen("arquivo.txt","w");

    if(f == NULL)
    {
        printf("Erro na abertura!\n");
        exit(1);
    }

    char texto[20];
    printf("Informe um nome: ");
    fflush(stdin);
    fgets(texto,20,stdin);

    int i=0;
    //Gravar string, caractere a caractere
    for(i=0; i<strlen(texto)-1; i++)
    {
        fputc(texto[i],f);
        fputc('-',f);
    }
    printf("%s",texto);
    fclose(f);

}
