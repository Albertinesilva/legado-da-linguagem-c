#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h.>

void imprime_Matriz(int x[][3]);


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int mat[10][3];

    imprime_Matriz(mat);



}
void imprime_Matriz(int x[][3])
{
    int prova1=0,prova2=0,prova3=0;
    int soma=0;
    int linha=0;

    for(int l=0; l<10; l++)
    {
        for(int c=0; c<3; c++)
        {
            x[l][c]=rand()%8+2;
        }
    }
    for(int l=0; l<10; l++)
    {
        for(int c=0; c<3; c++)
        {
            printf("|%d",x[l][c]);

        }
        printf("|\n");
    }
    printf("|\n");

    for(int l=0; l<1; l++)
    {
        for(int c=0; c<3; c++)
        {
            printf("|%d",x[l][c]);
            soma+=x[l][c];
            linha=l;
        }
        printf("|\n");
    }
    for(int l=0; l<10; l++)
    {
        for(int c=0; c<1; c++)
        {
            if(x[l][c]<5)
            {
                prova1++;
            }
        }
    }
    for(int l=0; l<10; l++)
    {
        for(int c=1; c<2; c++)
        {
            if(x[l][c]<5)
            {
                prova2++;
            }
        }
    }
    for(int l=0; l<10; l++)
    {
        for(int c=2; c<3; c++)
        {
            if(x[l][c]<5)
            {
                prova3++;
            }
        }
    }
    printf("\nNúmero de alunos com a pior nota na 1° prova = %d",prova1);
    printf("\nNúmero de alunos com a pior nota na 2° prova = %d",prova2);
    printf("\nNúmero de alunos com a pior nota na 3° prova = %d",prova3);
    printf("\nSoma da linha %d = %d\n",linha+1,soma);
}
