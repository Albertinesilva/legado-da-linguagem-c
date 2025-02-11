#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0;
    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&num);

     printf("\n");
    for(int i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            printf("%d,",i);
        }
    }
    printf("\n");

}
