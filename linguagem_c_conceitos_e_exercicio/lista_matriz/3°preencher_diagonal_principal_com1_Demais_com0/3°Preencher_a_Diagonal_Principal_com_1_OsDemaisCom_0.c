#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void diagonal(int **matriz);

void main()
{
    srand(time(NULL));
    int **mat;

    mat = (int **)malloc(5 * sizeof(int*));

    for(int l=0; l<5; l++)
    {
        mat[l] =(int *)malloc(5 * sizeof(int));
        for(int c=0; c<5; c++)
        {
            mat[l][c]=rand()%50+10;
        }
    }
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            printf("|%d",mat[l][c]);
        }
        printf("|\n");
    }
    printf("\n\n");
    diagonal(mat);

}
void diagonal(int **matriz)
{
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            if(l==c)
            {
                matriz[l][c]=1;
            }
            else
            {
                matriz[l][c]=0;
            }
        }
    }
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            printf("|%d",matriz[l][c]);
        }
        printf("|\n");
    }
}
