#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int Soma_Vetor(int vet[],int s,int n,int i);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int vetor[5]= {1,2,3,4,5};
    int y=0,soma=0;


    soma = Soma_Vetor(vetor,soma,5,y);
    printf("\nSoma = %d\n",soma);
}
int Soma_Vetor(int vet[],int s,int n,int i)
{
    if(i<n)
    {
        return Soma_Vetor(vet,s+=vet[i],n,i+1);
    }
    if(i==n)
    {
        return s;
    }

}

