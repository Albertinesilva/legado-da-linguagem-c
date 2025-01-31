#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main (){
setlocale(LC_ALL,"portuguese");

char estado[10];

printf("Em que estado do Brasil você nasceu? ");
fflush(stdin);
gets(estado);

if (strcmp(estado,"RJ")== 0) {
    printf("Nascendo em %s você é CARIOCA\n",estado);

    }else{
    if (strcmp(estado, "SP")== 0) {
        printf("Nascendo em %s você é PAULISTA\n",estado);

        }else{
        if (strcmp(estado, "MG")== 0) {
            printf("Nascendo em %s você é MINEIRO\n",estado);

            }else{
            if (strcmp(estado, "AL")== 0) {
                printf("Nascendo em %s você é ALAGOANO\n",estado);


                }else{
                if (strcmp(estado, "RN")== 0){
                    printf("Nascendo em %s você é POTIGUAR\n",estado);

                    }else{
                    if(strcmp(estado, "BA")== 0){
                        printf("Nascendo em %s você é SOTEROPOLITANO\n",estado);
                        }else{
                            printf("Nascendo em %s você é natural da sua cidade, mas ainda não sei como te chamar!",estado);

                        }

                    }
                }
            }
        }
    }
}










