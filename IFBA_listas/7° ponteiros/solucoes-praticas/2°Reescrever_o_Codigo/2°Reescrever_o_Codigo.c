#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{

    setlocale(LC_ALL,"POrtuguese");

    int vetor[5],i=0,x;
    int *ponteiro=&x;

    for(i=0; i<5; i++)
    {
        *ponteiro =  i*10;
        printf("vetor[i] = %d\n",*ponteiro);
        vetor[i]=x;
    }
    for(int j=0; j<5; j++)
    {
        printf("%d\n",vetor[j]);
    }

}
