#include <stdio.h>
#include <stdlib.h>


void main()
{
    FILE *file;
    file = fopen ("string.txt","w");

    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo!");
        exit(0);
    }

    fprintf(file,"Albert silva de Jesus\nCoxinha\nHot Dog\nInscreva-se no Canal :D\n");
    fclose(file);
}
