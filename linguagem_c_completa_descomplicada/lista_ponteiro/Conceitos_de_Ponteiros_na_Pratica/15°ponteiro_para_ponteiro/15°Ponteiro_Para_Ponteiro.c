#include <stdio.h>
#include <stdlib.h>

/*A linguagem C permite criar ponteiros com diferentes níveis de apontamento, isto é,
ponteiros que apontam para outros ponteiros.
Em linguagem C, a declaração de um ponteiro para ponteiro criado pelo programador
segue esta forma geral:
tipo_do_ponteiro **nome_do_ponteiro;
Note que agora usamos dois asteriscos (*) para informar ao compilador que aquela
variável não vai guardar um valor, mas sim um endereço de memória para outro endereço
de memória para aquele tipo especificado.*/

int main()
{
    int x = 10;
    int *p = &x;
    int **p2 = &p;
//Endereço em p2
    printf("Endereco em p2: %p\n",p2);
//Conteudo do endereço
    printf("Conteudo em *p2: %p\n",*p2);
//Conteudo do endereço do endereço
    printf("Conteudo em **p2: %d\n",**p2);

    system("pause");
    return 0;
}
