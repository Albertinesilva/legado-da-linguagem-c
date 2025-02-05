#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main(){
setlocale(LC_ALL,"portuguese");


int a,b,c;

printf("Informe um dos lados do triângulo: ");
scanf("%d",&a);

printf("\nInforme o outro lado do triângulo: ");
scanf("%d",&b);

printf("\nInforme o ultimo lado do triângulo: ");
scanf("%d",&c);

if(a < b + c && b < a + c && c < a + b)
    {

    if((a==b) && (b==c)){
    printf("\nCom os dados informados, forma um TRIÂNGULO EQUILÁTERO\n");
    }

    else{
        if((a!=b) && (b!=c)){
        printf("\nCom os dados informados, forma um TRIÂNGULO ESCALENO\n");
        }

        else{

            printf("\nCom os dados informados, forma um TRIÂNGULO ISÓSCELES\n");
            }

        }
}


        else{
        printf("\nNão forma um TRIÂNGULO\n");
            }

}
