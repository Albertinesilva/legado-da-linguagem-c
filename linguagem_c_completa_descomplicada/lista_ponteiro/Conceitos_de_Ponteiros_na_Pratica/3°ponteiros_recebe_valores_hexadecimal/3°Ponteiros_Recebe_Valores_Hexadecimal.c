#include <stdio.h>
#include <stdlib.h>
int main()
{
//Endere�o hexadecimal da porta serial
    int *p = 0x3F8;
//O valor em decimal � convertido para seu valor
//haxadecimal: 0x5DC
    int *p1 = 1500;
    printf("Endereco em p: %p \n",p);
    printf("Endereco em p1: %p \n",p1);
    system("pause");

    /*Sa�da: Endereco em p: 000003F8
             Endereco em p1: 000005DC*/

    return 0;
}
