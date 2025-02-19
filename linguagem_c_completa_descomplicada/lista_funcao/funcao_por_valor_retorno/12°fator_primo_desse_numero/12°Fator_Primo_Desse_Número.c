#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int Maior_Numero_Primo(int primo);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0;
    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&num);

    int maior = Maior_Numero_Primo(num);
    printf("\nMaior fator primo de %d = %d\n",num,maior);
}
int Maior_Numero_Primo(int primo)
{
    int maior=primo;

    for(int i=1; i < maior; i++)
    {
        if(maior%2==0)
        {
            maior=maior/2;
        }
        else
        {
            if(maior%i==0)
            {
              maior=maior/i;
            }
        }
    }
    return maior;
}
