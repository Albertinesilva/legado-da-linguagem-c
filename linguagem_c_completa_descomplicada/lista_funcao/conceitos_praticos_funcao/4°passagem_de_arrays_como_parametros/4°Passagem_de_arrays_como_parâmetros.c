#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Na passagem de um array como par�metro de uma fun��o podemos declarar a
fun��o usando uma das maneiras mostradas a seguir, todas equivalentes:

void imprime (int *m, int n);
void imprime (int m[], int n);
void imprime (int m[5], int n);

Mesmo especificando o tamanho de um array no seu par�metro da fun��o, a sem�ntica
� a mesma das outras declara��es, pois n�o existe checagem dos limites do array em
tempo de compila��o.*/

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
    printf("1� Posi��o do vetor modificada = %d\n",v[0]);
    system("pause");
    return 0;
}
