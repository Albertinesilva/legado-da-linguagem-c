#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main() {
setlocale(LC_ALL,"portuguese");

int num;

printf("Informe um número, para saber se é PAR, IMPAR OU ZERO: ");
scanf("%d",&num);

if(num == 0){
    printf("\nO número %i é ZERO: \n",num);

}
    else{if(num % 2==0){
        printf("\nO número %i é PAR: \n",num);
    }

        else{
        printf("\nO número %i é IMPAR: \n",num);
        }

    }


}
