#include <stdio.h>
#include <stdlib.h>

//A linguagem C não suporta a atribuição de um array para outro. Por
//esse motivo, não se pode ter um array como retorno de uma função.
//É possível retornar um array indiretamente, desde que ele faça parte de uma estrutura.

//A linguagem C não suporta a atribuição de um array para outro, mas permite a
//atribuição entre estruturas. Isto faz com que os conteúdos das variáveis contidas dentro
//de uma estrutura sejam copiados para outra. Desse modo, é possível retornar um array
//desde que ele esteja dentro de uma estrutura.

struct vetor
{
    int v[5];
};
struct vetor retorna_array()
{
    struct vetor v = {1,2,3,4,5};
    return v;
}
int main()
{
    int i;
    struct vetor vet = retorna_array();
    for (i=0; i<5; i++)
        printf("Valores: %d \n",vet.v[i]);

    system("pause");
    return 0;
}
