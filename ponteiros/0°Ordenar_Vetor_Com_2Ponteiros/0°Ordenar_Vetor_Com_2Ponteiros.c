#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL,"portuguese");

    int vet[10]= {10,9,3,8,5,6,7,4,2,1};
    int *p1;
    int *p2;
    int aux=0;

    for(p1=vet; p1<vet+10; p1++)
    {
        for(p2=vet; p2<vet+10; p2++)
        {
            if(*p1<*p2)
            {
                aux=*p1;
                *p1=*p2;
                *p2=aux;
            }
        }

    }
    printf("\n------------------------------PONTEIRO ORDENADO--------------------------------\n");
    for(p1=vet; p1<vet+10; p1++)
    {
        printf("%d,",*p1);
    }
    printf("\n\n-------------------------------VETOR ORDENADO----------------------------------\n");
    for(int i=0; i<10; i++)
    {
        printf("%d,",vet[i]);
    }

    printf("\n");
    return 0;
}
