#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main(){
setlocale(LC_ALL,"portuguese");

time_t t;
time (&t);
struct tm *data;
data = localtime (&t);
int ano,idade,alistamento,idade2;

printf("Atualmente estamos no ano de 2020.\n");

printf("Em que ano você nasceu? ");
fflush(stdin);
scanf("%d",&ano);

idade = data->tm_year + 1900 - ano;

if (idade > 18){
    alistamento = ano + 18;
    idade2  = data->tm_year + 1900 - alistamento;
    printf("\n-----------------------------------------------------\n");
    printf("Sua idade é %d anos.\n",idade);
    printf("Seu alistamento foi em %d. Já se passaram %d anos.\n",alistamento,idade2);
    printf("-------------------------------------------------------\n");

    }else{
    if (idade < 18){
        alistamento = ano + 18;
        idade2 = alistamento - (data->tm_year + 1900);
        printf("\n-----------------------------------------------------\n");
        printf("Sua idade é %d anos.\n",idade);
        printf("Seu alistamento será em %d. Ainda faltam %d anos.\n",alistamento,idade2);
        printf("-------------------------------------------------------\n");

     }else{
     if (idade == 18){
        alistamento = ano + 18;
        printf("\n-----------------------------------------------------\n");
        printf("Sua idade é %d anos.\n",idade);
        printf("Você completa %d anos exatamente em %d. Va se alistar!\n",idade,alistamento);
        printf("-------------------------------------------------------\n");

     }
     }
    }


}
