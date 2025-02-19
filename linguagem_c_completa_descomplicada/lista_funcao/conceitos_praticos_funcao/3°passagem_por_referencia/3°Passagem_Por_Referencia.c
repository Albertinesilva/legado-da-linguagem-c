#include <stdio.h>
#include <stdlib.h>

//Na passagem de uma vari�vel por refer�ncia � necess�rio usar o operador �*� sempre
//que se desejar acessar o conte�do da vari�vel dentro da fun��o.

//Nesse exemplo, no momento em que a fun��o soma_mais_um � chamada, o endere�o
//de x (&x) � copiado para o par�metro n da fun��o. O par�metro n � um ponteiro
//dentro da fun��o que guarda o endere�o de onde o valor de x est� guardado fora da
//fun��o. Sempre que alteramos o valor de *n (conte�do da posi��o de mem�ria guardada,
//ou seja, x), o valor de x fora da fun��o tamb�m � modificado.

void soma_mais_um(int *n)
{
    *n = *n + 1;
    printf("Dentro da funcao: x = %d\n",*n);
}
void Troca(int*a,int*b){
int temp;
temp = *a;
*a = *b;
*b = temp;
printf("Dentro: %d e %d\n",*a,*b);
}

int main()
{
    int x = 5;

    printf("Antes da funcao: x = %d\n",x);
    soma_mais_um(&x);

    printf("Depois da funcao: x = %d\n",x);


int z = 2;
int y = 3;
printf("\nAntes: %d e %d\n",z,y);

Troca(&z,&y);
printf("Depois: %d e %d\n",z,y);

    system("pause");
    return 0;
    /*Sa�da
    Antes da funcao: x = 5
    Dentro da funcao: x = 6
    Depois da funcao: x = 6*/
}
