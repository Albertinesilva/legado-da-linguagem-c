#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0;
    int soma=0;

    printf("\nInforme um número: ");
    fflush(stdin);
    scanf("%d",&num);

    for(int i=1; i<num-1; i++)
    {
       if(num%i==0)
       {
        soma+=i;
        printf("%d,",i);
       }
    }
    printf("\n\nSoma = %d\n",soma);
}
