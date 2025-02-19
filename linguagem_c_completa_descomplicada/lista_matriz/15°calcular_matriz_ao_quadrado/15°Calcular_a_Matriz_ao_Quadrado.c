#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void Soma_Acima_da_DiagonalPrincipal(int x[][5],int y[][5]);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int A[5][5],B[5][5];

    Soma_Acima_da_DiagonalPrincipal(A,B);
}
void Soma_Acima_da_DiagonalPrincipal(int x[][5],int y[][5])
{
    int soma=0;
    int soma_total=0;
    int soma_diagonais=0;

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
            y[l][c]=x[l][c]*x[l][c];
        }
    }

    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            printf("|%d",y[l][c]);
        }
        printf("|\n");
    }
    printf("\n\n");
}

