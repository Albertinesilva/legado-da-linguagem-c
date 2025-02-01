#include <stdio.h>
#include <stdlib.h>

struct cadastro{
    char nome[30],endereco[30];
    int idade;
};

void main()
{
     printf("\n--------------ESCREVENDO NA STRUCT------------\n");
    FILE *arq;
    arq = fopen("struct.txt","wb");
    if(arq == NULL)
    {
        printf("Erro de abertura!");
        system("pause");
        exit(1);
    }
    struct cadastro cad = {"Andre","Rua 1",31};
    fwrite(&cad,sizeof(struct cadastro),1,arq);
    fclose(arq);

    printf("\n----------------LENDO A STRUCT---------------");
    FILE *arq1;
    arq1 = fopen("struct.txt","rb");
    if(arq == NULL)
    {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    struct cadastro cad1;// = {"Andre","Rua 1",31};
    fread(&cad1,sizeof(struct cadastro),1,arq1);
    printf("\n%s\n%s\n%d\n",cad1.nome,cad1.endereco,cad1.idade);
    fclose(arq);
}
