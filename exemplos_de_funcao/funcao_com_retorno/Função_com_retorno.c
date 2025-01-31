#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int retorna_divisivel_por5();

void main()
{
    setlocale(LC_ALL,"portuguese");

    srand(time(NULL));

    int divisivel=0;

    divisivel=retorna_divisivel_por5();
    printf("\n\tNúmero divisivel por 5: %d\n",divisivel);
}
int retorna_divisivel_por5()
{
    int div=0;

    do
    {
        div=rand()%101;
    }
    while(div%5!=0);

    return div;
}
