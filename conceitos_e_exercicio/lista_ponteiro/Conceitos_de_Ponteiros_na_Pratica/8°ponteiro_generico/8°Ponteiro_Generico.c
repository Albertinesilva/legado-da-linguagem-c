#include <stdio.h>
#include <stdlib.h>

//Um ponteiro gen�rico � um ponteiro que pode apontar para qualquer tipo de dado,
//inclusive para outro ponteiro.

int main()
{
    void *pp;
    int *p1, p2 = 10;
    p1 = &p2;
//recebe o endere�o de um inteiro
    pp = &p2;
    printf("Endereco em pp: %p \n",pp);
//recebe o endere�o de um ponteiro para inteiro
    pp = &p1;
    printf("Endereco em pp: %p \n",pp);
//recebe o endere�o guardado em p1 (endere�o de p2)
    pp = p1;
    printf("Endereco em pp: %p \n",pp);

    system("pause");
    return 0;
}
