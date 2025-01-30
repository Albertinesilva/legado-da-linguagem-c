#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

int num;

printf("Digite um valor: ");
fflush(stdin);
scanf("%d",&num);

if(num%2==0){
    printf("\nO valor %i é PAR",num);
}else{
    printf("\nO valor %i é ÍMPAR",num);

}
printf("\nACABOU!\n");

}
