#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

int num1,num2;

printf("Informe o primeiro número: ");
scanf("%i",&num1);

printf("Informe o segundo número: ");
scanf("%i",&num2);


if(num1 == num2){
    printf("\nO 1° número é igual ao 2° número\n");

}else{if(num1 > num2){
    printf("\nO 1° número %i é MAIOR que o 2° número %i\n",num1,num2);

}
    else{if(num2 > num1){
    printf("\nO 2° número %i é MAIOR que o 1° número %i\n",num2,num1);
    }
    }

    }
}
