#include <stdio.h>
#include <stdlib.h>


void main()
{
    FILE *file;
    file = fopen("string.txt","r");

    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo!\n");
        getchar();
        exit(0);
    }

    char frase[100];

    while(fgets(frase,100,file) != NULL)
    {
        printf("%s",frase);
    }
    printf("\n");
}
