#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    float vetor_a[5], vetor_b[5],resultado[5];
    int i;

    for (i=0; i <5; i++)
    {

        printf("\nInforme o %d número para a multiplicação dos vetores: ",i);
        scanf("%f",&vetor_a[i]);

        printf("\nInforme o %d número para a multiplicação dos vetores: ",i);
        scanf("%f",&vetor_b[i]);


        resultado[i]=vetor_a[i] * vetor_b[i];
    }
    for (i=0; i<5; i++)
    {


        printf("\nResultado da multiplicação entre %.1f * %.1f = %.2f",vetor_a[i],vetor_b[i],resultado[i]);
    }
    printf("\n");
}
