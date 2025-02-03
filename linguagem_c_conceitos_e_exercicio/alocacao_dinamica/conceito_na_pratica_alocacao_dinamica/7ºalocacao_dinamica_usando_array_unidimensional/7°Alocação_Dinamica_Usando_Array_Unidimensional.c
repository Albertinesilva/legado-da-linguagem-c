#include <stdio.h>
#include <stdlib.h>

//Apesar de terem o comportamento de estruturas com mais de uma dimensão, os
//dados dos arrays multidimensionais são armazenados linearmente na memória. É o
//uso dos colchetes que cria a impressão de estarmos trabalhando com mais de uma
//dimensão.

//Sendo assim, uma solução trivial é simular um array bidimensional (ou com mais
//dimensões) utilizando um único array unidimensional alocado dinamicamente.

//Podemos alocar um array de uma única dimensão e tratá-lo como se fosse uma matriz
//(duas dimensões).

///O maior inconveniente dessa abordagem é que temos que abandonar a notação de
///colchetes para indicar a segunda dimensão da matriz. Como só possuímos uma única
///dimensão, é preciso calcular o deslocamento no array para simular a segunda dimensão.
///Isso é feito somando o índice da coluna que se quer acessar ao produto do índice da linha
///que se quer acessar pelo número total de colunas da “matriz”: [i * Ncolunas + j].


//Ao simular uma matriz (duas dimensões) utilizando um array de uma única dimensão
//perdemos a notação de colchetes para indicar a segunda dimensão.

/*int *p;
int i, j, Nlinhas = 2, Ncolunas = 2;
p = (int *) malloc(Nlinhas * Ncolunas * sizeof(int));
for (i = 0; i < Nlinhas; i++){
for (j = 0; j < Ncolunas; j++){
p[i * Ncolunas + j] = i+j;//CORRETO
p[i][j] = i+j;//ERRADO
}
}
free(p);*/

int main()
{
    int *p;
    int i, j, Nlinhas = 3, Ncolunas = 3;
    p = (int *) malloc(Nlinhas * Ncolunas * sizeof(int));
    for (i = 1; i < Nlinhas; i++)
    {
        for (j = 1; j < Ncolunas; j++)
            p[i * Ncolunas + j] = i+j;
    }
    for (i = 1; i < Nlinhas; i++)
    {
        for (j = 1; j < Ncolunas; j++)
            printf("%d ",p[i * Ncolunas + j]);
        printf("\n");
    }
    free(p);

    system("pause”");
    return 0;
}
