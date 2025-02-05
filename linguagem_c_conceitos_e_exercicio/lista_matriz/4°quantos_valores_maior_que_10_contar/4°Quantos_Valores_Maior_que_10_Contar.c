#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void diagonal(int **matriz);

void main()
{
    srand(time(NULL));
    int **mat,contador=0;

    mat = (int **)malloc(4 * sizeof(int));
    for(int l=0; l<4; l++)
    {
        mat[l] =(int *)malloc(4 * sizeof(int));
        for(int c=0; c<4; c++)
        {
            mat[l][c]=rand()%30+1;
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
    printf("\n\n");
    for(int l=0; l<4; l++)
    {
        for(int c=0; c<4; c++)
        {
            if(mat[l][c] > 10)
            {
                printf("|%d",mat[l][c]);
                contador++;
            }
        }

    }
    printf("\n\nQuantidade de números maiores que 10 = %d\n",contador);

}
