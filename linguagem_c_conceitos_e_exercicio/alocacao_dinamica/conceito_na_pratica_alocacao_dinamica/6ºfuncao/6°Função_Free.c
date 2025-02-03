#include <stdio.h>
#include <stdlib.h>

///Diferentemente das variáveis declaradas durante o desenvolvimento do programa,
///as variáveis alocadas dinamicamente não são liberadas automaticamente por ele.

//Sempre que alocamos memória de forma dinâmica (malloc(), calloc() ou realloc()), é
//necessário liberar essa memória quando ela não for mais necessária.

//novamente disponível para futuras alocações. Para liberar um bloco de memória previamente
//alocado utilizamos a função free(), cujo protótipo é:

///void free (void *p);

///A função free() recebe apenas um parâmetro de entrada: o ponteiro para o início
///do bloco de memória alocado.

//Para liberar a memória alocada, basta passar para o parâmetro da função free() o
//ponteiro que aponta para o início do bloco de memória alocado.

//Como o programa sabe quantos bytes devem ser liberados? Quando se aloca a memória,
//o programa guarda o número de bytes alocados numa “tabela de alocação” interna.

int main()
{
    int *p,i;
    p = (int *) malloc(50*sizeof(int));
    if(p == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");

        system("pause");
        exit(1);
    }
    for (i = 0; i < 50; i++)
    {
        p[i] = i+1;
    }
    for (i = 0; i < 50; i++)
    {
        printf("%d,",p[i]);
    }
//libera a memória alocada
    free(p);
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");


///Apenas libere a memória quando tiver certeza de que ela não será mais usada.
///Do contrário, um erro pode acontecer ou o programa poderá não funcionar como
///esperado.

    int *p1;
    p1 = (int *) malloc(50*sizeof(int));
    if(p1 == NULL)
    {
        printf("Erro: Memoria Insuficiente!\n");
        system("pause");
        exit(1);
    }
    for (int i = 0; i < 50; i++)
    {
        p1[i] = i+1;
    }
//libera a memória alocada
    free(p1);
//tenta imprimir o array
//cuja memória foi liberada
    for (int i = 0; i < 50; i++)
    {
        printf("%d,",p1[i]);
    }

//Nesse exemplo, nenhum erro ocorre porque a função free() apenas libera a memória.
//O ponteiro p continua com o endereço para onde ela estava reservada. Sendo
//assim, podemos tentar acessá-la. Como ela não nos pertence mais (foi liberada), não há
//garantias do que está guardado lá.

//Sempre libere a memória que não for mais utilizar.
//Além disso, convém não deixar ponteiros “soltos” (dangling pointers) no programa.
//Portanto, depois de chamar a função free(), atribua NULL ao ponteiro:
///free(p);
///p = NULL;

//É conveniente fazer isso porque ponteiros “soltos” podem ser explorados por hackers
//para atacar o seu computador.

    printf("\n\n");
    system("pause");
    return 0;
}

