#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float parte_inteira_eFracionaria(float *n,float *n2);

void main()
{
    setlocale(LC_ALL,"portuguese");
    float num=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%f",&num);
    float num2=num;

    parte_inteira_eFracionaria(&num,&num2);
    printf("\nParte inteira: %.0f",num);
    printf("\nParte fracionaria: %.0f\n",num2);
}
float parte_inteira_eFracionaria(float *n,float *n2)
{
    *n2= (*n-(int)*n2)/0.01;
    *n=(int)*n;
}
