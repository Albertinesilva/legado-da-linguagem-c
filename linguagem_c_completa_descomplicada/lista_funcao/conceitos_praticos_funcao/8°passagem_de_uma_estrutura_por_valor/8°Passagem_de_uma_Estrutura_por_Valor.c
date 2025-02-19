#include <stdio.h>
#include <stdlib.h>

//Para passar uma estrutura como par�metro de uma fun��o, basta declarar na lista
//de par�metros um par�metro com o mesmo tipo da estrutura. Dessa forma, teremos
//acesso a todos os campos da estrutura dentro da fun��o, como mostra o exemplo:

struct ponto
{
    int x, y;
};

void imprime(struct ponto p)
{
    printf("x = %d\n",p.x);
    printf("y = %d\n",p.y);
}

int main()
{
    struct ponto p1 = {10,20};
    imprime(p1);

    system("pause");
    return 0;
}
