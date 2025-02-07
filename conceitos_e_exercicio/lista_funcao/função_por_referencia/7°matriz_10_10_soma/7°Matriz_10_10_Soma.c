#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int Soma_Matriz(int x[][10],int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int mat[10][10];

    for(int l=0; l<10; l++)
    {
        for(int c=0; c<10; c++)
        {
            mat[l][c]=rand()%10+1;
        }
    }
    Soma_Matriz(mat,10);
    for(int l=0; l<10; l++)
    {
        for(int c=0; c<10; c++)
        {
           printf("|%d",mat[l][c]);
        }
        printf("|\n");
    }
}
int Soma_Matriz(int x[][10],int n)
{
  for(int l=0; l<10; l++)
    {
        for(int c=0; c<10; c++)
        {
           printf("|%d",x[l][c]);
        }
        printf("|\n");
    }
    printf("\n\n");
    for(int l=0; l<10; l++)
    {
        for(int c=0; c<10; c++)
        {
            x[l][c]+=x[l][c];
        }
    }
}
