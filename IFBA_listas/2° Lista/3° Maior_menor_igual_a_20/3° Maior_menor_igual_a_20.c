#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");


int num;

printf("Informe um número: ");
scanf("%i",&num);

if (num > 20){
    printf("\nO número %i é maior que 20\n",num);

    }else{

if (num < 20){
    printf("\nO número %i é menor que 20\n",num);

    }else{
    printf("\nO número %i é igual a 20\n",num);

        }
    }

}
