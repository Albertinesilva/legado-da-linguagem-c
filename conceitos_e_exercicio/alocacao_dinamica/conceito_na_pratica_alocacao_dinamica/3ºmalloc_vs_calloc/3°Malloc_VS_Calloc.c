#include <stdio.h>
#include <stdlib.h>

//Assim como a função malloc(), a função calloc() também serve para alocar memória
//durante a execução do programa. É ela que faz o pedido de memória ao computador
//e retorna um ponteiro com o endereço do início do espaço de memória alocado. A
//função malloc() possui o seguinte protótipo:
///void *calloc (unsigned int num, unsigned int size);

//A função malloc() recebe dois parâmetros de entrada:
//•• num: o número de elementos no array a ser alocado.
//•• size: o tamanho de cada elemento do array.

//E retorna:
//•• NULL: no caso de erro.
//•• O ponteiro para a primeira posição do array alocado.

//Basicamente, a função calloc() faz o mesmo que a função malloc(). A diferença é
//que agora passamos os valores da quantidade de elementos alocados e do tipo de dado
//alocado como parâmetros distintos da função.


int main()
{
//alocação com malloc
    int *p;
    p = (int *) malloc(50*sizeof(int));
    if(p == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");
    }
//alocação com calloc
    int *p1;
    p1 = (int *) calloc(50,sizeof(int));
    if(p1 == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");
    }

//Note que, enquanto a função malloc() multiplica o total de elementos do array
//pelo tamanho de cada elemento, a função calloc() recebe os dois valores como parâmetros
//distintos.

//Existe outra diferença entre a função calloc() e a função malloc(): ambas servem para
//alocar memória, mas a função calloc() inicializa todos os BITS do espaço alocado com 0s.

    int *p2, *p3;
    p2 = (int *) malloc(5*sizeof(int));
    p3 = (int *) calloc(5,sizeof(int));
    printf("calloc \t\t malloc\n");
    for (int i=0; i<5; i++)
        printf("p2[%d]=%d\tp3[%d] = %d\n",i,p2[i],i,p3[i]);

    system("pause");
    return 0;
}
