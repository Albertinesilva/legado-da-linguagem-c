#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Quadrado_Perfeito(int num);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int quadrado=0;
    printf("\nInforme um número para verificar se é um quadrado perfeito: ");
    fflush(stdin);
    scanf("%d",&quadrado);

    Quadrado_Perfeito(quadrado);

}
void Quadrado_Perfeito(int num)
{
    int quadrado = num * num;

    if(num<=0)
    {
        printf("\nO número %d não é um quadrado perfeito!\n",num);
    }
    else
    {
        if(quadrado%num==0)
        {
            printf("\nO número %d é um quadrado perfeito!\n",num);
        }
    }
}
