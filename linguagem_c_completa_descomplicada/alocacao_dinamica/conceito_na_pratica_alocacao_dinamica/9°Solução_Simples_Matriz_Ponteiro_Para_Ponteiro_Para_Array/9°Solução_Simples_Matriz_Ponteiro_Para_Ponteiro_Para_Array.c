#include <stdio.h>
#include <stdlib.h>

//A terceira solu��o poss�vel para alocar um array com mais de uma dimens�o e manter
//a nota��o de colchetes para cada dimens�o � um misto das duas solu��es anteriores:
//simulamos um array bidimensional (ou com mais dimens�es) utilizando:

//�� Um array unidimensional alocado dinamicamente e contendo as posi��es de
//todos os elementos.
//�� Um array de ponteiros unidimensional que simular� as dimens�es e, assim,
//manter� a nota��o de colchetes.
//O exemplo abaixo exemplifica como simular uma matriz utilizando um
//array de ponteiros e um array unidimensional contendo os dados.

//utilizando aritm�tica de ponteiros, associamos cada posi��o do array de
//ponteiros para uma por��o do array de inteiros:
///p[i] = v + i * Ncolunas;

int main()
{

    int *v; //1 �*� = 1 n�vel = 1 dimens�o
    int **p; //2 �*� = 2 n�veis = 2 dimens�es
    int i, j, Nlinhas = 2, Ncolunas = 2;

    v = (int*) malloc(Nlinhas * Ncolunas *sizeof(int));
    p = (int **) malloc(Nlinhas * sizeof(int *));

    for (i = 0; i < Nlinhas; i++)
    {
        p[i] = v + i * Ncolunas;
        for (j = 0; j < Ncolunas; j++)
        {
            printf("Digite a Linha e a Coluna: ");
            scanf("%d",&p[i][j]);
        }

    }
    printf("\n");
    for (i = 0; i < Nlinhas; i++)
    {
        for (j = 0; j < Ncolunas; j++)
            printf("%d ",p[i][j]);
        printf("\n");
    }
    free(v);
    free(p);

//Nesse exemplo, utilizando um ponteiro com um n�vel (int *v), alocamos o total de
//elementos da matriz (Nlinhas * Ncolunas). Essa tarefa � realizada pela primeira chamada
//da fun��o malloc(), a qual aloca o array usando o tamanho de um tipo int:
///sizeof(int)

//Em seguida, utilizando um ponteiro com dois n�veis (int **p), alocamos no primeiro
//n�vel do ponteiro um array de ponteiros representando as linhas da matriz.
//Essa tarefa � realizada pela primeira chamada da fun��o malloc(), a qual aloca o array
//usando o tamanho de um ponteiro para int:
///sizeof(int *)

//Do ponto de vista de aloca��o, essa solu��o � mais simples do que a anterior (solu��o
//2). Ela utiliza apenas duas chamadas da fun��o malloc() para alocar toda a matriz.
//Consequentemente, apenas duas chamadas da fun��o free() s�o necess�rias para liberar
//a mem�ria alocada.
//Por outro lado, para arrays com mais de duas dimens�es, essa solu��o pode se mostrar
//mais complicada de se trabalhar, j� que envolve aritm�tica de ponteiros no c�lculo
//que associa as linhas com o array contendo os dados.

    system("pause");
    return 0;
}

