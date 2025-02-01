#include <stdio.h>
#include <stdlib.h>


void main()
{
    char str[20];

    FILE *arq;
    arq = fopen("arquivo3.txt","r");
    if(arq == NULL)
    {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    char *result = fgets(str,20,arq);
    if(result == NULL)
    {
        printf("Erro na leitura\n");
    }
    else
    {
        printf("%s",str);
    }
    printf("\n");
    fclose(arq);
}
