#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int num,x,impar;
    bool b = true;
    char continuar;
    x=0;
    impar=0;

    while(b)
    {
        printf("\nInforme quantos números ímpares deseja imprimir: ");
        scanf("%d",&num);

        while(x!=num)
        {
            impar += 1;
            if(impar%2==1)
            {
                x += 1;
                printf("\nOs %d impares solicitado %d\n",num,impar);
            }

            if(x==num)
            {
                x=0;
                impar=0;
                num=0;
                printf("\nDeseja continuar com a pesquisa? SIM[S], NÃO[N]  ");
                fflush(stdin);
                continuar=getchar();
            }

            if(continuar == 'n')
            {
                b = false;
                printf("\nPesquisa finalizada com sucesso!\nObrigado!\n");
            }

        }
    }
}
