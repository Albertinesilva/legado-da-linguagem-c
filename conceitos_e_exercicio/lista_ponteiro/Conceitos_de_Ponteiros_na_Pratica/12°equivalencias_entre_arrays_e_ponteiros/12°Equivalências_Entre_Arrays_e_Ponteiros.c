#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5] = {1,2,3,4,5};
    int *p, indice = 2;
    p = vet;
//vet[0] � equivalente a *p;
    printf("%d\n",*p);
    printf("%d\n",vet[0]);
//vet[indice] � equivalente a *(p+indice);
    printf("%d\n",vet[indice]);
    printf("%d\n",*(p+indice));
//vet � equivalente a &vet[0];
    printf("%d\n",vet);
    printf("%d\n",&vet[0]);
//&vet[indice] � equivalente a (vet+indice);
    printf("%d\n",&vet[indice]);
    printf("%d\n",(vet+indice));

    system("pause");
    return 0;
}
