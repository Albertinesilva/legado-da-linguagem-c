#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");

int n1,n2;

printf("Digite um número: ");
fflush(stdin);
scanf("%d",&n1);

printf("Digite o segundo número: ");
fflush(stdin);
scanf("%i",&n2);


    //if (n1 > n2){
        //printf("\nO maior valor é o primeiro: %d\n",n1);
    //} else {
      //  if (n1 < n2){
          //  printf("\nO maior valor é o segundo: %d\n",n2);
        //} else {
         //   if(n1 == n2){
           //     printf("\nOs dois valores são iguais: %d = %d\n",n1,n2);
            //}
        //}
    //}

//MESMO EXERCÍCIO: SO QUE DE MANEIRA SIMPLIFICADA.

    //if (n1 > n2) {
      //  printf("\nO maior valor é o primeiro: %d\n",n1);
    //} else if (n1 < n2) {
        //printf("\nO maior valor é o segundo: %d\n",n2);
    //} else if (n1 == n2) {
      //  printf("\nOs dois valores são iguais: %d = %d\n",n1,n2);

    //}

//MESMO EXERCÍCIO: DE OUTRA MANEIRA SIMPLIFICADA.

 if (n1 > n2) printf("\nO maior valor é o primeiro: %d\n",n1);
    else if (n1 < n2) printf("\nO maior valor é o segundo: %d\n",n2);
    else if (n1 == n2) printf("\nOs dois valores são iguais: %d = %d\n",n1,n2);

}
