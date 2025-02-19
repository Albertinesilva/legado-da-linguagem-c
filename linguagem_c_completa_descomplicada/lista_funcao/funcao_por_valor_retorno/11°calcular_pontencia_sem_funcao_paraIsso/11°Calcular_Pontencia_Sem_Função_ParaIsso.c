#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Calcular_Potencia(int x,int y);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int base=0,expoente=0;

    printf("\nDigite a base: ");
    fflush(stdin);
    scanf("%d",&base);

    printf("\nDigite o expoente: ");
    fflush(stdin);
    scanf("%d",&expoente);

    int resultado = Calcular_Potencia(base,expoente);

    printf("\nResultado da potencia de %d elevado a %d = %d\n",base,expoente,resultado);
}
int Calcular_Potencia(int x,int y)
{
    int resul=1;

    for(int i=0; i<y; i++)
    {
         resul*=x;
    }
    return resul;
}
