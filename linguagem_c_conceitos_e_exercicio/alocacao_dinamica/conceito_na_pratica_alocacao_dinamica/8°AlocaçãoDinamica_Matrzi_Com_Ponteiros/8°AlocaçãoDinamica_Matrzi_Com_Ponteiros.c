#include <stdio.h>
#include <stdlib.h>

//Basicamente, para alocar uma matriz (array com duas dimensões) utiliza-se um
//ponteiro com dois níveis.

//Em um ponteiro para ponteiro, cada nível do ponteiro permite criar uma nova
//dimensão no array.

//Por exemplo, se quisermos um array com duas dimensões, precisaremos de um
//ponteiro com dois níveis (**); se quisermos três dimensões, precisaremos de um ponteiro
//com três níveis (***) e assim por diante.
//O exemplo exemplifica como alocar cada nível de um “ponteiro
//para ponteiro” para criar uma matriz (array com duas dimensões).

int main()
{
    int **p; //2 “*” = 2 níveis = 2 dimensões
    int i, j, N = 2;

    p = (int**) malloc(N*sizeof(int *));

    for (i = 0; i < N; i++)
    {
        p[i] = (int *)malloc(N*sizeof(int));
        for (j = 0; j < N; j++)
        {
            printf("Digite a linha e a coluna: ");
            scanf("%d",&p[i][j]);
        }
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d",p[i][j]);
        printf("\n");
    }
    printf("\n-------------------------------------------------------------------------------------------------------\n");
//Nesse exemplo, utilizando um ponteiro com dois níveis (int **p), alocamos no
//primeiro nível do ponteiro um array de ponteiros representando as linhas da matriz.
//Essa tarefa é realizada pela primeira chamada da função malloc(), a qual aloca o array
//usando o tamanho de um ponteiro para int:
///sizeof(int *)

//Em seguida, para cada posição desse array de ponteiros, alocamos um array de
//inteiros, o qual representa o espaço para as colunas da matriz, as quais efetivamente
//manterão os dados. Essa tarefa é realizada pela segunda chamada da função malloc(),
//dentro do comando for, a qual aloca o array usando o tamanho de um int:
///sizeof(int)

//Note que, desse modo, é possível manter a notação de colchetes para representar cada
//uma das dimensões da matriz.



///Diferentemente dos arrays de uma dimensão, para liberar da memória um array com
///mais de uma dimensão é preciso liberar a memória alocada em cada uma de suas
///dimensões, na ordem inversa da que foi alocada.

    int **p1; //2 “*” = 2 níveis = 2 dimensões
    int y, x, M = 2;
    p1 = (int **) malloc(M*sizeof(int *));
    for (y = 0; y < M; y++)
    {
        p1[y] = (int *) malloc(M*sizeof(int));
        for (x = 0; x < M; x++)
        {
            printf("Digite a linha e a coluna: ");
            scanf("%d",&p1[y][x]);
        }
    }
    printf("\n");
    for (y = 0; y < M; y++)
    {
        for (x = 0; x < M; x++)
            printf("%d",p1[y][x]);
        printf("\n");
    }
    for (y = 0; y < M; y++)
    {
        free(p1[y]);
    }
    free(p1);
    printf("\n");

//Para alocar nossa matriz, utilizamos duas chamadas da função malloc(): a primeira
//chamada faz a alocação das linhas, enquanto a segunda faz a alocação das colunas.

//Na hora de liberar a matriz, devemos liberar a memória no sentido inverso da alocação:
//primeiro liberamos as colunas, para depois liberar as linhas da matriz. Essa ordem deve
//ser respeitada porque, se liberarmos primeiro as linhas, perderemos os ponteiros para
//onde estão alocadas as colunas e, assim, não poderemos liberá-las.

    printf("\n-------------------------------------------------------------------------------------------------------\n");

//Esse tipo de alocação, usando ponteiro para ponteiro, permite criar matrizes que não
//sejam quadradas ou retangulares.

//Note que a segunda chamada da função malloc() está condicionada ao valor de i:
//malloc((i+1)*sizeof(int)). Assim, as colunas de cada linha da matriz terão um número
//diferente de elementos. De fato, o código anterior cria uma matriz triangular inferior,
//como fica claro pelo Exemplo a seguir:

    int **p3; //2 “*” = 2 níveis = 2 dimensões
    int a, b, C = 3;
    p3 = (int **) malloc(C*sizeof(int *));
    for (a = 0; a < C; a++)
    {
        p3[a] = (int *) malloc((a+1)*sizeof(int));
        for (b = 0; b < (a+1); b++)
        {
            printf("Digite a linha e a coluna: ");
            scanf("%d",&p3[a][b]);
        }
    }
    for (a = 0; a < C; a++)
    {
        for (b = 0; b < C; b++)
        {
            printf("%d",p3[a][b]);

        }
        printf("\n");
    }
    for (a = 0; a < C; a++)
    {
        free(p3[a]);
    }
    free(p3);

    system("pause");
    return 0;
}
