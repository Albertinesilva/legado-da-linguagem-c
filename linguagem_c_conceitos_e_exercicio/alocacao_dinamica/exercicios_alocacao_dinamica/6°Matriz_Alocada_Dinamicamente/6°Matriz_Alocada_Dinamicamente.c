#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int retorna_1_ou_0(int *x,int coluna,int linha );

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int linhas=0,colunas=0;

    printf("\nInfome a quantidade de linhas: ");
    fflush(stdin);
    scanf("%d",&linhas);

    printf("\nInforme a quantidade de colunas: ");
    fflush(stdin);
    scanf("%d",&colunas);

    int *mat;
    mat=(int *)malloc(linhas * colunas * sizeof(int));

    for(int l=0; l<linhas; l++)
    {
        for(int c=0; c<colunas; c++)
        {
            mat[l * colunas + c]=rand()%8+1;
        }
    }
    int existe_ou_Nao=retorna_1_ou_0(mat,colunas,linhas);

    if(existe_ou_Nao == 1)
    {
        printf("\nExiste o valor digitado!\n");
    }
    else
    {
        if(existe_ou_Nao == 0)
        {
            printf("\nO valor digitado não existe!\n");
        }
    }
}
int retorna_1_ou_0(int *x,int coluna,int linha)
{
    int valor=0;

    for(int l=0; l<linha; l++)
    {
        for(int c=0; c<coluna; c++)
        {
            printf("|%d",x[l * coluna + c]);
        }
        printf("|\n");
    }

    printf("\n\nDigite um valor: ");
    fflush(stdin);
    scanf("%d",&valor);

    for(int l=0; l<linha; l++)
    {
        for(int c=0; c<coluna; c++)
        {
            if(x[l * coluna + c] == valor)
            {
                return 1;
            }
        }
    }

      for(int l=0; l<linha; l++)
    {
        for(int c=0; c<coluna; c++)
        {
            if(x[l * coluna + c] != valor)
            {
                return 0;
            }
        }
    }
}

