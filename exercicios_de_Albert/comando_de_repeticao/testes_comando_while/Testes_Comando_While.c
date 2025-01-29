#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

void main(){
setlocale(LC_ALL,"portuguese");

bool b=true;
int num;
char continuar;




while (b==true){

printf("\nInforme um número: ");
scanf("%d",&num);

     if(num%2==0){
        b=false;
        printf("\nO número informado é PAR!\n");

     }
     else{ if(num%2==1){
        b=false;
        printf("\nO número informado e ÍMPAR!\n");
     }
     }
     printf("\nVocê deseja continuar? sim[s] não[n] \n");
     fflush(stdin);
     continuar=getchar();

     if(continuar=='s'){
        b=true;
     }else{
        b=false;
     }

}

}

