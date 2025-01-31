#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main (){
setlocale(LC_ALL,"portuguese");

int num1,num2;

printf("Me diga dois números e eu colocarei\n");
printf("Os dois em ordem crescente.\n");


printf("\nPrimeiro número: ");
fflush(stdin);
scanf("%d",&num1);

printf("Segundo número: ");
fflush(stdin);
scanf("%d",&num2);

if (num1 > num2){
    printf("Os números em ordem são %d e %d\n",num2,num1);
} else {if (num1 < num2)
    printf("Os números em ordem são %d e %d\n",num1,num2);

    }

}
