#include <stdio.h>
#include <stdlib.h>

//Na passagem de uma variável por referência é necessário usar o operador “*” sempre
//que se desejar acessar o conteúdo da variável dentro da função.

//Nesse exemplo, no momento em que a função soma_mais_um é chamada, o endereço
//de x (&x) é copiado para o parâmetro n da função. O parâmetro n é um ponteiro
//dentro da função que guarda o endereço de onde o valor de x está guardado fora da
//função. Sempre que alteramos o valor de *n (conteúdo da posição de memória guardada,
//ou seja, x), o valor de x fora da função também é modificado.

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
    /*Saída
    Antes da funcao: x = 5
    Dentro da funcao: x = 6
    Depois da funcao: x = 6*/
}
