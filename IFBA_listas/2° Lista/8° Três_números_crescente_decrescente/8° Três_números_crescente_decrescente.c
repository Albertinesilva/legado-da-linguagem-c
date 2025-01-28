#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

int num1,num2,num3,aux;


printf("Informe o 1° número: ");
scanf("%i",&num1);

printf("\nInforme o 2° número: ");
scanf("%i",&num2);

printf("\nInforme o 3° número: ");
scanf("%i",&num3);


if(num1 > num2){
    aux = num1;
    num1 = num2;
    num2 = aux;
}
        if(num1 > num3){
            aux = num1;
            num1 = num3;
            num3 = aux;
        }
            if(num2 > num3){
                aux = num2;
                num2 = num3;
                num3 = aux;
            }


printf("\n-----------------------------------ORDEM CRESCENTE-----------------------------------\n");

printf("\nOrdem crescente: %i - %i - %i\n",num1,num2,num3);

printf("\n-----------------------------------ORDEM DECRESCENTE----------------------------------\n");

printf("\nOrdem decrescente: %i - %i - %i\n",num3,num2,num1);


}
