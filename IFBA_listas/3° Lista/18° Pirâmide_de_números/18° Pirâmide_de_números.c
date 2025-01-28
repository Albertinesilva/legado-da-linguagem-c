#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0, cont=0, piramide=0;

    printf("\nInforme um número para formar uma pirâmide: ");
    scanf("%d",&num);

    for(int i=1; i<=num; i++)
    {
        cont=1;
        while(cont<=i)
        {
            printf("%.2d",cont);
            cont++;
        }
        printf("\n");
    }


    // 2° Exemplo

    num=0;
    cont=0;
    piramide=0;

    printf("\nInforme um número para formar uma pirâmide: ");
    scanf("%d",&num);

    while(piramide!=num)
        {
            piramide++;
        cont=1;

        while(cont<=piramide)
        {
            printf("%.2d",cont);
            cont++;
        }
        printf("\n");

        }

}
