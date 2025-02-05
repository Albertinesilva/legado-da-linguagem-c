#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void Soma_Acima_da_DiagonalPrincipal(int x[][5]);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int mat[5][5];

    Soma_Acima_da_DiagonalPrincipal(mat);
}
void Soma_Acima_da_DiagonalPrincipal(int x[][5])
{
    int soma=0;

    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            x[l][c]=rand()%8+2;
        }
    }
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            printf("|%d",x[l][c]);
        }
        printf("|\n");
    }
    printf("\n\n");
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
           if(c>l)
           {
             printf("|%d",x[l][c]);
             soma+=x[l][c];
           }
        }
        printf("|\n");
    }
    printf("\nResultado da soma = %d\n",soma);
}
