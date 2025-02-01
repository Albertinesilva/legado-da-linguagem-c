#include <stdio.h>
#include <stdlib.h>


void main()
{
    FILE *f;
    f = fopen("arquivo2.txt","w");

    if(f == NULL)
    {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    char texto[20] = "Mãe Amor Eterno";
    int retorno = fputs(texto,f);

    if(retorno == EOF)
    {
        printf("Erro na Gravação!\n");
    }
    fclose(f);
}
