#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



void main(){
    setlocale(LC_ALL,"portuguese");

    int x;
    int *ponteiro;

    printf("\nDigite um número inteiro: ");
    fflush(stdin);
    scanf("%d",&x);

    ponteiro=&x;

    printf("\nPonterio: %d\n",*ponteiro);

    *ponteiro=*ponteiro/10;

    printf("\nValor de X: %d\n",x);


}
