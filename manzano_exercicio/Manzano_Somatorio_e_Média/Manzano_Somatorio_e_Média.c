//i) Elaborar um programa que efetue a leitura de 10 valores numéricos e apresente no final o total do
//somatório e a média aritmética dos valores lidos.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somatorio (int num);
float mediatotal (float media);

void main()
{

    setlocale(LC_ALL, "portuguese");

    int n=0;
    int result=0;
    float m=0;

    for (int i=0; i<10; i++)
    {
        printf("Informe o %d° = ",i+1);
        scanf("%d",&n);
        result+=somatorio(n);

    }
     printf("\nResultado: %d\n",result);

    mediatotal(result);

}

int somatorio (int num)
{
    int total=0;

        total+=num;

        return total;

}
float mediatotal(float media)
{
    media=somatorio(media);
    printf("Media aritmetica %.0f\n",media/10);
}
