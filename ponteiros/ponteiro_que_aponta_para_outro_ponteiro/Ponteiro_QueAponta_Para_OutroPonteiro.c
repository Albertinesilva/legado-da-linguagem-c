#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    /*A linguagem C permite criar ponteiros com diferentes
    niveis de apontamento: Ponteiros que apontam para outros ponteiros.*/

    int x = 10;
    int *p = &x;
    int **p2 = &p;

    //Endereço em p2
    printf("\np2: %d\n",p2);//&p

    //Conteudo de endereço
    printf("\n*p2: %d\n",*p2);//&x

    //Conteudo do endereço do endereço
    printf("\n**p2: %d\n",**p2);//x

    /*É a quantidade de asteriscos (*) na declaração do
    ponteiro que indica o número de níveis do ponteiro.*/

    //int x;
    //Ponteiro para int (1 nível)
    //int *p1;

    //Ponteiro para ponteiro de int (2 níveis)
    //int **p2;

    //Ponteiro para ponteiro para ponteiro de int (3 níveis)
    //int ***p3;

    /*Acessando o conteúdo de um ponteiro
    para ponteiro*/
    char letra = 'a';
    char *ponteiro1 = &letra;
    char **ponteiro2 = &ponteiro1;
    char ***ponteiro3 =&ponteiro2;

    printf("\n\nPonteiro1: %c\n",*ponteiro1);
    printf("\nPonteiro2: %c\n",**ponteiro2);
    printf("\nPonteiro3: %c\n",***ponteiro3);




}
