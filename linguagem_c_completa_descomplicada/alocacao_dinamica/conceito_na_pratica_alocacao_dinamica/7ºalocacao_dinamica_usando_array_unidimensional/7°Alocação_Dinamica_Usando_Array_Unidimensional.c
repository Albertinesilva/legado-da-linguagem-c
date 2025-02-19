#include <stdio.h>
#include <stdlib.h>

//Apesar de terem o comportamento de estruturas com mais de uma dimens�o, os
//dados dos arrays multidimensionais s�o armazenados linearmente na mem�ria. � o
//uso dos colchetes que cria a impress�o de estarmos trabalhando com mais de uma
//dimens�o.

//Sendo assim, uma solu��o trivial � simular um array bidimensional (ou com mais
//dimens�es) utilizando um �nico array unidimensional alocado dinamicamente.

//Podemos alocar um array de uma �nica dimens�o e trat�-lo como se fosse uma matriz
//(duas dimens�es).

///O maior inconveniente dessa abordagem � que temos que abandonar a nota��o de
///colchetes para indicar a segunda dimens�o da matriz. Como s� possu�mos uma �nica
///dimens�o, � preciso calcular o deslocamento no array para simular a segunda dimens�o.
///Isso � feito somando o �ndice da coluna que se quer acessar ao produto do �ndice da linha
///que se quer acessar pelo n�mero total de colunas da �matriz�: [i * Ncolunas + j].


//Ao simular uma matriz (duas dimens�es) utilizando um array de uma �nica dimens�o
//perdemos a nota��o de colchetes para indicar a segunda dimens�o.

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

    system("pause�");
    return 0;
}
