#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){

    setlocale(LC_ALL,"portuguese");

    int i=0,j=0;
    int *p_1,*p_2,**p_p_1,**p_p_2;

    i=4;
    j=5;

    p_1=&i;
    p_2=&j;
    p_p_1=&p_2;
    p_p_2=&p_1;

    printf("\nvalor de i = %d, Endereço = %d\nValor de j = %d, Endereço = %d\nPonteiro P_1 = %d, Endereço = %d\nPonteiro P_2 = %d, Endereço = %d\nPonteiro P_P_1 = %d, Endereço = %d\nPonteiro P_P_2 = %d, Endereço = %d\n",i,&i,j,&j,*p_1,p_1,*p_2,p_2,**p_p_1,p_p_1,**p_p_2,p_p_2);


}
