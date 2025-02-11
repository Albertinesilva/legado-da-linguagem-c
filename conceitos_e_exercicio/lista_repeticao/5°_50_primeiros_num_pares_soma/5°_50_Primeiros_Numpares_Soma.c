#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int soma=0;

    for(int i=1; i<=100; i++)
    {
        if(i%2==0)
        {
            printf("%d,",i);
            soma+=i;
        }
    }
    printf("\n\nResultado da Soma = %d\n",soma);
}
