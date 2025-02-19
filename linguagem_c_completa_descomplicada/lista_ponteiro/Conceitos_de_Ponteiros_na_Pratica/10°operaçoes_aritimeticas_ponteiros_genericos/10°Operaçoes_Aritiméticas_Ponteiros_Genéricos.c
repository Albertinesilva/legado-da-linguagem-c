#include <stdio.h>
#include <stdlib.h>

//As opera��es aritm�ticas n�o funcionam em ponteiros gen�ricos da mesma forma
//como em ponteiros de tipos definidos. Elas s�o sempre realizadas com base em uma
//unidade de mem�ria (1 byte).

//Nesse exemplo, como o compilador n�o sabe qual o tipo do ponteiro gen�rico, nas
//opera��es de adi��o e subtra��o � adicionado/subtra�do um total de 1 byte por incremento/
//decremento, pois esse � o tamanho de uma unidade de mem�ria. Portanto, se o
//endere�o guardado for, por exemplo, de um inteiro, o incremento de uma posi��o no
//ponteiro gen�rico (1 byte) n�o levar� ao pr�ximo inteiro (4 bytes).

int main()
{
    void *p = 0x5DC;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);
//Incrementa p em uma posi��o
    p++;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);
//Incrementa p em 15 posi��es
    p = p + 15;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);
//Decrementa p em 2 posi��es
    p = p - 2;
    printf("p = Hexadecimal: %p Decimal: %d \n",p,p);

    system("pause");
    return 0;
}
