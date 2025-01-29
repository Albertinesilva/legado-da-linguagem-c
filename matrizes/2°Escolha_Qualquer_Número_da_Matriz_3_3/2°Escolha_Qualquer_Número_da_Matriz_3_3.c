#include <stdio.h>


void main ()
{
    char mat[3][3]= {'1','2','3','4','5','6','7','8','9'};
    int l=0,c=0;
    char opcao='4';
    char x;

    for(l=0; l<3; l++)
    {
        for(c=0; c<3; c++)
        {
            printf("|%c",mat[l][c]);
        }
        printf("|\n");
    }
    printf("\n\n");

    for(int c=0; c<9; c++)
    {
        if(mat[0][c] == opcao)
        {
            x=mat[0][c];
        }
    }

    printf("Valor de X = %c\n",x);
    printf("Valor de 1 na tabela ASCII = %d\n",x);










}
