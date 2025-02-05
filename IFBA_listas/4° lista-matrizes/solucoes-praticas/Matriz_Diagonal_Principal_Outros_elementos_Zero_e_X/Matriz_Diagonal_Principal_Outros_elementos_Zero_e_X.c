#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

void main ()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int mat[5][5], mat_prin[5][5];
    int l=0,c=0;

    printf("\n\n\t-------------------------MATRIZ [5][5]-------------------------\n\n");
    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            mat[l][c]=rand()%50 + 10;
        }
    }

    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            mat_prin[l][c]=0;
            printf("|%d|",mat[l][c]);
        }
        printf("\n");
    }

    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            if(l==c)
            {
                mat_prin[l][c]=mat[l][c];
            }
        }
    }
    printf("\n\n\t-------------------------DIAGONAL PRINCIPAL---------------------\n\n");
    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            printf("|%d|",mat_prin[l][c]);
        }
        printf("\n");
    }

    printf("\n\n\t-------------------------DIAGONAL PRINCIPAL---------------------\n\n");
    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            if(mat_prin[l][c]!=0)
            {
                printf("|%d|",mat_prin[l][c]);
            }
            else
            {
                printf("|x|");
            }

        }
        printf("\n");

    }

}
