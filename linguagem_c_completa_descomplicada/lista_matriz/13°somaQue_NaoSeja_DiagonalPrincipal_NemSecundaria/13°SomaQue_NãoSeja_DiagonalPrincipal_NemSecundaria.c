#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void Soma_Acima_da_DiagonalPrincipal(int x[][4]);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int mat[4][4];

    Soma_Acima_da_DiagonalPrincipal(mat);
}
void Soma_Acima_da_DiagonalPrincipal(int x[][4])
{
    int soma=0;
    int soma_total=0;
    int soma_diagonais=0;

    for(int l=0; l<4; l++)
    {
        for(int c=0; c<4; c++)
        {
            x[l][c]=rand()%8+2;
        }
    }
    for(int l=0; l<4; l++)
    {
        for(int c=0; c<4; c++)
        {
            printf("|%d",x[l][c]);
            soma_total+=x[l][c];
        }
        printf("|\n");
    }
    printf("\n\n");
    for(int l=0; l<4; l++)
    {
        for(int c=0; c<4; c++)
        {
            if (l+c==3 || l==c)
            {
                printf("|%d",x[l][c]);
                soma_diagonais+=x[l][c];
            }
            else
            {
                soma+=x[l][c];
                printf("|x");
            }
        }
        printf("|\n");
    }
    printf("\nSoma total da matriz [4][4] = %d",soma_total);
    printf("\nSoma sem as Diagonais = %d",soma);
    printf("\nSoma das diagonais = %d\n",soma_diagonais);
}
