#include <stdio.h>
#include <stdlib.h>

//A fun��o realloc() recebe dois par�metros de entrada:
//�� Um ponteiro para um bloco de mem�ria previamente alocado.
//�� num: o tamanho em bytes do espa�o de mem�ria a ser alocado.
///E retorna:
//�� NULL: no caso de erro.
//�� O ponteiro para a primeira posi��o do array alocado/realocado.

//Basicamente, a fun��o realloc() modifica o tamanho da mem�ria previamente alocada
//e apontada pelo ponteiro ptr para um novo valor especificado por num, sendo
//num o tamanho em bytes do bloco de mem�ria solicitado (igual � fun��o malloc()).

//O novo valor de mem�ria alocada (num) pode ser maior ou menor do que o tamanho
//previamente alocado.

int main()
{

    int *p = malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = i+1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d,",p[i]);
    }
    printf("\n");
//Diminui o tamanho do array
    p = realloc(p,3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("%d,",p[i]);
    }
    printf("\n");
//Aumenta o tamanho do array
    p = realloc(p,10*sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d,",p[i]);
    }
    printf("\n\n");
//A fun��o realloc() retorna um ponteiro (void *) para o novo bloco alocado. Isso �
//necess�rio porque a fun��o realloc() pode precisar mover o bloco antigo para aumentar
//seu tamanho. Se isso ocorrer, o conte�do do bloco antigo � copiado para o novo
//bloco e nenhuma informa��o � perdida.
//Se o novo tamanho � maior, o valor do bloco de mem�ria rec�m-alocado �
//indeterminado.

//Isso ocorre porque a fun��o realloc() se comporta como a fun��o malloc(). Ela n�o
//se preocupa em inicializar o espa�o alocado.
//Se o ponteiro para o bloco de mem�ria previamente alocado for NULL, a fun��o realloc()
//alocar� mem�ria da mesma forma que a fun��o malloc() faz.

//Se n�o houver mem�ria suficiente para a realoca��o, um ponteiro nulo � devolvido
//e o bloco original � deixado inalterado.

    int *p1;
    p1 = (int *) realloc(NULL,5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p1[i] = i+1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d,",p1[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
