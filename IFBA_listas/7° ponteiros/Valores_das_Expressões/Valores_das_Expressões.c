#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){

    setlocale(LC_ALL,"portuguese");

    int i=2;
    int j=5;

    int *p;
    int *x;

    p=&i;
    x=&j;

    printf("\nP = %d\nX = %d\n",*p,*x);
    printf("\nSOMA = %d\nMULTIPLICAÇÃO = %d\n",(*p+*x),(*p)*(*x));



}
