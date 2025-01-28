#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

int calculo_potencia (int num1,int num2);
int potencia_usando_for (int x, int y);

void main ()
{
    setlocale(LC_ALL,"portuguese");

    int base=0,expoente=0,potencia=0,p=0;

    printf("\n\tInforme a base: ");
    scanf("%d",&base);

    printf("\n\tInforme o expoente: ");
    scanf("%d",&expoente);

    potencia=calculo_potencia(base,expoente);

    if(expoente<0)
    {
        printf("\n\tExpoente é menor que zero\n");
    }
    else
    {
        printf("\n\tResultado da pontencia de %d elevado a %d é: %d\n",base,expoente,potencia);
    }

    p=potencia_usando_for(base,expoente);

    if(expoente>0)
    {
        printf("\n\tUsando o comando FOR:\n\tResultado da potencia de %d elevado a %d é: %d\n",base,expoente,p);
    }
    else
    {
        printf("\n\tUsando o comando FOR:\n\tExpoente é menor que zero\n");
    }



}
int calculo_potencia (int num1,int num2)
{
    if(num2 >=0)
    {
        return pow(num1,num2);

    }
}
int potencia_usando_for (int x, int y)
{
    int i=0;
    double result=1;

    if(y >= 0)
    {

        for(i=0; i<y; i++)
        {
            result*=x;
        }
    }
    return result;

}
