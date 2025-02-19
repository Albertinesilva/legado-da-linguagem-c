#include <stdio.h>
#include <stdlib.h>

//As notações a seguir funcionam para arrays com mais de uma dimensão. Mas o
//array é tratado como se tivesse apenas uma dimensão dentro da função

//void imprime (int *m, int n);
//void imprime (int m[], int n);

//O exemplo da Figura 9.17 mostra como um array de duas dimensões pode ser passado
//como um array de uma única dimensão para uma função.

//Note que, nesse exemplo, em vez de passarmos o nome do array, passamos o endereço
//do primeiro elemento (&mat[0][0]). Isso faz com que percamos a notação de dois
//colchetes para a matriz e ela seja tratada como se tivesse apenas uma dimensão.

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
