#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    srand (time(NULL));
    int mat [6][6],mat_x[6][6];
    int l=0,c=0,i=0,num=0;
    int vet[36];


    for(l=0; l<6 ; l++)
    {
        for(c=0; c<6 ; c++)
        {
            mat[l][c]=rand()%10+1;
        }
    }
    for(l=0; l<6; l++)
    {
        for(c=0; c<6; c++)
        {
            printf(" %d|",mat[l][c]);
        }
        printf("\n");
    }

    printf("\nInforme um número para fazer a multiplicação da matriz [6][6]: ");
    scanf("%d",&num);


    for(l=0; l<6; l++)
    {
        for(c=0; c<6; c++)
        {

            vet[i]=mat[l][c]*num;
            i++;
        }
    }

    printf("\n");
    for(i=0; i<36; i++)
    {
        printf("%d,",vet[i]);
    }
    printf("\n");


}
