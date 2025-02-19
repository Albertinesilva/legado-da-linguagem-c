#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int **mat;
    int vet[3]= {0};

    mat = (int **)malloc(3 * sizeof(int*));
    for(int l=0; l<3; l++)
    {
        mat[l] = (int*)malloc(3 * sizeof(int));
        for(int c=0; c<3; c++)
        {
            mat[l][c]=rand()%9+1;
        }
    }

    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            printf("|%d",mat[l][c]);
        }
        printf("|\n");
    }

    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            vet[c]+=mat[l][c];
        }
    }
    printf("\n------------------SOMA DAS COLUNAS--------------------\n");
    for(int y=0; y<3; y++)
    {
        printf("%d,",vet[y]);
    }
    printf("\n\n");
}

