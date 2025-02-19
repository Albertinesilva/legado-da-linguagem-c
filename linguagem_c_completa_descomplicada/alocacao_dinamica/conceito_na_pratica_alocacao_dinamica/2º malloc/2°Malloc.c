#include <stdio.h>
#include <stdlib.h>

//A fun��o malloc() serve para alocar mem�ria durante a execu��o do programa. �
//ela que faz o pedido de mem�ria ao computador e retorna um ponteiro com o endere�o
//do in�cio do espa�o de mem�ria alocado. A fun��o malloc() possui o seguinte prot�tipo:

//void *malloc (unsigned int num);

//A fun��o malloc() recebe um par�metro de entrada num:
//o tamanho do espa�o de mem�ria a ser alocado. e retorna NULL: no caso de erro;
//O ponteiro para a primeira posi��o do array alocado.

//Note que a fun��o malloc() retorna um ponteiro gen�rico (void*). Esse ponteiro pode
//ser atribu�do a qualquer tipo de ponteiro via type cast.
//Existe uma raz�o para a fun��o malloc() retornar um ponteiro gen�rico (void*): ela
//n�o sabe o que vamos fazer com a mem�ria alocada.

int main()
{
    int *p;
    p = (int *) malloc(5*sizeof(int));

    for (int i=0; i<5; i++)
    {
        printf("Digite o valor da posicao %d: ",i);
        scanf("%d",&p[i]);
    }
    printf("\n");
    for (int y=0; y<5; y++)
    {
        printf("%d,",p[y]);

    }
    printf("\n\n");

//Nesse exemplo:
//�� estamos alocando um array contendo cinco posi��es de inteiros: 5*sizeof(int);
//�� a fun��o sizeof(int) retorna 4 (n�mero de bytes do tipo int na mem�ria). Portanto,
//s�o alocados 20 bytes (50 * 4 bytes);
//�� a fun��o malloc() retorna um ponteiro gen�rico, o qual � convertido no tipo de
//ponteiro via type cast: (int*);
//�� o ponteiro p passa a ser tratado como um array: p[i].
//Se n�o houver mem�ria suficiente para alocar a mem�ria requisitada, a fun��o malloc()
//retorna um ponteiro nulo.

    int *p1;
    p1 = (int *) malloc(5*sizeof(int));
    if(p1 == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");
        system("pause");
        exit(1);
    }
    for (int i=0; i<5; i++)
    {
        printf("Digite o valor da posicao %d: ",i);
        scanf("%d",&p1[i]);
    }
    printf("\n\n");

//� importante sempre testar se foi poss�vel fazer a aloca��o de mem�ria. A fun��o
//malloc() retorna um ponteiro NULL para indicar que n�o h� mem�ria dispon�vel no
//computador ou que ocorreu algum outro erro que impediu a mem�ria de ser alocada.
//No momento da aloca��o da mem�ria, deve-se levar em conta o tamanho do dado alocado.

//Lembre-se: no momento da aloca��o da mem�ria, deve-se levar em conta o tamanho
//do dado alocado. Alocar 1.000 bytes de mem�ria equivale a um n�mero de
//elementos diferente, dependendo do tipo do elemento:
//�� Bytes para char: um array de 1.000 posi��es de caracteres.
//�� Bytes para int: um array de 250 posi��es de inteiros.

    char*p2;
//aloca espa�o para 1.000 chars
    p2 = (char *) malloc(1000);
    int *p3;
//aloca espa�o para 250 inteiros
    p3 = (int *) malloc(1000);
    system("pause");
    return 0;
}
