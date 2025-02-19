#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    float mat[3][3];

    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            mat[l][c]=rand()%10+1;
        }
    }

    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            printf("|%d",&mat[l][c]);
        }
        printf("\n|");
    }
}

