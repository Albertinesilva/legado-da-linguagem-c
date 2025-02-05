#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

struct estoque
{
    int codigo;
    char nome[15];
    int quantidade;
    int preco;
};



void main()
{
    setlocale(LC_ALL,"portuguese");

    int i=1,n=0,x=0;
    int cod_cliente=0;
    int quant_cliente=0;
    bool cod_produto=true;
    bool fatal=true;

    printf("\n\nInforme a quantidade de produtos existentes no estoque: ");
    scanf("%d",&n);

    struct estoque produto[n];

    do
    {

        for(i=0; i<n; i++)
        {
            printf("\n\n-------------------------%d° PRODUTO-------------------------\n",i+1);
            printf("\nInforme o codigo do produto: ");
            scanf("%d",&produto[i].codigo);

            if(produto[i].codigo<=0)
            {
                i=n;

            }
            else
            {

                printf("\nInforme o nome do produto: ");
                fflush(stdin);
                gets(produto[i].nome);

                printf("\nInforme a quantidade do produto: ");
                scanf("%d",&produto[i].quantidade);

                printf("\nInforme o preço do produto: ");
                scanf("%d",&produto[i].preco);

            }
        }
        cod_produto=true;
        while(cod_produto)
        {
            for(i=0; i<n; i++)
            {
                if(produto[i].codigo<=0)
                {
                    cod_produto=false;
                }
            }
            if(cod_produto==true)
            {
                printf("\n\n----------------------PEDIDO DO CLIENTE---------------------\n");
                printf("\nDigite o código do produto: ");
                scanf("%d",&cod_cliente);
            }
            if(cod_cliente<=0)
            {
                cod_produto=false;
            }
            else
            {
                printf("\nDigite a quantidade do produto: ");
                scanf("%d",&quant_cliente);




                for(i=0; i<n; i++)
                {

                    if(produto[i].codigo==cod_cliente&&produto[i].quantidade>=quant_cliente)
                    {
                        cod_produto=false;
                        printf("\n\nTemos o produto com o codigo informado e a quantidade solicitada!");
                    }
                }
                for(i=0; i<n; i++)
                {

                    if(produto[i].codigo==cod_cliente&&produto[i].quantidade<quant_cliente)
                    {
                        cod_produto=false;
                        produto[i].quantidade=quant_cliente;
                        printf("\nVamos atualizar o estoque!\nEstoque atualizado!");
                        printf("\nQuantidade solicitada disponivel: %d",produto[i].quantidade);
                    }
                }
                for(i=0; i<n; i++)
                {
                    if(produto[i].codigo!=cod_cliente)
                    {
                        x++;
                        cod_produto=false;
                    }
                }
                if(x!=0)
                {
                    cod_produto=false;
                    printf("\nNão temos esse produto na casa, vamos fazer o pedido\nObrigado!");
                }
            }
        }

        x=0;
        for(i=0; i<n; i++)
        {
            if(produto[i].codigo<=0||cod_cliente<=0)
            {
                printf("\nFIM!\n");
                fatal=false;
                cod_produto=false;
            }
            else
            {
                cod_produto=true;
            }
        }

    }
    while(fatal);
}



