#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void main (){
setlocale(LC_ALL,"portuguese");

time_t t;
time (&t);
struct tm *data;
data = localtime (&t);

int idade,ano1,ano,dia,mes;
int hora,minu,seg ,semana;
char nome [20];
char estuda[10];

printf("-----------------------ISOLAMENTO TOTAL---------------------------------\n");
dia    = data->tm_mday;
mes    = data->tm_mon + 1;
semana = data->tm_wday;
ano1   = data->tm_year + 1900;
hora   = data->tm_hour;
minu   = data->tm_min;
seg    = data->tm_sec;
printf("\nHoje é %d do mês %d do ano de %d: PEGUEM A VISÃO!\n",dia,mes,ano1);
printf("Dia da semana %i, são exatamente: %i:%d é %i segundos\n",semana,hora,minu,seg);


printf("\nQual o seu nome? ");
fflush(stdin);
gets(nome);

printf("Em que ano você nasceu? ");
fflush(stdin);
scanf("%d",&ano);

idade = data->tm_year + 1900 - ano;

printf("Meu nome é %s, tenho %d anos: Estou em isolamento do IFBA! kkkkkk\n",nome,idade);
printf("\nMinha idade não e essa! kkkkk\n");

printf("\nEdu esta estudando? SIM [s], NÃO [n]: ");
fflush(stdin);
gets(estuda);
if (strcmp(estuda, "n")== 0){
    printf("\nSe não estudar Leandro e George vai empurrar com força!\n");
}
char fag[10];
printf("\nFagner e Uelbert esta estudando? SIM [s], NÃO [s]: \n");
fflush(stdin);
gets(fag);
if (strcmp(fag,"s")==0){
    printf("Fagner provavelmente esta estudando, já Uelbert eu não sei!\n");
}
char jorge[10];
printf("\nJorge aprendeu logica? SIM [s], NÃO [n]\n");
fflush(stdin);
gets(jorge);
if(strcmp(jorge,"n")==0){
    printf("Tem que estudar, se não o fumo entra dinovo!\n");
}
}
