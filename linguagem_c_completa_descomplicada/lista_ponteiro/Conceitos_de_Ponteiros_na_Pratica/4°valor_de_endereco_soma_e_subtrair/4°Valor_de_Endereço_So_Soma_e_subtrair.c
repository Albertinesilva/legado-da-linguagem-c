#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p = 0x5DC;
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
