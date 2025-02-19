#include <stdio.h>
#include <stdlib.h>

//Dependendo da aplica��o, pode ser que n�o seja necess�rio passar todos os valores
//da estrutura para a fun��o. Nesse caso, a fun��o � declarada sem levar em conta a estrutura
//nos seus par�metros. Mas � necess�rio que o par�metro da fun��o seja compat�vel
//com o campo da fun��o que ser� passado como par�metro, como mostra o exemplo

struct ponto
{
    int x, y;
};
void imprime_valor(int n)
{
    printf("Valor = %d\n",n);
}
int main()
{
    struct ponto p1 = {10,20};

    imprime_valor(p1.x);
    imprime_valor(p1.y);

    system("pause");
    return 0;
}
