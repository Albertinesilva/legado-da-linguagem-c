#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *arq;

    arq = fopen("Vetor.txt","wb");
    if(arq == NULL)
    {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    int total_gravado,vetor[5] ={1,2,3,4,5};
    //Grava todo o array no arquivo(5 posições)

    total_gravado = fwrite(vetor, sizeof(int),5,arq);
    if(total_gravado != 5)
    {
        printf("Erro na escrita do arquivo!");
        system("pause");
        exit(1);
    }
    fclose(arq);
}
