#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int valores=0;
    int soma=0;

    for(int i=0; i<10; i++)
    {
        printf("\nDigite o %d° valor: ",i+1);
        fflush(stdin);
        scanf("%d",&valores);

        soma+=valores;
    }
    printf("\nValores somados = %d\n",soma);
}
