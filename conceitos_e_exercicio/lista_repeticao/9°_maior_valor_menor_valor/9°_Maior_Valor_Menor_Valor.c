#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0;
    int maior=0,menor=99999999;

    for(int i=0; i<10; i++)
    {
        printf("\n%d° Informe um número: ",i+1);
        fflush(stdin);
        scanf("%d",&num);

        if(num > maior)
        {
            maior=num;
        }
        if(num<menor)
        {
          menor=num;
        }
    }
    printf("\nMaior = %d\nMenor = %d\n",maior,menor);
}
