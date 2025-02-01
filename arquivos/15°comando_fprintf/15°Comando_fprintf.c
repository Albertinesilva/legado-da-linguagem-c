#include <stdio.h>
#include <stdlib.h>

void main()
{
    char nome[20]="Albert";
    int i=41;
    float a=1.86;

    FILE *arq = fopen("arquivo5.txt","w");
    if(arq == NULL)
    {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    //Escreve no arquivo
    fprintf(arq,"Nome: %s\nIdade: %d\nAltura: %f",nome,i,a);
    fclose(arq);
}

