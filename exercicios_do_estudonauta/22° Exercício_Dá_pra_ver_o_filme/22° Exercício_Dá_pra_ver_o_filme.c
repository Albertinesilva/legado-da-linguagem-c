#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main(){
setlocale(LC_ALL,"portuguese");

time_t t;
struct tm *hora;
time (&t);
hora = localtime(&t);
int h = hora->tm_hour;

float dinheiro;
float preco = 20.00;
int inicio = 7;
//CABEÇALHO DO PROGRAMA
printf("=================CINEMA ESTUDONAUTA=================\n");
printf("HORARIO DO FILME: %iHS - PREÇO DO INGRESSO: R$%.2f\n",inicio,preco);
printf("----------------------------------------------------\n");
printf("Hora atual: %ih\n\n",h);

//ENTRADA DE DADOS
printf("Quanto dinheiro você tem? R$");
fflush(stdin);
scanf("%f",&dinheiro);

//VERIFICAÇÃO
if(h < inicio && dinheiro >=preco){
    printf("\nAgora são %ihs.\n",h);
    printf("Você consegue comprar o ingresso. Seja bem vindo(a)!\n");

}
else{
    printf("\nAgora são %ihs.\n",h);
    printf("Infelizmente não é possivel comprar o ingresso! Volte outro dia!\n");
}
}
