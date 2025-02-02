#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    int x,y;
};

void main()
{
    printf("\nChar: %d\n",sizeof(char));
    printf("\nInt: %d\n",sizeof(int));
    printf("\nFloat: %d\n",sizeof(float));
    printf("\nDouble: %d\n",sizeof(double));
    printf("\nStruct ponto: %d\n",sizeof(struct ponto));
}
