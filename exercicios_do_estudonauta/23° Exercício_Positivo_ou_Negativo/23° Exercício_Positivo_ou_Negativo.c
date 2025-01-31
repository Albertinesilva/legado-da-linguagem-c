#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main (){
setlocale(LC_ALL,"portuguese");

int num;

printf("Me diga um número e eu te direi se");
printf("\nele é POSITIVO, NEGATIVO ou NULO.\n");

printf("\nDigite um número: ");
fflush(stdin);
scanf("%d",&num);

if (num > 0)
    printf("O valor %d digitado é POSSITIVO.\n",num);

 else  if (num < 0)
        printf("O valor %d digitado é NEGATIVO.\n",num);

     else  if (num == 0)
            printf("O valor %d digitado é NULO.\n",num);



}
