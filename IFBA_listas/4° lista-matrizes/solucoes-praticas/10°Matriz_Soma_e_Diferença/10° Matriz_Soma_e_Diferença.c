#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand (time(NULL));

    int m[6][4], n[6][4], soma[6][4],sub[6][4];
    int l=0,c=0;

    for(l=0; l<6; l++)
    {
        for(c=0; c<4; c++)
        {
            m[l][c]=rand()%50 + 10;
            n[l][c]=rand()%50 + 10;
        }
    }

    printf("\n\n\t--------------------------------------MATRIZ (M) [6][4]-------------------------------------\n\n");
    for(l=0; l<6; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            printf("|%d|",m[l][c]);
        }
        printf("\n");
    }

    printf("\n\n\t--------------------------------------MATRIZ (N) [6][4]-------------------------------------\n\n");
    for(l=0; l<6; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            printf("|%d|",n[l][c]);
        }
        printf("\n");
    }

    for(l=0; l<6; l++)
    {
        for(c=0; c<4; c++)
        {
            soma[l][c]=m[l][c] + n[l][c];
        }
    }

    printf("\n\n\t--------------------------RESULTADO DA SOMA ENTRE M E N [6][4]------------------------------\n\n");
    for(l=0; l<6; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            printf("|%d|",soma[l][c]);
        }
        printf("\n");
    }

    for(l=0; l<6; l++)
    {
        for(c=0; c<4; c++)
        {
            sub[l][c]=m[l][c] - n[l][c];
        }
    }

    printf("\n\n\t--------------------------RESULTADO DA DIFERENÇA ENTRE M E N [6][4]-------------------------\n\n");
    for(l=0; l<6; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            printf("|%d|",sub[l][c]);
        }
        printf("\n");
    }
}
