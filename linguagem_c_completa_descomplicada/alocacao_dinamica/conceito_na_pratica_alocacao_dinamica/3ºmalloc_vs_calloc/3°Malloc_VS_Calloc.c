#include <stdio.h>
#include <stdlib.h>

//Assim como a fun��o malloc(), a fun��o calloc() tamb�m serve para alocar mem�ria
//durante a execu��o do programa. � ela que faz o pedido de mem�ria ao computador
//e retorna um ponteiro com o endere�o do in�cio do espa�o de mem�ria alocado. A
//fun��o malloc() possui o seguinte prot�tipo:
///void *calloc (unsigned int num, unsigned int size);

//A fun��o malloc() recebe dois par�metros de entrada:
//�� num: o n�mero de elementos no array a ser alocado.
//�� size: o tamanho de cada elemento do array.

//E retorna:
//�� NULL: no caso de erro.
//�� O ponteiro para a primeira posi��o do array alocado.

//Basicamente, a fun��o calloc() faz o mesmo que a fun��o malloc(). A diferen�a �
//que agora passamos os valores da quantidade de elementos alocados e do tipo de dado
//alocado como par�metros distintos da fun��o.


int main()
{
//aloca��o com malloc
    int *p;
    p = (int *) malloc(50*sizeof(int));
    if(p == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");
    }
//aloca��o com calloc
    int *p1;
    p1 = (int *) calloc(50,sizeof(int));
    if(p1 == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");
    }

//Note que, enquanto a fun��o malloc() multiplica o total de elementos do array
//pelo tamanho de cada elemento, a fun��o calloc() recebe os dois valores como par�metros
//distintos.

//Existe outra diferen�a entre a fun��o calloc() e a fun��o malloc(): ambas servem para
//alocar mem�ria, mas a fun��o calloc() inicializa todos os BITS do espa�o alocado com 0s.

    int *p2, *p3;
    p2 = (int *) malloc(5*sizeof(int));
    p3 = (int *) calloc(5,sizeof(int));
    printf("calloc \t\t malloc\n");
    for (int i=0; i<5; i++)
        printf("p2[%d]=%d\tp3[%d] = %d\n",i,p2[i],i,p3[i]);

    system("pause");
    return 0;
}
