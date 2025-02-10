#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Multiplicacao_Sucessiva(int r,int x,int y);

void main()
{
    setlocale(LC_ALL,"Portuguese");
    int num1=0,num2=0;

    printf("\nDigite o 1° número: ");
    fflush(stdin);
    scanf("%d",&num1);

    printf("\nDigite o 2° número: ");
    fflush(stdin);
    scanf("%d",&num2);

    int result =0;
    result = Multiplicacao_Sucessiva(result,num1,num2);
    printf("\nResultado da Multiplicação: %d\n",result);
}
int Multiplicacao_Sucessiva(int r,int x,int y)
{
    if(y > 0)
    {
        return Multiplicacao_Sucessiva(r+=x,x,y-1);
    }
}

