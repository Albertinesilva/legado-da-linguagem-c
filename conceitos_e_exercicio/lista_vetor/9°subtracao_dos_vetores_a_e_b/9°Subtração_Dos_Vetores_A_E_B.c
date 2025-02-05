#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int A[10],B[10],C[10];

    for(int i=0; i<10; i++)
    {
        A[i]=rand()%10+50;
        B[i]=rand()%10+100;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n\n");
    for(int i=0; i<10; i++)
    {
        printf("%d,",B[i]);
        C[i]=A[i] - B[i];
    }
    printf("\n\n----------------------------------SUBTRAÇÃO DOS VETORES A E B------------------------------\n\n");
    for(int i=0; i<10; i++)
    {
        printf("%d,",C[i]);
    }
    printf("\n\n");

    return 0;
}
