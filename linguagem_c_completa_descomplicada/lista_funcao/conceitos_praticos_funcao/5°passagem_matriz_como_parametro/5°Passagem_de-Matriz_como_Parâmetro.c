#include <stdio.h>
#include <stdlib.h>

//Arrays com mais de uma dimens�o (por exemplo, matrizes) precisam da informa��o do
//tamanho das dimens�es extras.

//Para arrays com mais de uma dimens�o � necess�rio especificar o tamanho de todas
//as dimens�es, exceto a primeira. Sendo assim, uma declara��o poss�vel para uma
//fun��o que receba uma matriz de quatro linhas e cinco colunas seria a apresentada a
//seguir:

void imprime_matriz(int m[][2],int n)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=0; j< 2; j++)
        {
            printf("|%d",m[i][j]);
        }
        printf("|\n");
    }

}
int main()
{
    int mat[3][2] = {{1,2},{3,4},{5,6}};
    imprime_matriz(mat,3);

    system("pause");
    return 0;
}
