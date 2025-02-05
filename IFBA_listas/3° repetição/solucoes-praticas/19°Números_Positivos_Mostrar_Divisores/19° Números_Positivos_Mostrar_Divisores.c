#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0, contador=0;


    printf("\nInforme um número para saber quais são seus divisores: ");
    scanf("%d",&num);

    system("cls");

    printf("\n\n\t//////////////////// DIVISORES DE %d ////////////////////\n\n",num);

    while(contador!=num)
    {
        contador++;

        if(num%contador==0)
        {
            printf("\t\t\t%d É divisivel por: %d\n ",num,contador);
        }

    }

}
