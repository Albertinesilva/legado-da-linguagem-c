#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int escreva (int x[4][4]);
int matprincipal(int p[4][4]);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int mat[4][4],principal[4][4];
    int l=0,c=0;

    for(l=0; l<4; l++)
    {
        for(c=0; c<4; c++)
        {
            mat[l][c]=rand()%50+10;
            principal[l][c]=0;
        }
    }
    escreva(mat);

    for(l=0; l<4; l++)
    {
        for(c=0; c<4; c++)
        {
            if(l==c)
            {
                principal[l][c]=mat[l][c];
            }
        }
    }
    printf("\n\n");
    matprincipal(principal);
}
int escreva (int x[4][4])
{
    int l=0,c=0;

    for(l=0; l<4; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            printf("|%d|",x[l][c]);
        }
        printf("\n");
    }
}
int matprincipal(int p[4][4])
{
    int l=0,c=0;

    for(l=0; l<4; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            if(p[l][c]!=0)
            {
                printf("|%d|",p[l][c]);
            }
            else
            {
                printf("|x|");
            }

        }
        printf("\n");

    }


}

