#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int vetor[8]= {10,20,30,40,50,60,70,80};
    int x=8,y=8;

    while(x > 7 || y > 7)
    {
        system("cls");
        printf("\nDigite o 1° Índice: ");
        fflush(stdin);
        scanf("%d",&x);

        printf("\nDigite o 2° Índice: ");
        fflush(stdin);
        scanf("%d",&y);

        if(x < 0 || y < 0)
        {
            x=8;
            y=8;
        }

    }
    printf("\nResultado da soma entre %d + %d = %d\n",vetor[x],vetor[y],vetor[x]+vetor[y]);



    return 0;
}
