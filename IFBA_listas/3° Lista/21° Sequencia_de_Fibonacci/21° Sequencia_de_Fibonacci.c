#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0,fibonacci=1,anterior=0, atual=1,contador=0;
    bool b = true;

printf("\nInforme um número para formar a sequencia de FRIBONACCI: ");
scanf("%d",&num);

fibonacci=1;
anterior=0;
atual=1;

    while(num!=contador)
    {
        contador++;

       printf("%d,",fibonacci);

       fibonacci=anterior+atual;
       anterior=atual;
       atual=fibonacci;

    }

    int controle=0, num1=1, num2=0, soma=0;



    printf("\nInforme ate que termo a serie Fibonacci ira\n");
    scanf("%i",&controle);

    for(int i=0; i<controle; i++){
    soma=num1+num2;
    num1=num2;
    num2=soma;
    printf("%i ",soma);
    }
}
