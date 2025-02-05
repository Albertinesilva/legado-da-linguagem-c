#include <stdio.h>
#include <stdlib.h>

//A função realloc() recebe dois parâmetros de entrada:
//•• Um ponteiro para um bloco de memória previamente alocado.
//•• num: o tamanho em bytes do espaço de memória a ser alocado.
///E retorna:
//•• NULL: no caso de erro.
//•• O ponteiro para a primeira posição do array alocado/realocado.

//Basicamente, a função realloc() modifica o tamanho da memória previamente alocada
//e apontada pelo ponteiro ptr para um novo valor especificado por num, sendo
//num o tamanho em bytes do bloco de memória solicitado (igual à função malloc()).

//O novo valor de memória alocada (num) pode ser maior ou menor do que o tamanho
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
//A função realloc() retorna um ponteiro (void *) para o novo bloco alocado. Isso é
//necessário porque a função realloc() pode precisar mover o bloco antigo para aumentar
//seu tamanho. Se isso ocorrer, o conteúdo do bloco antigo é copiado para o novo
//bloco e nenhuma informação é perdida.
//Se o novo tamanho é maior, o valor do bloco de memória recém-alocado é
//indeterminado.

//Isso ocorre porque a função realloc() se comporta como a função malloc(). Ela não
//se preocupa em inicializar o espaço alocado.
//Se o ponteiro para o bloco de memória previamente alocado for NULL, a função realloc()
//alocará memória da mesma forma que a função malloc() faz.

//Se não houver memória suficiente para a realocação, um ponteiro nulo é devolvido
//e o bloco original é deixado inalterado.

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
