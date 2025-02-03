#include <stdio.h>
#include <stdlib.h>

//A terceira solução possível para alocar um array com mais de uma dimensão e manter
//a notação de colchetes para cada dimensão é um misto das duas soluções anteriores:
//simulamos um array bidimensional (ou com mais dimensões) utilizando:

//•• Um array unidimensional alocado dinamicamente e contendo as posições de
//todos os elementos.
//•• Um array de ponteiros unidimensional que simulará as dimensões e, assim,
//manterá a notação de colchetes.
//O exemplo abaixo exemplifica como simular uma matriz utilizando um
//array de ponteiros e um array unidimensional contendo os dados.

//utilizando aritmética de ponteiros, associamos cada posição do array de
//ponteiros para uma porção do array de inteiros:
///p[i] = v + i * Ncolunas;

int main()
{

    int *v; //1 “*” = 1 nível = 1 dimensão
    int **p; //2 “*” = 2 níveis = 2 dimensões
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

//Nesse exemplo, utilizando um ponteiro com um nível (int *v), alocamos o total de
//elementos da matriz (Nlinhas * Ncolunas). Essa tarefa é realizada pela primeira chamada
//da função malloc(), a qual aloca o array usando o tamanho de um tipo int:
///sizeof(int)

//Em seguida, utilizando um ponteiro com dois níveis (int **p), alocamos no primeiro
//nível do ponteiro um array de ponteiros representando as linhas da matriz.
//Essa tarefa é realizada pela primeira chamada da função malloc(), a qual aloca o array
//usando o tamanho de um ponteiro para int:
///sizeof(int *)

//Do ponto de vista de alocação, essa solução é mais simples do que a anterior (solução
//2). Ela utiliza apenas duas chamadas da função malloc() para alocar toda a matriz.
//Consequentemente, apenas duas chamadas da função free() são necessárias para liberar
//a memória alocada.
//Por outro lado, para arrays com mais de duas dimensões, essa solução pode se mostrar
//mais complicada de se trabalhar, já que envolve aritmética de ponteiros no cálculo
//que associa as linhas com o array contendo os dados.

    system("pause");
    return 0;
}

