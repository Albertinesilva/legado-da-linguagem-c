#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

void imprime_matriz(int matriz[4][4]);

void imprime_diagonalprincipal(int matriz[4][4]);

void imprime_diagonalsecundaria(int matriz[4][4]);

void imprime_triangularsuperior(int matriz[4][4]);

void imprime_triangularinferior(int matriz[4][4]);

void imprime_somalinha(int matriz[4][4],int somalinha[4],int x,int somacoluna[4],int y);

void imprime_matrizprimo(int num_inicial);

void imprime_matrizpar(int numpar);

void imprime_matrizimpar(int numimpar);


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int mat[4][4], soma_linha[4]= {0},soma_coluna[4]= {0};
    int l=0,c=0;
    int somadiagonal=0, primo=0;
    int par=0,impar=0;

    for(l=0; l<4; l++)
    {
        for(c=0; c<4; c++)
        {
            mat[l][c]=rand()%50+10;
        }
    }

    printf("\t\n********************MATRIZ [4][4]**********************\n\n");
    imprime_matriz(mat);

    printf("\t\n********************SOMA DE LINHAS E COLUNAS***********\n\n");
    imprime_somalinha(mat,soma_linha,4,soma_coluna,4);

    printf("\t\n\n********************DIAGONAL PRINCIPAL****************\n\n");
    imprime_diagonalprincipal(mat);

    printf("\t\n**********************DIAGONAL SECUNDARIA**************\n\n");
    imprime_diagonalsecundaria(mat);

    printf("\t\n*********************TRIANGULAR SUPERIOR***************\n\n");
    imprime_triangularsuperior(mat);

    printf("\t\n*********************TRIANGULAR INFERIOR***************\n\n");
    imprime_triangularinferior(mat);


    printf("\t\n***********MATRIZ[5][5] COM NÚMEROS PRIMOS*************\n");

    printf("\n  Você deseja montar uma matriz com números PRIMOS a partir de que número?  ");
    scanf("%d",&primo);
    printf("\n");
    imprime_matrizprimo(primo);

    printf("\t\n************MATRIZ[5][5] COM NÚMEROS PARES*************\n");

    printf("\n  Você deseja montar uma matriz com números pares a partir de número?  ");
    scanf("%d",&par);
    printf("\n");
    imprime_matrizpar(par);

    printf("\t\n************MATRIZ[5][5] COM NÚMEROS IMPARES************\n");

    printf("\n  Você deseja montar uma matriz com números impares a partir de número?  ");
    scanf("%d",&impar);
    printf("\n");
    imprime_matrizimpar(impar);


}
void imprime_matriz(int matriz[4][4])
{
    int l=0, c=0;


    for(l=0; l<4; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            printf("|%d",matriz[l][c]);
        }
        printf("|\n");
    }
}
void imprime_somalinha(int matriz[4][4],int somalinha[4],int x,int somacoluna[4],int y)
{
    int l=0,c=0;
    int i=0,maior=0,menor=9999;
    int soma_total=0;

    for(l=0; l<4; l++)
    {
        for(c=0; c<4; c++)
        {
            somalinha[l]+=matriz[l][c];
            somacoluna[c]+=matriz[l][c];
        }
    }
    for(i=0; i<4; i++)
    {
        soma_total+=somalinha[i];
        printf("\n\t%d° Linha: %d",i+1,somalinha[i]);
    }
    printf("\n");
    for(i=0; i<4; i++)
    {
        soma_total+=somacoluna[i];
        printf("\n\t%d° Coluna: %d",i+1,somacoluna[i]);
    }

    for(l=0; l<4; l++)
    {
        for(c=0; c<4; c++)
        {
            if(matriz[l][c]>maior)
            {
                maior=matriz[l][c];
            }
            else
            {
                if(matriz[l][c]<menor)
                {
                    menor=matriz[l][c];
                }
            }
        }
    }
    printf("\n\n\tSOMA = TOTAL DA MATRIZ[4][4] = %d\n",soma_total);
    printf("\tMAIOR NÚMERO DA MATRIZ[4][4] é: %d\n",maior);
    printf("\tMENOR NÚMERO DA MATRIZ[4][4] é: %d\n",menor);
}
void imprime_diagonalprincipal(int matriz[4][4])
{
    int l=0,c=0;
    int soma=0;

    for(l=0; l<4; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            if(l==c)
            {
                printf("|%d",matriz[l][c]);
                soma+=matriz[l][c];
            }
            else
            {
                printf("|x|");
            }
        }
        printf("|\n");
    }
    printf("\n\tResultado da soma: DIAGONAL PRINCIPAL = %d\n",soma);
}
void imprime_diagonalsecundaria(int matriz[4][4])
{
    int l=0,c=0;
    int soma_secund=0;

    for(l=0; l<4; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            if(l+c==3)
            {
                soma_secund+=matriz[l][c];
                printf("|%d",matriz[l][c]);
            }
            else
            {
                printf("|x|");
            }
        }
        printf("\n");
    }
    printf("\n\tResultado da soma: DIAGONAL SECUNDARIA = %d\n",soma_secund);
}
void imprime_triangularsuperior(int matriz[4][4])
{
    int l=0,c=0;
    int soma_triangular_superior=0;

    for(l=0; l<4; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            if(l<c)
            {
                soma_triangular_superior+=matriz[l][c];
                printf("|%d",matriz[l][c]);
            }
            else
            {
                printf("|x|");
            }
        }
        printf("\n");
    }
    printf("\n\tResultado da soma: TRIANGULAR SUPERIOR = %d\n",soma_triangular_superior);
}
void imprime_triangularinferior(int matriz[4][4])
{
    int l=0,c=0;
    int soma_triangular_inferior=0;

    for(l=0; l<4; l++)
    {
        printf("\t");
        for(c=0; c<4; c++)
        {
            if (l>c)
            {
                soma_triangular_inferior+=matriz[l][c];
                printf("|%d",matriz[l][c]);
            }
            else
            {
                printf("|x|");
            }
        }
        printf("\n");
    }
    printf("\n\tResultado da soma: TRIANGULAR INFERIOR = %d\n",soma_triangular_inferior);
}
void imprime_matrizprimo(int num_inicial)
{
    int l=0,c=0,i=0;
    int divisivel=0;
    bool verdade=true;
    int matriz[5][5];

    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            while(verdade)
            {
                for(i=1; i<=num_inicial; i++)
                {
                    if(num_inicial%i==0)
                    {
                        divisivel++;
                    }
                }
                if(divisivel==2)
                {
                    divisivel=0;
                    verdade=false;
                }
                else
                {
                    num_inicial++;
                    divisivel=0;
                }
            }
            matriz[l][c]=num_inicial;
            num_inicial++;
            verdade=true;
        }
    }

    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            printf("|%d",matriz[l][c]);
        }
        printf("|\n");
    }
}
void imprime_matrizpar(int numpar)
{
    int l=0,c=0,div=0;
    int matriz[5][5];
    bool verdadeiro=true;

    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            while(verdadeiro)
            {
                if(numpar%2==0)
                {
                    div++;
                }
                if(div==1)
                {
                    div=0;
                    verdadeiro=false;
                }
                else
                {
                    div=0;
                    numpar++;
                }
            }
            matriz[l][c]=numpar;
            numpar++;
            verdadeiro=true;
        }
    }

    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            printf("|%d",matriz[l][c]);
        }
        printf("|\n");
    }
}
void imprime_matrizimpar(int numimpar)
{
    int l=0,c=0,div=0;
    bool verdadeiro=true;
    int matriz[5][5];

    for(l=0; l<5; l++)
    {
        for(c=0; c<5; c++)
        {
            while(verdadeiro)
            {
                if(numimpar%2==1)
                {
                    div++;
                }
                if(div==1)
                {
                    div=0;
                    verdadeiro=false;
                }
                else
                {
                    numimpar++;
                    div=0;
                }
            }
            matriz[l][c]=numimpar;
            verdadeiro=true;
            numimpar++;
        }
    }
    for(l=0; l<5; l++)
    {
        printf("\t");
        for(c=0; c<5; c++)
        {
            printf("|%d",matriz[l][c]);
        }
        printf("|\n");
    }
}
