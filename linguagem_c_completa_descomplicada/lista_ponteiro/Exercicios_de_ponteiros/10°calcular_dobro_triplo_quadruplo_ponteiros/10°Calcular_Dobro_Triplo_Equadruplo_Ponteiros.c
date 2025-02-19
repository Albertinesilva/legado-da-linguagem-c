#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int a=0,*b,**c,***d;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&a);

    b=&a;
    c=&b;
    d=&c;

    int dobro=*b*2;
    int triplo=**c*3;
    int quadruplo=***d*4;

    printf("\nDobro de %d = %d\n",a,dobro);
    printf("\nTriplo de %d = %d\n",a,triplo);
    printf("\nQuadruplo de %d = %d\n",a,quadruplo);

    printf("\n\n-----------------CALCULO FEITO DENTRO DO PRINTF----------------------");
    printf("\nDobro de %d = %d\n",a,*b*2);
    printf("\nTriplo de %d = %d\n",a,**c*3);
    printf("\nQuadruplo de %d = %d\n",a,***d*4);
}
