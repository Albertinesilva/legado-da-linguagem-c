#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Na passagem de um array como parâmetro de uma função podemos declarar a
função usando uma das maneiras mostradas a seguir, todas equivalentes:

void imprime (int *m, int n);
void imprime (int m[], int n);
void imprime (int m[5], int n);

Mesmo especificando o tamanho de um array no seu parâmetro da função, a semântica
é a mesma das outras declarações, pois não existe checagem dos limites do array em
tempo de compilação.*/

void imprime(int *n,int m)
{
    int i;
    for (i=0; i<m; i++)
        printf("%d \n",n[i]);

        n[0]=10;
}
int main()
{
    setlocale(LC_ALL,"portuguese");

    int v[5] = {1,2,3,4,5};
    imprime(v,5);
    printf("1° Posição do vetor modificada = %d\n",v[0]);
    system("pause");
    return 0;
}
