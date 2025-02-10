#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Fibonacci(int n);

void main()
{
    setlocale(LC_ALL,"portuguese");
    int x=0,i=0;

    printf("\nDigite um número: ");
    fflush(stdin);
    scanf("%d",&x);

    printf("%d,",i);
    for(i=0; i<x; i++)
        printf("%d, ", Fibonacci(i+1));
    getchar();


}
int Fibonacci(int n)
{
    if(n==1 || n==2)
        return 1;
    else
    return Fibonacci(n-1) + Fibonacci(n-2);
}
