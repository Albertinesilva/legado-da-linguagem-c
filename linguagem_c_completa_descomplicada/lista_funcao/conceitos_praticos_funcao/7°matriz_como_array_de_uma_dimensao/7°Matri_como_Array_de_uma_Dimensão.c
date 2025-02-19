#include <stdio.h>
#include <stdlib.h>

//As nota��es a seguir funcionam para arrays com mais de uma dimens�o. Mas o
//array � tratado como se tivesse apenas uma dimens�o dentro da fun��o

//void imprime (int *m, int n);
//void imprime (int m[], int n);

//O exemplo da Figura 9.17 mostra como um array de duas dimens�es pode ser passado
//como um array de uma �nica dimens�o para uma fun��o.

//Note que, nesse exemplo, em vez de passarmos o nome do array, passamos o endere�o
//do primeiro elemento (&mat[0][0]). Isso faz com que percamos a nota��o de dois
//colchetes para a matriz e ela seja tratada como se tivesse apenas uma dimens�o.

void imprime_matriz(int *m,int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d \n", m[i]);
}
int main()
{
    int mat[3][2] = {{1,2},{3,4},{5,6}};
    imprime_matriz(&mat[0][0],6);

    system("pause");
    return 0;
}
