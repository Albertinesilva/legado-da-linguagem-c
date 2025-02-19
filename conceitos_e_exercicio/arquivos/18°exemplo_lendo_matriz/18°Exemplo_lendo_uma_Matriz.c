#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    arq = fopen("matriz.txt","r");
    char matriz[3][3];
    int i=0,j=0,v;

    if(arq == NULL)
    {
        printf("Erro\n");
        system("pause");
        exit(1);
    }
    int soma=0;
    while(!feof(arq))
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                fscanf(arq,"%c",&matriz[i][j]);

            }
            fscanf(arq,"\n");

        }
    }

    for(int a=0;a<3;a++)
    {
        for(int b=0;b<3;b++)
        {
            printf("%c",matriz[a][b]);
        }
        printf("\n");

    }
    printf("\n");
    fclose(arq);

    system("pause");
    return 0;
}
