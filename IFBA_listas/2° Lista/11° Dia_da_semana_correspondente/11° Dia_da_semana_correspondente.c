#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){
setlocale(LC_ALL,"portuguese");

int semana;

printf("Informe um número de 1 a 7: ");
scanf("%d",&semana);

if(semana == 1){
    printf("\nO dia da semana correspondente ao número informado é DOMINGO\n");
}
    else{
        if(semana == 2){
        printf("\nO dia da semana correspondente ao número informando é SEGUNDA FEIRA\n");
        }
        else{
            if(semana == 3){
            printf("\nO dia da semana correspondente ao número informado é TERÇA FEIRA\n");
            }
            else{
                if(semana == 4){
                printf("\nO dia da semana correspondente ao número informado é QUARTA FEIRA\n");
                }
                else{
                    if(semana == 5){
                    printf("\nO dia da semana correspondente ao número informado é QUINTA FEIRA\n");
                    }
                    else{
                        if(semana == 6){
                        printf("\nO dia da semana correspondente ao número informado é SEXTA FEIRA\n");
                        }
                        else{
                            if(semana == 7){
                            printf("\nO dia da semana correspondente ao número informado é SABADO\n");
                            }
                            else{
                                printf("\nO número informado é invalido!");
                            }
                        }
                    }
                }
            }
        }
    }
}
