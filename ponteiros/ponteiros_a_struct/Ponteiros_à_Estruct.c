#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

struct horario{
    int hora;
    int minuto;
    int segundo;
}agora;

struct dados{
   char nome[30];
   int idade;
   int ano;
}documento;

void main()
{

    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    struct horario agora,*depois;
    depois=&agora;

    //Forma de acessar um ponteiro tipo struct:
    (*depois).hora=20;
    (*depois).minuto=30;
    (*depois).segundo=59;

    printf("\n%d:%d:%d",agora.hora,agora.minuto,agora.segundo);


    //Outra forma de acessar um ponteiro de struct (Essa maneira é melhor, fica mais intuitivo)
    struct dados documento,*ponteiro;
    ponteiro=&documento;

    strcpy(ponteiro->nome,"Albert");
    ponteiro->idade=40;
    ponteiro->ano=1979;

    printf("\n\nMeu nome é %s, tenho %d anos, nasci em %d.\n",documento.nome,documento.idade,documento.ano);


}

