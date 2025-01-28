#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <windows.h>


void main ()
{
    setlocale(LC_ALL,"portuguese");
    SetConsoleTitle("Converter tipos de dados");
    srand(time(NULL));

    int mat[5][5];
    int mat_prin[5][5],mat_secun[5][5];
    int l=0,c=0;
    int soma_linha4=0, soma_coluna2=0, diagonal_prin=0, diagonal_secun=0, soma_todos_elementos=0;


    printf("\n\t------------------------------MATRIZ [5] [5]------------------------------------\n\n");

    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            mat[l][c]=rand()%90 + 10;
            mat_prin[l][c]= 0;
            mat_secun[l][c]=0;

        }
    }

    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            printf(" |%d|",mat[l][c]);
        }
        printf("\n");
    }

    printf("\n\t------------------------------SOMA DA LINHA 4-----------------------------------\n");

    for(l=0; l<5; l++)
    {
        soma_linha4=soma_linha4+mat[3][l];
    }

    printf("\n\n\tRESULTADO DA SOMA: %d\n",soma_linha4);

    printf("\n\n\t------------------------------SOMA DA COLUNA 2----------------------------------\n");

    for(c=0; c<5; c++)
    {
        soma_coluna2=soma_coluna2+mat[c][1];
    }

    printf("\n\n\tRESULTADO DA SOMA: %d\n",soma_coluna2);

    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            if(l==c)
            {
                mat_prin[l][c]= mat[l][c];
                diagonal_prin=diagonal_prin+mat[l][c];

            }
        }
    }

    printf("\n\n\t------------------------------DIAGONAL PRINCIPAL--------------------------------\n\n");
    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            if(mat_prin[l][c]!=0)
            {
                printf("|%d|",mat_prin[l][c]);
            }
            else
            {
                printf("|x|");
            }
        }
        printf("\n");
    }
    printf("\n\t---------------------------SOMA DIAGONAL PRINCIPAL------------------------------\n");
    printf("\n\tRESULTADO DA SOMA: %d\n",diagonal_prin);

    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            if(l+c==4)
            {
                mat_secun[l][c]=mat[l][c];
                diagonal_secun=diagonal_secun+mat[l][c];
            }
        }
    }
    printf("\n\n\t------------------------------DIAGONAL SECUNDARIA-------------------------------\n\n");
    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            if(mat_secun[l][c]!=0)
            {
                printf("|%d|",mat_secun[l][c]);
            }
            else
            {
                printf("|x|");
            }
        }
        printf("\n");
    }

    printf("\n\n\t--------------------------SOMA DA DIAGONAL SECUNDARIA---------------------------\n");
    printf("\n\tRESULTADO DA SOMA: %d\n",diagonal_secun);
    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            soma_todos_elementos=soma_todos_elementos+mat[l][c];
        }

    }

    printf("\n\n\t------------------SOMA DE TODOS OS ELEMENTOS DA MATRIZ [5] [5]------------------\n");
    printf("\n\tRESULTADO DA SOMA: %d\n\n",soma_todos_elementos);

}
