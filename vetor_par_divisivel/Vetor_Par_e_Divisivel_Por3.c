#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ganhou(char matriz[3][3],int l,int c,char *nome1,char *nome2);
int letra1=0;
int letra2=0;

void main()
{
    setlocale(LC_ALL,"portuguese");

    char nome1='x';
    char nome2='0'; 

    char mat[3][3]= {'1','2','3','4','5','6','7','8','9'};

    printf("\t  +----------------+\n");
    for(int l=0; l<3; l++)
    {
        printf("\t  ");
        for(int c=0; c<3; c++)
        {
            printf("|  %c ",mat[l][c]);

        }
        printf("  | ");
        printf("\n\t  +----------------+\n");
    }
    int cont1=0;
    char opcao='1';

    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            if(mat[l][c]== opcao )
            {
                mat[l][c]=nome1;

            }
        }
    }
    printf("\n\t  +----------------+\n");
    for(int l=0; l<3; l++)
    {
        printf("\t  ");
        for(int c=0; c<3; c++)
        {
            printf("|  %c ",mat[l][c]);

        }
        printf("  | ");
        printf("\n\t  +----------------+\n");
    }
    int proximo=0;
    int anterior=-1;
    while(proximo!=3 && anterior!=2)
    {
        proximo++;
        anterior++;
        printf("\nlinha = %d",proximo);
        printf("\nlinha_ant = %d\n",anterior);

        for(int l=anterior; l<proximo; l++)
        {
            for(int c=0; c<3; c++)
            {

                if(mat[l][c] == nome1 || mat[l][c]==nome2)
                {
                    cont1++;
                    ganhou(mat,l,c,&nome1,&nome2);
                }
            }
        }
        if(letra1 == 3 || letra2 == 3)
        {
            printf("\n\n\nGanhou na linha %d\n",proximo);
            printf("\nletra1 = %d",letra1);
            printf("\nletra2 = %d",letra2);
            proximo=3;
            anterior=2;
        }
        letra1=0;
        letra2=0;


        for(int i=0; i<3; i++)
        {
            for(int j=anterior; j<proximo; j++)
            {
                if(mat[i][j] == nome1 || mat[i][j]==nome2)
                {
                    //cont1++;
                    ganhou(mat,i,j,&nome1,&nome2);
                }
            }
        }
        if(letra1 == 3 || letra2 == 3)
        {
            printf("\n\n\nGanhou na linha %d\n",proximo);
            printf("\nletra1 = %d",letra1);
            printf("\nletra2 = %d",letra2);
            proximo=3;
            anterior=2;
        }
        letra1=0;
        letra2=0;
    }

    printf("\n\nletra x = %d",cont1);

}
int ganhou(char matriz[3][3],int l,int c,char *nome1,char *nome2)
{
 if (matriz[l][c]==*nome1)
 {
   letra1=letra1+1;
   printf("%c",*nome1);
 }
 else
 {
     letra2=letra2+1;
     printf("%c",*nome2);
 }

}

