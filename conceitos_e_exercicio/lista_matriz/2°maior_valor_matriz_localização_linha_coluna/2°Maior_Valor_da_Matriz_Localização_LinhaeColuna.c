#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int **mat;
    int maior=0,linha=0,coluna=0;

    mat =(int **)malloc(4 * sizeof(int *));

    for(int l=0; l<4; l++)
    {
        mat[l]=(int *)malloc(4 * sizeof(int));
        for(int c=0; c<4; c++)
        {
            mat[l][c]=rand()%10+1;
        }
    }
    for(int l=0; l<4; l++)
    {
        for(int c=0; c<4; c++)
        {
            printf("|%d",mat[l][c]);
        }
        printf("|\n");
    }

    for(int l=0; l<4; l++)
    {
        for(int c=0; c<4; c++)
        {
            if(mat[l][c] > maior)
            {
                maior=mat[l][c];
                linha=l;
                coluna=c;
            }
        }

    }
    printf("\n\n");
    printf("Maior elemento da Matriz = %d\nLocalizado na Linha %d e Coluna %d\n",maior,linha+1,coluna+1);

}
