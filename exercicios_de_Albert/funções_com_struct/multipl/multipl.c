#include <stdio.h>
#include <locale.h>

int mul (int x, int y);

void main()
{
setlocale(LC_ALL,"portuguese");
int x,y,resul;

printf("Digite um número\n");
scanf("%d",&x);

printf("Digite outro número\n");
scanf("%d",&y);

resul = mul (x,y);
printf("Resultado da multiplicação %d\n",resul);
printf("Resultado da multiplicação %d\n",resul);
}

int mul (int x,int y)
{
int resul;
resul = x * y;
}
