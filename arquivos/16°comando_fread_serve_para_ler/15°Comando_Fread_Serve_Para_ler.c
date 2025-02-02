#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *arq;
    arq = fopen("vetor.txt","rb");
    if(arq == NULL)
    {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    int total_lido, vetor[5];//={1,2,3,4,5,};
    total_lido = fread(vetor,sizeof(int),5,arq);

    if(total_lido != 5)
    {
        printf("Erro na leitura do arquivo!");
        system("pause");
        exit(1);
    }
    fclose(arq);

    int b[5];
    for(int i=0; i<5; i++)
    {
        b[i]=vetor[i];
        printf("%d,",vetor[i]);
    }
    printf("\n----------------------Vetor B--------------------------\n");
    for(int i=0; i<5; i++)
    {
        printf("%d,",b[i]);
    }
    printf("\n\n----------------------OUTRO ARQUIVO--------------------");
    FILE *arq1;
    arq1 = fopen("dados.txt","rb");
    if(arq1 == NULL)
    {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    char str[20];//Hello World;
    float x;//=5;
    int v[5];//{1,2,3,4,5};

    fread(str,sizeof(char),20,arq1);
    fread(&x,sizeof(float),1,arq1);
    fread(v,sizeof(int),5,arq1);

    printf("\n%s,\n%f\n",str,x);
    for(int i=0; i<5; i++)
    {
        printf("%d,",v[i]);
    }
    fclose(arq1);




}
