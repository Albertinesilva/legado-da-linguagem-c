#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    void *ponteiro;
    int *p1,p2=10;
    p1=&p2;
    ponteiro=&p2;//Endereço de int p2
    printf("\nEndereço em ponteiro: %p\n",ponteiro);

    ponteiro=&p1;//Endereço de int* p1
    printf("\nEndereço em ponteiro: %p\n",ponteiro);

    ponteiro=p1;//Endereço de int
    printf("\nEndereço em ponteiro: %p\n",ponteiro);

    void *ponteiro2;
    int x=10;
    ponteiro2=&x;

    //Não pode vai dar ERRO.
    //printf("\nConteudo: %d\n",*ponteiro2);

    //Antes de acessar o conteúdo é preciso converter o ponteiro genérico para o
    //tipo de ponteiro com o qual se deseja trabalhar.
    printf("\nConteudo: %d\n",*(int*)ponteiro2);
}
