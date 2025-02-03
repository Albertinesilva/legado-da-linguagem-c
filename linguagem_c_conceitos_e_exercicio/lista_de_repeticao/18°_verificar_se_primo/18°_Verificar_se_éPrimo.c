#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int primo=0;
    int divisivel=0;
    int continuar=0;

    while(continuar != 2)
    {
        printf("\nInforme um número, para saber se é PRIMO: ");
        fflush(stdin);
        scanf("%d",&primo);

        for(int i=1; i<=primo; i++)
        {
            if(primo%i==0)
            {
                divisivel++;
            }
        }
        system("cls");
        if(divisivel==2)
        {
            printf("\nO número %d é PRIMO\n",primo);
            divisivel=0;
        }
        else
        {
            printf("\nO número %d não é PRIMO\n",primo);
            divisivel=0;
        }
        printf("\nDeseja continuar:\n\nDigite [1] Sim\nDigite [2] Não\n");
        fflush(stdin);
        scanf("%d",&continuar);
        system("cls");
    }

}
