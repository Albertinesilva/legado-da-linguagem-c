#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *arq;
    arq = fopen("matriz.txt","w");
    if(arq == NULL)
    {
        printf("Erro\n");
        system("pause");
        exit(1);
    }
 char mat[3][3]= {'X','0','3','4','5','6','7','8','9'};
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            fprintf(arq,"%c",mat[i][j]);
        }
        fprintf(arq,"\n");

    }

    fclose(arq);
    system("pause");
    return 0;
}
