#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
   int **mat;
   int menor=0;

   mat = (int **)malloc(3 * sizeof(int));

   for(int l=0; l<3; l++)
   {
       mat[l] = (int *)malloc(3 * sizeof(int));
       for(int c=0; c<3; c++)
       {
         mat[l][c]=rand()%9+1;
       }
   }
   for(int l=0; l<3; l++)
   {
       for(int c=0; c<3; c++)
       {
           printf("|%d",mat[l][c]);
           menor=mat[l][c];
       }
       printf("|\n");
   }
   for(int l=0; l<3; l++)
   {
       for(int c=0; c<3; c++)
       {
           if(mat[l][c]<menor)
           {
               menor=mat[l][c];
           }
       }

   }
   printf("\nMenor Valor da Matriz = %d\n",menor);
}
