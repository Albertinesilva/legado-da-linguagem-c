#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void main ()
{
    setlocale(LC_ALL,"portuguese");

    int num=0,divisores=0, contador=0, soma=0, cont=0;
    bool b = true;


    printf("\nInforme um número para saber se ele e perfeito: ");
    scanf("%d",&num);

    while(b)
    {
        contador++;

        if(contador==num)

        {
            b = false;
        }

        if(num%contador==0 && num!=contador)
        {
            soma += contador;
            printf("\nDivisiveis %d\n ",contador);

        }


    }
    printf("\nA soma dos números = %d\n",soma);

    if(soma!=num)
        {
            printf("\nNão e um número perfeito.\n");
        }
        else
        {
            printf("\nÉ um número perfeito.\n");
        }





    int qtd=0, numero=1, somar=0;


    do{
      somar=0;
      for(int i=1; i<numero; i++){
        if(numero%i==0){
            somar=somar+i;
        }
      }
      if(somar==numero){
        printf("\n%d\n",numero);
        qtd++;
      }
      numero++;
    }while(qtd!=3);


}
