#include <stdio.h>
#include <stdlib.h>

//Passagem de um campo da estrutura por referência
//Como visto anteriormente, podemos passar um único campo da estrutura por valor
//para a função. Isso significa que também podemos passar esse mesmo campo por
//referência. Nesse caso, o parâmetro da função deverá novamente ser compatível com
//o campo da função que será passado como parâmetro, adicionado do operador “*”,
//como mostra o exemplo:

struct ponto
{
    int x, y;
};

void soma_imprime_valor(int *n)
{
    *n = *n + 1;
    printf("Valor = %d\n",*n);
}
int main()
{

    struct ponto p1 = {10,20};
    soma_imprime_valor(&p1.x);
    soma_imprime_valor(&p1.y);

    system("pause");
    return 0;
}
