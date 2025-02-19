#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

float Soma_Vetor(float vet[],float M,int n,int i);

void main()
{
    setlocale(LC_ALL,"portuguese");
    float vetor[5]= {1,2,3,4,5};
    float media=0;
    int y=0;

    media = Soma_Vetor(vetor,media,5,y);
    printf("\nMedia do vetor = %.2f\n",media);
}
float Soma_Vetor(float vet[],float M,int n,int i)
{
    if(i<n)
    {
        return Soma_Vetor(vet,M+=vet[i],n,i+1);
    }
    if(i==n)
    {
        return Soma_Vetor(vet,M/=5,n,i+1);
    }
    return M;
}

