#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int Matriz_Transposta(int x[][5],int n,int y[][5],int m);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int A[5][5];
    int B[5][5];

    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            A[l][c]=rand()%9+1;
        }
    }

    Matriz_Transposta(A,5,B,5);
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            printf("|%d",A[l][c]);
        }
        printf("|\n");
    }
}
int Matriz_Transposta(int x[][5],int n,int y[][5],int m)
{
    for(int l=0; l<n; l++)
    {
        for(int c=0; c<n; c++)
        {
            printf("|%d",x[l][c]);
            y[l][c]=x[c][l];
        }
        printf("|\n");
    }
    printf("\n\n");
    for(int l=0; l<5; l++)
    {
        for(int c=0; c<5; c++)
        {
            x[l][c]=y[l][c];
        }
    }
    printf("\n");
}
