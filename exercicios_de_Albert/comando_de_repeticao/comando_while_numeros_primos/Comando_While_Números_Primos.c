#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main(){
setlocale(LC_ALL,"portuguese");

int divisivel,x,primo;
bool b = true;
char continuar;
divisivel = 0;
x = 0;


while (b){
    divisivel = 0;
    x = 0;
    printf("\nInforme um número para saber se é PRIMO: ");
    scanf("%d",&primo);

    while (x != primo){
        x += 1;

    if(primo%x==0){
        divisivel += 1;
        }
    }

        if(divisivel==2){
        printf("\nO número %d é PRIMO\n\nDeseja continuar? SIM[S], NÃO [N]: ",primo);
        fflush(stdin);
        continuar = getchar();
        }

        else{
        printf("\nO número %d não é PRIMO!\n\nDeseja continuar? SIM[S], NÃO[N] ",primo);
        fflush(stdin);
        continuar = getchar();
        }

        if(continuar=='n'){
            b = false;
            printf("\nConsulta de números PRIMOS FOI ENCERRADA!!!\n");
        }

}

}
