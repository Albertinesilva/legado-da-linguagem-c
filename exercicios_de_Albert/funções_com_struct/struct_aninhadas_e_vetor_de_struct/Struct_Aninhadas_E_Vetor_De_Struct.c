// Usando struct dentro de struct:

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Criação da struct tp_endereco
struct tp_endereco
{
    char rua[40];
    char bairro[40];
    char cidade [40];
    char estado [3];
    int numero;
    int cep;

}; // Não foi associada nenhuma variavel à struct ainda...


// Criação da struct tp_data_nascimento:
struct tp_data_nascimento
{
    int dia;
    int mes;
    int ano;

};// Não associei nenhuma variavel à struct ainda, isto será feito
 // dentro da proxima struct

struct cadastro_cliente
{
    char nome_cliente[60];
    int telefone;

    // Declarando variavel associada à struct tp_endereco
    struct tp_endereco endereco;

    // Declarando variavel associada à struct data_nascimento
    struct tp_data_nascimento data_nascimento;
}cad_cliente[2];



//Programa principal:

void main ()
{
    setlocale(LC_ALL,"portuguese");

    int i=0;

    printf("\n\n------------------------------CADASTRO DOS CLIENTES------------------------------\n\n");


    // Armazenando os dados do cadastro dentro da struct cad_cliente:

    for (i=0; i<2; i++)
    {
        printf("\n\nNome do cliente....................: ");
        fflush(stdin);
        gets(cad_cliente[i].nome_cliente);

        printf("\nDigite o telefone do cliente.........: ");
        scanf("%d",&cad_cliente[i].telefone);

        printf("\nDigite a rua.........................: ");
        fflush(stdin);
        gets(cad_cliente[i].endereco.rua);

        printf("\nDigite o número......................: ");
        scanf("%d",&cad_cliente[i].endereco.numero);

        printf("\nBairro...............................: ");
        fflush(stdin);
        gets(cad_cliente[i].endereco.bairro);

        printf("\nCidade...............................: ");
        fflush(stdin);
        gets(cad_cliente[i].endereco.cidade);

        printf("\nEstado...............................: ");
        fflush(stdin);
        gets(cad_cliente[i].endereco.estado);

        printf("\nDigite o CEP.........................: ");
        fflush(stdin);
        gets(cad_cliente[i].endereco.rua);

        printf("\nDia de nascimento....................: ");
        scanf("%d",&cad_cliente[i].data_nascimento.dia);

        printf("\nMês de nascimento....................: ");
        scanf("%d",&cad_cliente[i].data_nascimento.mes);

        printf("\nAno de nascimento....................: ");
        scanf("%d",&cad_cliente[i].data_nascimento.ano);

    }  //Fim da coleta


    //Percorrer o vetor de struct cad_cliente:

    for(i=0; i<2; i++)
    {
        printf("\n\n Nome...............: %s",cad_cliente[i].nome_cliente);
        printf("\n Rua................: %s",cad_cliente[i].endereco.rua);
        printf("\n Número.............: %d",cad_cliente[i].endereco.numero);
        printf("\n Bairro.............: %s",cad_cliente[i].endereco.bairro);
        printf("\n Cidade.............: %s",cad_cliente[i].endereco.cidade);
        printf("\n Estado.............: %s",cad_cliente[i].endereco.estado);
        printf("\n Cep................: %d",cad_cliente[i].endereco.cep);

        printf("\n Dia de nascimento: %d",cad_cliente[i].data_nascimento.dia);
        printf("\n Mês de nascimento: %d",cad_cliente[i].data_nascimento.mes);
        printf("\n Ano de nascimento: %d\n",cad_cliente[i].data_nascimento.ano);
    }
}
