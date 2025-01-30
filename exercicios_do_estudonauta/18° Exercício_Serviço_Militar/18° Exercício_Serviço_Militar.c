#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main(){
setlocale(LC_ALL,"portuguese");

int idade,ano,nasceu;

time_t t;
time(&t);
struct tm *data;
data = localtime (&t);
ano = data->tm_year + 1900;

printf("Atualmete estamos no ano de %i.\n",ano);
printf("Em que ano você nasceu? ");
fflush(stdin);
scanf("%d",&nasceu);

idade = ano - nasceu;

if (idade >= 18){
    printf("\n----------------------------------------\n");
    printf("Sua idade atual é de %d anos.\n",idade);
    printf("Já fez 18 anos. Espero sinceramente que você tenha se alistado.\n");
}else{
    printf("\n----------------------------------------\n");
    printf("Sua idade atual é de %i anos.\n",idade);
    printf("Você ainda não tem 18 anos. Não pode se alistar\n");


}



}
