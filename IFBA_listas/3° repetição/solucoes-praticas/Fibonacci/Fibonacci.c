#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");


    int num=0,anterior=1,fibonacci=0, atual=0,contador=0;


    printf("informe um numero: ");
    scanf("%d",&num);
printf("\n");
    while(contador!=num)
    {contador++;

     fibonacci=anterior+atual;
     anterior=atual;
     atual=fibonacci;

     printf("%d,",fibonacci);
    }
printf("\n");
}
