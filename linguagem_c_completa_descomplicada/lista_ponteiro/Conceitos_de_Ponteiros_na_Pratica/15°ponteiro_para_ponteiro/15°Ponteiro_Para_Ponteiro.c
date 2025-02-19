#include <stdio.h>
#include <stdlib.h>

/*A linguagem C permite criar ponteiros com diferentes n�veis de apontamento, isto �,
ponteiros que apontam para outros ponteiros.
Em linguagem C, a declara��o de um ponteiro para ponteiro criado pelo programador
segue esta forma geral:
tipo_do_ponteiro **nome_do_ponteiro;
Note que agora usamos dois asteriscos (*) para informar ao compilador que aquela
vari�vel n�o vai guardar um valor, mas sim um endere�o de mem�ria para outro endere�o
de mem�ria para aquele tipo especificado.*/

int main()
{
    int x = 10;
    int *p = &x;
    int **p2 = &p;
//Endere�o em p2
    printf("Endereco em p2: %p\n",p2);
//Conteudo do endere�o
    printf("Conteudo em *p2: %p\n",*p2);
//Conteudo do endere�o do endere�o
    printf("Conteudo em **p2: %d\n",**p2);

    system("pause");
    return 0;
}
