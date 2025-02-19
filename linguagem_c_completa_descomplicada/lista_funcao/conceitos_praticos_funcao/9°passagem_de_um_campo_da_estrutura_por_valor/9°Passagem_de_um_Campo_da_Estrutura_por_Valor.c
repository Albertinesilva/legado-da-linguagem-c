#include <stdio.h>
#include <stdlib.h>

//Dependendo da aplicação, pode ser que não seja necessário passar todos os valores
//da estrutura para a função. Nesse caso, a função é declarada sem levar em conta a estrutura
//nos seus parâmetros. Mas é necessário que o parâmetro da função seja compatível
//com o campo da função que será passado como parâmetro, como mostra o exemplo

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
