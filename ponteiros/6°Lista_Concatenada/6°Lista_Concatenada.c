#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

    struct lista{
        int valor;
        struct lista *proximo;
    };

void main()
{
    setlocale(LC_ALL,"portuguese");

    struct lista m1, m2, m3;
    struct lista *gancho = &m1;

    m1.valor =10;
    m2.valor =20;
    m3.valor =30;

    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = (struct lista *)0;

    //Obs: Funciona com NULL ou ZERO também
    while(gancho != (struct lista *)0){

        printf("\n%i\n",gancho->valor);
        gancho = gancho->proximo;
    }

}
