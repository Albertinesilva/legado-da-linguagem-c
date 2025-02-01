#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *file;
    file = fopen("string.txt","a");

    if(file == NULL)
    {
        printf("Arquivo não pode ser aberto!");
        getchar();
        exit(1);
    }

    fprintf(file,"Primeira linha\n");

    char frase[] = "Segunda linha ";
    fputs(frase,file);

    char caractere = '3';
    fputc(caractere,file);
}
