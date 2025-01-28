#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int mat[3][3];
    int l=0,c=0,cont=1;
    int linha,Numero,Numero_desejado;



    for(l=0; l<3; l++)
    {
        for(c=0; c<3; c++)
        {
            mat[l][c]=cont++;

        }

    }


    for(l=0; l<3; l++)
    {
        for(c=0; c<3; c++)
        {
            printf("|%d",mat[l][c]);
        }
        printf("|\n");
    }
    printf("\n\n");

    printf("\nDigite a linha: ");
    fflush(stdin);
    scanf("%d",&linha);

    printf("\nDigite o número que você deseja: ");
    fflush(stdin);
    scanf("%d",&Numero);

    int Nao_existe=0;

    for(l=0; l<3; l++)
    {
        if(mat[linha-1][l]==Numero)
        {
            Numero_desejado=mat[linha-1][l];

        }
        else
        {
            if(mat[linha-1][l]!=Numero)
            {
                Nao_existe++;
            }

        }
    }
    if(Nao_existe == 3)
    {
        printf("\nNão exite esse número na linha %d\n",linha);
    }
    else
    {
        if(Numero == Numero_desejado)
        {
            printf("\nNúmero: %d\n",Numero_desejado);
        }
    }

}
