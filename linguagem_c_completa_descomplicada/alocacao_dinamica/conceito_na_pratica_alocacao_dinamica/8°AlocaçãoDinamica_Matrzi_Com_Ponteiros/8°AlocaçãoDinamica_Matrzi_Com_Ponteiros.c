#include <stdio.h>
#include <stdlib.h>

//Basicamente, para alocar uma matriz (array com duas dimens�es) utiliza-se um
//ponteiro com dois n�veis.

//Em um ponteiro para ponteiro, cada n�vel do ponteiro permite criar uma nova
//dimens�o no array.

//Por exemplo, se quisermos um array com duas dimens�es, precisaremos de um
//ponteiro com dois n�veis (**); se quisermos tr�s dimens�es, precisaremos de um ponteiro
//com tr�s n�veis (***) e assim por diante.
//O exemplo exemplifica como alocar cada n�vel de um �ponteiro
//para ponteiro� para criar uma matriz (array com duas dimens�es).

int main()
{
    int **p; //2 �*� = 2 n�veis = 2 dimens�es
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
//Nesse exemplo, utilizando um ponteiro com dois n�veis (int **p), alocamos no
//primeiro n�vel do ponteiro um array de ponteiros representando as linhas da matriz.
//Essa tarefa � realizada pela primeira chamada da fun��o malloc(), a qual aloca o array
//usando o tamanho de um ponteiro para int:
///sizeof(int *)

//Em seguida, para cada posi��o desse array de ponteiros, alocamos um array de
//inteiros, o qual representa o espa�o para as colunas da matriz, as quais efetivamente
//manter�o os dados. Essa tarefa � realizada pela segunda chamada da fun��o malloc(),
//dentro do comando for, a qual aloca o array usando o tamanho de um int:
///sizeof(int)

//Note que, desse modo, � poss�vel manter a nota��o de colchetes para representar cada
//uma das dimens�es da matriz.



///Diferentemente dos arrays de uma dimens�o, para liberar da mem�ria um array com
///mais de uma dimens�o � preciso liberar a mem�ria alocada em cada uma de suas
///dimens�es, na ordem inversa da que foi alocada.

    int **p1; //2 �*� = 2 n�veis = 2 dimens�es
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

//Para alocar nossa matriz, utilizamos duas chamadas da fun��o malloc(): a primeira
//chamada faz a aloca��o das linhas, enquanto a segunda faz a aloca��o das colunas.

//Na hora de liberar a matriz, devemos liberar a mem�ria no sentido inverso da aloca��o:
//primeiro liberamos as colunas, para depois liberar as linhas da matriz. Essa ordem deve
//ser respeitada porque, se liberarmos primeiro as linhas, perderemos os ponteiros para
//onde est�o alocadas as colunas e, assim, n�o poderemos liber�-las.

    printf("\n-------------------------------------------------------------------------------------------------------\n");

//Esse tipo de aloca��o, usando ponteiro para ponteiro, permite criar matrizes que n�o
//sejam quadradas ou retangulares.

//Note que a segunda chamada da fun��o malloc() est� condicionada ao valor de i:
//malloc((i+1)*sizeof(int)). Assim, as colunas de cada linha da matriz ter�o um n�mero
//diferente de elementos. De fato, o c�digo anterior cria uma matriz triangular inferior,
//como fica claro pelo Exemplo a seguir:

    int **p3; //2 �*� = 2 n�veis = 2 dimens�es
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
