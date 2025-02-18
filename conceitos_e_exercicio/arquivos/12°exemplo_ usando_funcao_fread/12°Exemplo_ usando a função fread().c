#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    arq = fopen("ArqGrav.txt","rb");
    if(arq == NULL)
    {
        printf("Problemas na ABERTURA do arquivo\n");
        system("pause");
        exit(1);
    }
    char str1[20],str2[20];
    float x;
    int i,v1[5],v2[2];

    //l� a string toda do arquivo
    fread(str1,sizeof(char),12,arq);
    str1[12] = '\0';
    printf("%s\n",str1);

    //l� apenas os 5 primeiros caracteres da string
    fread(str2,sizeof(char),5,arq);
    str2[5] = '\0';
    printf("%s\n",str2);

    //l� o valor de x do arquivo
    fread(&x,sizeof(float),1,arq);
    printf("%.2f\n",x);
    printf("\n");
    //l� todo o array do arquivo (5 posi��es)
    fread(v1,sizeof(int),5,arq);
    for(i = 0; i < 5; i++)
        printf("v1[%d] = %d\n",i,v1[i]);
    fread(v2,sizeof(int),2,arq);
    printf("\n");
    //l� apenas as 2 primeiras posi��es do array
    for(i = 0; i < 2; i++)
        printf("v2[%d] = %d\n",i,v2[i]);
    fclose(arq);

    system("pause");
    return 0;
}
