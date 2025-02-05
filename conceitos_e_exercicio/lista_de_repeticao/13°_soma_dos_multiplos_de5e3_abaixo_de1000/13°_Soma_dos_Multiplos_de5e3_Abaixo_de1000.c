#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int multiplo=0;

    for(int i=0; i<1000; i+=5)
    {
       if(i!=1000)
       {
           multiplo+=i;
           printf("%d,",i);
       }
    }
    printf("\n\nSoma dos multiplos de 5 ate 1000 = %d\n",multiplo);

}
