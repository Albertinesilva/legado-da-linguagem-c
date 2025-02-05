#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float valorfinal_doveiculo (char modelo[30],char marc[30], float preco_venda );


void main()
{
    setlocale(LC_ALL,"portuguese");

    float custo_fabrica=0;
    char modelo_veiculo[30],marca[30];

    printf("\n\tInforme o modelo do veículo: ");
    fflush(stdin);
    gets(modelo_veiculo);

    printf("\n\tInforme a marca do veiculo: ");
    fflush(stdin);
    gets(marca);

    printf("\n\tInforme o custo de fabricação: ");
    scanf("%f",&custo_fabrica);

    valorfinal_doveiculo (modelo_veiculo,marca,custo_fabrica);


}
float valorfinal_doveiculo (char modelo[30],char marc[30],float preco_venda)
{
    float acrecimo = preco_venda + ((preco_venda*30)/100);

    printf("\n\tModelo do veiculo: %s\n\tMarca do veiculo: %s\n\tValor final do veiculo: R$%.2f\n",modelo,marc,acrecimo);

    return acrecimo;
}
