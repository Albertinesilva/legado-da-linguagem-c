#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int Potencia(int x,int y,int controle);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int base=0;
    int expoente=0;
    int i=0;

    printf("\nDigite a Base: ");
    fflush(stdin);
    scanf("%d",&base);

    printf("\nDigite o Expoente: ");
    fflush(stdin);
    scanf("%d",&expoente);

    int resul = Potencia(base,expoente,i);
    printf("\nResultado da Pontecia de %d elevado a %d = %d\n",base,expoente,resul);
}
int Potencia(int x,int y,int controle)
{
    if(controle < y-1)
    {
        return Potencia(x*=x,y,controle+1);
    }
    return x;

}

