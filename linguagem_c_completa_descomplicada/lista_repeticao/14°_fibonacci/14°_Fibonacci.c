#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int anterior=0,proximo=1;
    int fibonacci=0;
    int enesimo=0;

    printf("\nDigite um n�mero para fomar a s�rie de FIBONACCI: ");
    fflush(stdin);
    scanf("%d",&enesimo);
    printf("\n");

    for(int i=0; i<enesimo; i++)
    {
        printf("%d,",fibonacci);
        anterior=proximo;
        proximo=fibonacci;
        fibonacci=anterior+proximo;

    }
    printf("\n");


}
