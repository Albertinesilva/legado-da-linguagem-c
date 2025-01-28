#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

int num1,num2;

printf("Informe o 1° número: ");
scanf("%i",&num1);

printf("Informe o 2° número: ");
scanf("%i",&num2);

if(num1 < num2){
    printf("\nA ordem cresecente é: %i, %i\n",num1,num2);
    }
    else{
    if(num1 > num2){
    printf("\nA ordem crescente é: %i, %i\n",num2,num1);
    }
    else{
    printf("\nO 1° número: %i é igual a 2° número: %i",num1,num2);
    }
    }


}


