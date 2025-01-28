#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){
setlocale(LC_ALL,"portuguese");

int multiplo;

printf("Informe um número multiplo de três: ");
fflush(stdin);
scanf("%i",&multiplo);

if(multiplo%3==0){
    printf("\nO número %i é multiplo de TRÊS\n ",multiplo);

    }else{
    printf("\nO número %i não e multiplo de TRÊs \n",multiplo);

}


}
