#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

float nota1,nota2,media;


printf("Digite a sua primeira nota: ");
fflush(stdin);
scanf("%f",&nota1);

printf("Digite a segunda nota: ");
fflush(stdin);
scanf("%f",&nota2);

media = (nota1 + nota2)/2;

if(media >=7){
printf("---------------------------------------\n");
printf("MEUS PARABÉNS! A sua média final foi %.2f\n",media);
printf("---------------------------------------\n");

}
if(media < 7){
printf("------------------------------\n");
printf("Sua média final foi %.1f \n",media);
printf("------------------------------\n");
}

}
