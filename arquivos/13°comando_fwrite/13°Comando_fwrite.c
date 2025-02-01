#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *arq;
    arq = fopen("dados.txt","wb");
    if(arq == NULL)
    {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    char str[20]="Hello World";
    float x = 5;
    int vetor[5]={1,2,3,4,5};

    fwrite(str,sizeof(char),20,arq);
    fwrite(&x,sizeof(float),1,arq);
    fwrite(vetor,sizeof(int),5,arq);

    fclose(arq);
}
