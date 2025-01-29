#include <stdio.h>


void main ()
{
    char mat[3][3]= {'x',2,3,4,5,6,7,8,9,};
    int l=0,c=0;
    int opcao=1;


    for(l=0; l<3; l++)
    {
        for(c=0; c<3; c++)
        {
            printf("|%d",mat[l][c]);
        }
        printf("|\n");
    }
    printf("\n\n");


    printf("Matriz %d\n",mat[0][opcao-1]);




}
