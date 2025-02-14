#include <stdio.h>
#include <stdlib.h>

//As operações aritméticas não funcionam em ponteiros genéricos da mesma forma
//como em ponteiros de tipos definidos. Elas são sempre realizadas com base em uma
//unidade de memória (1 byte).

//Nesse exemplo, como o compilador não sabe qual o tipo do ponteiro genérico, nas
//operações de adição e subtração é adicionado/subtraído um total de 1 byte por incremento/
//decremento, pois esse é o tamanho de uma unidade de memória. Portanto, se o
//endereço guardado for, por exemplo, de um inteiro, o incremento de uma posição no
//ponteiro genérico (1 byte) não levará ao próximo inteiro (4 bytes).

int main()
{
    void *p = 0x5DC;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);
//Incrementa p em uma posição
    p++;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);
//Incrementa p em 15 posições
    p = p + 15;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);
//Decrementa p em 2 posições
    p = p - 2;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);

    system("pause");
    return 0;
}
