#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

struct estoque
{
    int codigo;
    char nome[15];
    float preco;
    int quant;
};

struct estoque localize (struct estoque a[],int x,int cod, int quanti);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int n=0,i=0;
    int codigo=1;
    int quantidade=0;
    bool sair=true;

    printf("\n\nTêm quantos produtos na loja? ");
    scanf("%d",&n);

    struct estoque produto[n];

    while(sair)
    {

        for(i=0; i<n; i++)
        {
            printf("\n\n------------------%d° PRODUTO----------------------\n",i+1);
            printf("\nInforme o nome do produto: ");
            fflush(stdin);
            gets(produto[i].nome);

            printf("\nQual o código (do/da) %s? ",produto[i].nome);
            scanf("%d",&produto[i].codigo);

            printf("\nQuanto custa (o/a) %s? ",produto[i].nome);
            scanf("%f",&produto[i].preco);

            printf("\n(Quanta(s)/Quanto(s)) %s têm no estoque? ",produto[i].nome);
            scanf("%d",&produto[i].quant);

        }

        int cont=1;
        int x=0,y=0;

        while(cont<=n)
        {

            printf("\n\n---------------PEDIDO DO %d° CLIENTE---------------\n",cont);

            printf("\nDigite o código do produto: ");
            scanf("%d",&codigo);

            if(codigo<=0)
            {
                printf("\nNão existe esse código: %d na loja!",codigo);
                sair=false;
                cont=n;
            }
            else
            {
                printf("\nInforme quantos o senhor deseja: ");
                scanf("%d",&quantidade);
            }

            for(y=0; y<n; y++)
            {

                if(produto[y].codigo!=codigo)
                {
                    x++;
                }
            }
            if(x==n&&sair==false)
            {
                printf("\nFIM!\n");
            }
            else
            {
                if(x!=0)
                {
                    printf("\nNão existe esse código: %d na loja!\n",codigo);

                }
            }
            x=0;


            struct estoque local;
            local=localize(produto,n,codigo,quantidade);

            cont++;
        }
    }

}
struct estoque localize (struct estoque a[],int x,int cod,int quanti)
{
    int i=0;


    for(i=0; i<x; i++)
    {

        if(a[i].codigo==cod && a[i].quant>=quanti)
        {
            printf("\nTemos o produto com o código: %d\nTemos %d em estoque, podemos atender o seu pedido!\n",a[i].codigo,a[i].quant);
        }
        else
        {
            if(a[i].codigo==cod && a[i].quant<=quanti)
            {
                printf("\nTemos o produto com o código: %d\nNão temos: %d, %s em estoque.\nSó temos: %d em estoque!\n ",a[i].codigo,quanti,a[i].nome,a[i].quant);
            }
        }
    }
};
