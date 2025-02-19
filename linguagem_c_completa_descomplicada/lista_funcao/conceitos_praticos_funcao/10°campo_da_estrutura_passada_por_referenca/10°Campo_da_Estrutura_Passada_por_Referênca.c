#include <stdio.h>
#include <stdlib.h>

//Passagem de um campo da estrutura por refer�ncia
//Como visto anteriormente, podemos passar um �nico campo da estrutura por valor
//para a fun��o. Isso significa que tamb�m podemos passar esse mesmo campo por
//refer�ncia. Nesse caso, o par�metro da fun��o dever� novamente ser compat�vel com
//o campo da fun��o que ser� passado como par�metro, adicionado do operador �*�,
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
