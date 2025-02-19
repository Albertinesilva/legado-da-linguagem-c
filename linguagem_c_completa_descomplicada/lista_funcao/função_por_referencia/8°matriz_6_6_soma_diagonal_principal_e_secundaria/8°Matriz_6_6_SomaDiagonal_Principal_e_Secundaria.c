#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Matriz_SomaDiagonal_Principal_e_Secundaria(int A[][6],int n,int *sPrincipal,int *sSecundaria);

void main()
{
    srand(time(NULL));
    int mat[6][6];
    int Principal=0,Secundaria=0;

    for(int l=0; l<6; l++)
    {
        for(int c=0; c<6; c++)
        {
            mat[l][c]=rand()%9+1;
        }
    }
    Matriz_SomaDiagonal_Principal_e_Secundaria(mat,6,&Principal,&Secundaria);
    printf("\nSoma da Diagonal Principal = %d\n",Principal);
    printf("\nSoma da Diagonal Secundaria = %d\n",Secundaria);

}
int Matriz_SomaDiagonal_Principal_e_Secundaria(int A[][6],int n,int *sPrincipal,int *sSecundaria)
{
    for(int l=0; l<6; l++)
    {
        for(int c=0; c<6; c++)
        {
            printf("|%d",A[l][c]);
        }
        printf("|\n");
    }
    printf("\n");
    for(int l=1; l<=6; l++)
    {
        for(int c=1; c<=6; c++)
        {
            if(l==c)
            {
                *sPrincipal+=A[l][c];
            }
            else
            {
                if(l+c==7)
                {
                    *sSecundaria+=A[l][c];
                }
            }

        }
    }
}
