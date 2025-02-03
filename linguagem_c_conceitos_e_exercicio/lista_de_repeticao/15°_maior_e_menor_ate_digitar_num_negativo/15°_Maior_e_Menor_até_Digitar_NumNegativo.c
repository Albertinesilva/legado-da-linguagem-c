#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=1,maior=0,menor=9999;

    while(num>0)
    {
        printf("\nDigite um número: ");
        fflush(stdin);
        scanf("%d",&num);

        if(num > maior)
        {
            maior=num;
        }
        if(num < menor)
        {
            menor=num;
        }
    }
    printf("\n\nMenor = %d\nMaior = %d\n",maior,menor);
}
