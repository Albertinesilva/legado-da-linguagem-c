#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

int codigo;

printf("\nInforme o código do produto: ");
fflush(stdin);
scanf("%d",&codigo);


if(codigo != 1 && codigo != 2 && codigo != 3 && codigo != 4 && codigo != 5){
    printf("\n\n\t\tCÓDIGO INVÁLIDO!\n\n");
}
    else{
        if(codigo == 1){
            printf("\n CÓDIGO  DESCRIÇÃO   PREÇO R$\n");
            printf("\n  %d    \t|CANETA  |\t1,20\n",codigo);
        }
        if(codigo == 2){
            printf("\n CÓDIGO  DESCRIÇÃO   PREÇO R$\n");
            printf("\n  %d    \t| LÁPIS  |\t0,80\n",codigo);
        }
        if(codigo == 3){
            printf("\n CÓDIGO  DESCRIÇÃO   PREÇO R$\n");
            printf("\n  %d    \t| CADERNO |\t4,50",codigo);
        }
        if(codigo == 4){
            printf("\n CÓDIGO  DESCRIÇÃO   PREÇO R$\n");
            printf("\n  %d    \t| BORRACHA |\t1,00\n",codigo);
        }
        if(codigo == 5){
            printf("\n CÓDIGO  DESCRIÇÃO   PREÇO R$\n");
            printf("\n  %d    \t | RÉGUA |\t1,50\n",codigo);
        }

    }

}
