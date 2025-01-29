#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//e) Apresentar os resultados das potências de 3, variando do expoente 0 até o expoente 15. Deve ser
//considerado que qualquer número elevado a zero é 1, e elevado a 1 é ele próprio. Observe que
//neste exercício não pode ser utilizado o operador de exponenciação do portuguol (^).

void main()
{
    setlocale(LC_ALL,"portuguese");

    int b=0,soma=1,e=0;

    printf("\n\tBase: ");
    setbuf(stdin,NULL);
    scanf("%d",&b);

    printf("\n\tExpoente: ");
    setbuf(stdin,NULL);
    scanf("%d",&e);

    for(int i=0; i!=e; i++)
    {
        soma*=b;

    }
    printf("\n\t%d",soma);

}
