#include <stdio.h>
#include <stdlib.h>

///Diferentemente das vari�veis declaradas durante o desenvolvimento do programa,
///as vari�veis alocadas dinamicamente n�o s�o liberadas automaticamente por ele.

//Sempre que alocamos mem�ria de forma din�mica (malloc(), calloc() ou realloc()), �
//necess�rio liberar essa mem�ria quando ela n�o for mais necess�ria.

//novamente dispon�vel para futuras aloca��es. Para liberar um bloco de mem�ria previamente
//alocado utilizamos a fun��o free(), cujo prot�tipo �:

///void free (void *p);

///A fun��o free() recebe apenas um par�metro de entrada: o ponteiro para o in�cio
///do bloco de mem�ria alocado.

//Para liberar a mem�ria alocada, basta passar para o par�metro da fun��o free() o
//ponteiro que aponta para o in�cio do bloco de mem�ria alocado.

//Como o programa sabe quantos bytes devem ser liberados? Quando se aloca a mem�ria,
//o programa guarda o n�mero de bytes alocados numa �tabela de aloca��o� interna.

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
//libera a mem�ria alocada
    free(p);
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");


///Apenas libere a mem�ria quando tiver certeza de que ela n�o ser� mais usada.
///Do contr�rio, um erro pode acontecer ou o programa poder� n�o funcionar como
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
//libera a mem�ria alocada
    free(p1);
//tenta imprimir o array
//cuja mem�ria foi liberada
    for (int i = 0; i < 50; i++)
    {
        printf("%d,",p1[i]);
    }

//Nesse exemplo, nenhum erro ocorre porque a fun��o free() apenas libera a mem�ria.
//O ponteiro p continua com o endere�o para onde ela estava reservada. Sendo
//assim, podemos tentar acess�-la. Como ela n�o nos pertence mais (foi liberada), n�o h�
//garantias do que est� guardado l�.

//Sempre libere a mem�ria que n�o for mais utilizar.
//Al�m disso, conv�m n�o deixar ponteiros �soltos� (dangling pointers) no programa.
//Portanto, depois de chamar a fun��o free(), atribua NULL ao ponteiro:
///free(p);
///p = NULL;

//� conveniente fazer isso porque ponteiros �soltos� podem ser explorados por hackers
//para atacar o seu computador.

    printf("\n\n");
    system("pause");
    return 0;
}

