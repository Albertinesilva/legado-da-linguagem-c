
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int vet_par[5],vet_impar[5];
    int i=0,par=0,impar=0,y=0,x=0,num=0;
    bool b=true;


    for(i=0; i<30; i++)
    {


        printf("\nInforme um número para saber se é PAR OU IMPAR: ");
        scanf("%d",&num);


        if(num%2==0 && par<5)
        {
            vet_par[par]=num;
            par++;
        }

        if(par==5)
        {

            printf("\n\n\t------------------------------NÚMEROS PARES------------------------------\n");
            for(y=0; y<5; y++)
            {
                printf("\n\t%d\n",vet_par[y]);
            }
            par=0;
        }
        if(num%2==1 && impar<5)
        {

            vet_impar[impar]=num;
            impar++;


        }
        if(impar==5)
        {

            printf("\n\n\t------------------------------NÚMEROS ÍMPARES------------------------------\n");
            for(x=0; x<5; x++)
            {
                printf("\n\t%d\n",vet_impar[x]);
            }
            impar=0;
        }


    }
    printf("\n");
    system("cls");
    for(i=0; i<par; i++)
    {
        printf("%d,",vet_par[i]);

    }
    printf("\n");
    printf("\n");
    for(i=0; i<impar; i++)
    {
        printf("%d,",vet_impar[i]);

    }
    printf("\n");
}
