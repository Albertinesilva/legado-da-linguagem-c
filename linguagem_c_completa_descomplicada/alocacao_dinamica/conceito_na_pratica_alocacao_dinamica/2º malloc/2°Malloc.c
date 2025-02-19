#include <stdio.h>
#include <stdlib.h>

//A função malloc() serve para alocar memória durante a execução do programa. É
//ela que faz o pedido de memória ao computador e retorna um ponteiro com o endereço
//do início do espaço de memória alocado. A função malloc() possui o seguinte protótipo:

//void *malloc (unsigned int num);

//A função malloc() recebe um parâmetro de entrada num:
//o tamanho do espaço de memória a ser alocado. e retorna NULL: no caso de erro;
//O ponteiro para a primeira posição do array alocado.

//Note que a função malloc() retorna um ponteiro genérico (void*). Esse ponteiro pode
//ser atribuído a qualquer tipo de ponteiro via type cast.
//Existe uma razão para a função malloc() retornar um ponteiro genérico (void*): ela
//não sabe o que vamos fazer com a memória alocada.

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
//•• estamos alocando um array contendo cinco posições de inteiros: 5*sizeof(int);
//•• a função sizeof(int) retorna 4 (número de bytes do tipo int na memória). Portanto,
//são alocados 20 bytes (50 * 4 bytes);
//•• a função malloc() retorna um ponteiro genérico, o qual é convertido no tipo de
//ponteiro via type cast: (int*);
//•• o ponteiro p passa a ser tratado como um array: p[i].
//Se não houver memória suficiente para alocar a memória requisitada, a função malloc()
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

//É importante sempre testar se foi possível fazer a alocação de memória. A função
//malloc() retorna um ponteiro NULL para indicar que não há memória disponível no
//computador ou que ocorreu algum outro erro que impediu a memória de ser alocada.
//No momento da alocação da memória, deve-se levar em conta o tamanho do dado alocado.

//Lembre-se: no momento da alocação da memória, deve-se levar em conta o tamanho
//do dado alocado. Alocar 1.000 bytes de memória equivale a um número de
//elementos diferente, dependendo do tipo do elemento:
//•• Bytes para char: um array de 1.000 posições de caracteres.
//•• Bytes para int: um array de 250 posições de inteiros.

    char*p2;
//aloca espaço para 1.000 chars
    p2 = (char *) malloc(1000);
    int *p3;
//aloca espaço para 250 inteiros
    p3 = (int *) malloc(1000);
    system("pause");
    return 0;
}
