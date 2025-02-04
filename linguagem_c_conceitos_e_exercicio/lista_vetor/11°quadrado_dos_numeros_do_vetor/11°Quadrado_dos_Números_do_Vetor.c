#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int A[20],B[20];

    for(int i=1; i<=20; i++)
    {
        A[i]=i;
    }
    for(int i=1; i<=20; i++)
    {
        printf("%d,",A[i]);
        B[i]=A[i]*i;
    }
    printf("\n\n");
    for(int i=1; i<=20; i++)
    {
        printf("%d,",B[i]);

    }
    printf("\n");


}
