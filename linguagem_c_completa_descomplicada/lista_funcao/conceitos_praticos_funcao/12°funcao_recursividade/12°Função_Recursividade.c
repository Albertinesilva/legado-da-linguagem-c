#include <stdio.h>
#include <stdlib.h>

//Todo cuidado é pouco ao se fazerem funções recursivas, pois duas coisas devem ficar
//bem estabelecidas: o critério de parada e o parâmetro da chamada recursiva.

///Durante a implementação de uma função recursiva temos de ter em mente duas
///coisas: o critério de parada e o parâmetro da chamada recursiva:
///•• Critério de parada: determina quando a função deve parar de chamar a si mesma.
///Se ele não existir, a função continuará executando até esgotar a memória do
///computador. No cálculo de fatorial, o critério de parada ocorre quando tentamos
///calcular o fatorial de zero: 0! = 1.
///•• Parâmetro da chamada recursiva: quando chamamos a função dentro dela mesma,
///devemos sempre mudar o valor do parâmetro passado, de forma que a recursão
///chegue a um término. Se o valor do parâmetro for sempre o mesmo, a função
///continuará executando até esgotar a memória do computador. No cálculo de fatorial,
///a mudança no parâmetro da chamada recursiva ocorre quando definimos o
///fatorial de N em termos no fatorial de (N − 1): N! = N * (N − 1)!.

//int fatorial (int n){
//if(n == 0) //critério de parada
//return 1;
//else //parâmetro do fatorial sempre muda
//return n*fatorial(n – 1);
//}

int fatorial (int n)
{
    if(n == 0)
        return 1;
    else
        return n*fatorial(n-1);
}
int main()
{
    int x;
    int y;

    x = fatorial(4);
    printf("4! = %d\n",x);

    system("pause");
    return 0;
}
