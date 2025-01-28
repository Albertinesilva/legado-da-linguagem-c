#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    srand (time(NULL));
    int mat_v[3][3],mat_x[3][3];
    int num = 0, l = 0,c = 0, cont = 0;

    printf("\nInforme um número inteiro: ");
    fflush(stdin);
    scanf("%d",&num);

    printf("\n");

    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            mat_v[l][c]=rand()%10+ 1;
        }
    }

    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            printf("|%d|",mat_v[l][c]);
        }
        printf("\n");
    }

    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            if(mat_v[l][c] == num)
            {
                cont++;

            }
            if(mat_v[l][c] != num)
            {
                mat_x[l][c] = mat_v[l][c];
            }
            else
            {
                mat_x[l][c] = 0;
            }

        }
    }
    printf("\n\t------------------------------NOVA MATRIZ-----------------------------\n\n");

    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            if( mat_x[l][c] == 0)
            {
                printf("|x|");
            }
            else
            {
                printf("|%d|",mat_x[l][c]);
            }
        }

        printf("\n");
    }

    if(cont > 0)
    {
        printf("\nO número encontrado na Matriz[5][5] = %d",num);
        printf("\nQuantidade de casos que foi encontrado: %d\n",cont);
    }


}

