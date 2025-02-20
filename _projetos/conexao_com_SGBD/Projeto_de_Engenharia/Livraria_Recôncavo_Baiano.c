#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <mysql.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>


//ESTRUTURA PARA CADASTRO DE CLIENTES.
typedef struct
{
    char Nome[50], Cpf[12], Complemento_Endereco[50];
    char Numero_Telefone[10], Cidade[50], Bairro[30];
    char Email[50], Rua[30], Cep[10], Tipo[30];
    char Livro_Titulo[50];
    int Ddd, Numero_Residencia, Quant_Itens, Desconto;

} Cadastro_Cliente;

//ESTRUTURA PARA CADASTRO DE FUNCIONARIOS.
typedef struct
{
    char Nome[50], Cpf[12], Login[30], Senha[255];
    char Numero_Telefone[10], Cidade[50], Bairro[30];
    char Email[50], Rua[30], Cep[10], Cargo[30], Complemento_Endereco[50];
    int Ddd, Numero_Residencia, Comissao, Permissoes;
    float Salario;

} Cadastro_Funcionario;

//ESTRUTURA PARA FAZER PEDIDO, CADASTRAR LIVROS E CADASTRAR FORNECEDORES.
typedef struct
{
    char Titulo[50], Edicao[15], Fornecedor_Tel[15];
    char Categoria_Titulo[30], Fornecedor_Nome[50];
    char Fornecedor_Email[50], Autor_Nome[50];
    char Data_Pedido[15], Data_Recebido[15];
    int Ano, Quantidade;
    float Valor_Livro;

} Dados_Estoque;

//ESTRUTURA PARA VENDA.
typedef struct
{
    char Data_Venda[15];
    float Valor_Total;
    int Nota_Fiscal;
    int Quant_Itens;
    float Valor_Unitario;
    char Opcao_Pagamento[12];
    char Livros[50];

} Livraria_Vendas;

//ESTRUTURA RESPONSAVEL EM RECEBER OS DADOS DA VENDA
typedef struct
{
    char Nome_Cliente[50];
    char Nome_Funcionario[50];
    char Nome_Livro[50];
    int id_Cliente;
    int  id_Funcionario;
    int id_Estoque;
    int id_Livro;
    int Quant_Estoque;

} Dados_Venda;

//ESTRUTURA DE CHAVES PRIMARIAS E ESTRANGEIRAS
typedef struct
{
    int id_Estoque, id_Funcionario;
    int id_Categoria, id_Fornecedor;
    int id_Autor, id_Endereco;
    int id_Livro, id_Cliente;
    int id_Perfis, id_Rh, id_Forma_Pagamento;
    int id_Telefone, id_Vendas;

} Primary_Key;

/*FUNÇÃO RESPONSAVEL PELO MENU PRINCIPAL DA LIVRARIA RECÔNCAVO BAIANO */
int Menu(MYSQL conexao, int Escolha);

/*FUNÇÃO RESPONSAVEL EM IMPRIMIR RELAÇÕES ENTRE ENTIDADES. */
void Listar_Relacoes_Entre_Entidades(MYSQL conexao);

/*FUNÇÃO RESPONSAVEL EM VERIFICAR SE O ID É VALIDO */
int Busca_id(MYSQL conexao, int id, char query[1024]);

/*FUNÇÃO RESPONSAVEL EM CHECAR DADOS DO CLIENTE */
int Checar_Dados_Cliente(MYSQL conexao,char query[1024], Livraria_Vendas *Vendas, Dados_Venda *Dados, Primary_Key *Primary);

/*FUNÇÃO RESPONSAVEL EM CHECAR O PERFIL DO CLIENTE PARA A VENDA */
int Checar_Perfil_Cliente(MYSQL conexao, char query[1024], int Desconto);

/*FUNÇÃO RESPONSAVEL EM CHECAR OS DADOS DO FUNCIONARIO.*/
int Checar_Dados_Funcionario(MYSQL conexao, char query[1024], Livraria_Vendas *Venda, Dados_Venda *Dados, Primary_Key *Primary);

/*FUNÇÃO RESPONSAVEL EM CHECAR DADOS DO ESTOQUE PARA A VENDA */
int Checar_Dados_Estoque(MYSQL conexao, char query[1024], Livraria_Vendas *Venda, Dados_Venda *Dados, Primary_Key *Primary);

/*FUNÇÃO RESPONSAVEL EM CHECAR DADOS DO LIVRO PARA A VENDA */
int Checar_Dados_Livro(MYSQL conexao, char query[1024], Livraria_Vendas *Venda, Dados_Venda *Dados, Primary_Key *Primary);

/*FUNÇÃO RESPONSAVEL EM CHECAR FORNECEDOR */
int Checar_Fornecedor(MYSQL conexao, Dados_Estoque *Estoque, char query[1024], int id);

/*FUNÇÃO RESPONSAVEL EM INSERIR DADOS DE CLIENTE E FUNCIONARIO*/
void Insert_Cliente_e_Funcionario(MYSQL conexao, Cadastro_Cliente *Cliente, Cadastro_Funcionario *Funcionario,  Primary_Key *Primary);

/*FUNÇÃO RESPONSAVEL EM INSERIR DADOS NO ESTOQUE */
void Insert_Estoque(MYSQL conexao, Dados_Estoque *Estoque, Primary_Key *Primary);

/*FUNÇÃO RESPONSAVEL EM REALIZAR VENDAS */
void Realizar_Vendas(MYSQL conexao, Livraria_Vendas *Venda, Primary_Key *Primary,Dados_Venda *Dados);

/*FUNÇÃO RESPONSAVEL EM ALTERAR DADOS DO LIVRO: TITULO, CATEGORIA, EDIÇÃO, VALOR E AUTOR.*/
void Update_Livros(MYSQL conexao, Dados_Estoque  Estoque);



int main()
{
    /*COMANDO RESPONSAVEL PELA ACENTUAÇÃO*/
    setlocale(LC_ALL,"portuguese");

    /*COMANDO RESPONSAVEL PELA MUDANÇA DE CORES DO PLANO DE FUNDO E DO TEXTO*/
    SetConsoleTitle("cores com system");
    char comando[9] = "color";

    /*STRUCTS*/
    Cadastro_Cliente Cliente;
    Cadastro_Funcionario Funcionario;
    Dados_Estoque Estoque;
    Livraria_Vendas Venda;
    Dados_Venda Dados;
    Primary_Key Primary;

    /*VARIAVEL QUE RECEBE O RETORNO DA FUNÇÃO MENU */
    int Opcao = 0;

    /*VARIAVEL CONEXAO DO TIPO MYSQL */
    MYSQL conexao;

    /*FUNÇÃO DA PROPRIA BIBLIOTECA MYSQL, RECEBE O ENDEREÇO DE MEMÓRIA DA VARIAVEL CONEXAO. RESPONSAVEL PELA CONEXAO COM O BANCO,
    AQUI ESTA SENDO INICIALIZADA A CONEXÃO. */
    mysql_init(&conexao);

    /*VERIFICA SE OS DADOS DE CONEXÃO ESTÃO CORRETOS E DEPOIS ABRE A CONEXÃO COM O BANCO.
    127.0.0.1: ENDEREÇO LOCAL DA MAQUINA
    ROOT: O NOME DO ADMINISTRADOR DO BANCO.
    "": SENHA VAZIA.
    LIVRARIA_RECONCAVO_BAIANO: NOME DO MEU BANCO DE DADOS.
    0, NULL, 0: COMO ESTOU USANDO UMA CONEXÃO LOCAL EU UTILIZO 0, NULL, 0 PORQUE SE TRATA DE UM SERVIDOR LOCAL*/
    if(mysql_real_connect(&conexao, "127.0.0.1", "root", "", "livraria_reconcavo_baiano", 0, NULL, 0))
    {
        printf("\n\tConexão Realizada com Sucesso!...\n\n");
    }
    else
    {
        printf("\n\tFalha na conexão com o Banco de Dados\n");
        printf("\n\tErro %d: %s\n",mysql_errno(&conexao),mysql_error(&conexao));
    }


    while(Opcao != 6)
    {
        Opcao = Menu(conexao, Opcao);

        switch(Opcao)
        {
        case 1:

            strcpy(comando, "color 09");
            system(comando);
            Listar_Relacoes_Entre_Entidades(conexao);

            break;

        case 2:

            strcpy(comando, "color 2f");
            system(comando);
            Insert_Cliente_e_Funcionario(conexao, &Cliente, &Funcionario, &Primary);

            break;

        case 3:

            strcpy(comando, "color 5f");
            system(comando);
            Insert_Estoque(conexao, &Estoque, &Primary);

            break;

        case 4:

            strcpy(comando, "color 7d");
            system(comando);
            Update_Livros(conexao, Estoque);

            break;

        case 5:

            strcpy(comando, "color 1f");
            system(comando);
            Realizar_Vendas(conexao, &Venda, &Primary, &Dados);

            break;

        case 6:

            strcpy(comando, "color 4f");
            system(comando);
            printf("\n\tConexão Finalizada com sucesso!...\n");

            mysql_close(&conexao);
            exit(1);

            break;
        }
    }
    return 0;

}

int Menu(MYSQL conexao, int Escolha)
{
    char comando[9] = "color 0f";
    system(comando);

    printf("\n\n__________________________________________________________________________________________________________________________________________________________________________________________________________________");
    printf("\n{*****|****|****|****|*******|***|*****|*****|*****|*****|*****|****|****|******|****|*****|***|***|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|***|***}\n");
    printf("{___|___|___|_____|_____|_____|_____|_____|___|_____|_____|_____|_____|___|___|_____|____LIVRARIA RECÔNCAVO BAIANO___|_____|____|_____|_____|_____|_____|_____|_____|_____|_____|___|___|___|___|___|__|___|__|__}");
    printf("*******************************************************************************************************************************************************************************************************************");


    do
    {

        printf("\n\n\n\n                                                        \t\t\t{****************************************}\n");
        printf("                                                         \t\t\t|[1] - RELAÇÃO ENTRE TABELAS (ENTIDADES) |");
        printf("\n                                                        \t\t\t{________________________________________}\n");
        printf("                                                        \t\t\t|****************************************|");
        printf("\n                                                        \t\t\t{[2] - CADASTRAR CLIENTES E FUNCIONARIOS }");
        printf("\n                                                        \t\t\t|________________________________________|\n");
        printf("                                                         \t\t\t{****************************************}");
        printf("\n                                                        \t\t\t|[3] - FAZER PEDIDOS E CONSULTAR ESTOQUE |");
        printf("\n                                                        \t\t\t{________________________________________}\n");
        printf("                                                         \t\t\t|****************************************|");
        printf("\n                                                        \t\t\t{[4] - ALTERAR LIVROS                    }");
        printf("\n                                                        \t\t\t|________________________________________|\n");
        printf("                                                         \t\t\t{****************************************}");
        printf("\n                                                         \t\t\t|[5] - VENDER LIVROS                     |");
        printf("\n                                                         \t\t\t{________________________________________}\n");
        printf("                                                         \t\t\t|****************************************|");
        printf("\n                                                        \t\t\t{[6] - SAIR                              }");
        printf("\n                                                        \t\t\t|________________________________________|\n");
        printf("                                                        \t\t\t{*******}********************************}");
        printf("\n                                                        \t\t\t\7|ENTRADA|--> ");
        scanf("%d",&Escolha);

        if(Escolha > 6 || Escolha < 1)
        {
            printf("\n\tOpção escolhida invalida, Tente novamente!...\n\n");
        }
    }
    while(Escolha > 6 || Escolha < 1);
    system("cls");

    return Escolha;
}

void Listar_Relacoes_Entre_Entidades(MYSQL conexao)
{
    /* VARIAVEL REFERENTE AOS DADOS DAS LINHAS NAS TABELAS DO BANCO*/
    MYSQL_ROW rs_linhas;

    /*RESPONSAVEL POR RECEBER O RETORNO DA CONSULTA AO BANCO, UTILIZO UM PONTEIRO CHAMADO (CONSULTA)*/
    MYSQL_RES *Consulta;

    /*VARIAVEL REFERENTE AOS DADOS DAS COLUNAS NAS TABELAS DO BANCO      */
    MYSQL_FIELD *rs_Colunas;

    int i, j, Opcao = 0;
    int voltar_menu;

    while(Opcao !=8)
    {
        printf("\n\t-----------Relação Entre as Tabelas(Entidades)-----------\n");

        do
        {
            printf("\n\n\t[1] - Relação com Livros");
            printf("\n\t[2] - Relção Venda com Forma de Pagamento");
            printf("\n\t[3] - Relação Livros com Estoque");
            printf("\n\t[4] - Relação Perfil com Cliente");
            printf("\n\t[5] - Relação Funcionario com RH");
            printf("\n\t[6] - Relação Autorers com Livros");
            printf("\n\t[7] - Relação Categoria com Titulo de Livros");
            printf("\n\t[8] - Sair");
            printf("\n\tEntrada:  ");
            fflush(stdin);
            scanf("%d",&Opcao);
            system("cls");
        }
        while(Opcao > 8 || Opcao < 1);


        //RELAÇÃO ENTRE ENTIDADES VENDAS E LIVROS, FOI UTLIZADO O COMANDO : SELECT FROM JOIN ON JOIN
        if(Opcao == 1)
        {
            printf("\n\n\n\n--------------------------------------TABELA VENDAS--------------------------------\n");

            if(mysql_query(&conexao, "SELECT    a.venda_id as ID,a.cliente_id as IdCliente,a.funcionario_id as IdFuncionario, a.data_venda as DataCom, a.valor_total as ValorTotal, a.nota_fiscal as NotaFiscal, a.quantidade_itens as Quant_Itens, c.titulo as Titulo FROM vendas a JOIN vendas_livros b on a.venda_id = b.livro_id JOIN livros c on b.livro_id = c.livro_id"))
            {
                printf("\n\tERRO: %s\n",mysql_error(&conexao));
            }
            else
            {
                Consulta = mysql_store_result(&conexao);
            }
            if(Consulta)
            {
                rs_Colunas = mysql_fetch_fields(Consulta);

                for(j = 0; j < mysql_num_fields(Consulta); j++)
                {
                    if(mysql_num_fields(Consulta) > 1)
                    {
                        printf("|%s",(rs_Colunas[j].name));
                    }
                }
                printf("\n");

                while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                {
                    printf("|");
                    for(i = 0; i < mysql_num_fields(Consulta); i++)
                    {
                        printf(" %s\t",rs_linhas[i]);
                    }
                    printf("\n");
                }
            }
            mysql_free_result(Consulta);

            printf("\n-----------------------------------------------------------------------------------\n");
        }
        else
        {
            //RELAÇÃO ENTRE ENTIDADES VENDAS E FORMA_PAGAMENTOS FOI UTILIZADO O COMANDO: SELECT FROM INNER JOIN
            if(Opcao == 2)
            {
                printf("\n\n\n-------TABELA DE FORMA DE PAGAMENTO-------\n\n");

                if(mysql_query(&conexao, "SELECT  vendas.venda_id as ID, vendas.valor_total as ValorTotal, vendas.quantidade_itens as QuantItens, forma_pagamentos.opcao as Opção FROM vendas INNER JOIN forma_pagamentos on vendas.venda_id = forma_pagamentos.pagamento_id "))
                {
                    printf("Erro: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Consulta = mysql_store_result(&conexao);
                }
                if(Consulta)
                {
                    rs_Colunas = mysql_fetch_fields(Consulta);

                    for(i = 0; i < mysql_num_fields(Consulta); i++)
                    {
                        if(mysql_num_fields(Consulta) > 1)
                        {
                            printf("|%s",(rs_Colunas[i].name));
                        }
                    }
                    printf("\n");

                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                    {
                        printf("|");
                        for(j = 0; j < mysql_num_fields(Consulta); j++)
                        {
                            printf("%s\t",rs_linhas[j]);

                        }
                        printf("\n");
                    }
                }

                mysql_free_result(Consulta);

                printf("\n-------------------------------------------\n");
            }
            else
            {
                //RELAÇÃO ENTRE ENTIDADES LIVROS E ESTOQUE, COMANDO UTILIZADO: SELECT FROM INNER JOIN
                if(Opcao == 3)
                {
                    printf("\n\n------------------------------TABELA LIVROS---------------------------\n\n");

                    if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as Ano,livros.categoria_id as Categoria,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                    {
                        printf("\n\tERRO: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        Consulta = mysql_store_result(&conexao);
                    }
                    if(Consulta)
                    {
                        rs_Colunas = mysql_fetch_fields(Consulta);

                        for(j = 0; j < mysql_num_fields(Consulta); j++)
                        {
                            if(mysql_num_fields(Consulta) > 1)
                            {
                                printf("|%s ",(rs_Colunas[j].name));
                            }
                        }
                        printf("\n");

                        while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                        {
                            printf("|");
                            for(i = 0; i < mysql_num_fields(Consulta); i++)
                            {
                                printf(" %s\t",rs_linhas[i]);
                            }
                            printf("\n");
                        }
                    }

                    mysql_free_result(Consulta);

                    printf("\n----------------------------------------------------------------------\n");
                }
                else
                {
                    //RELAÇÃO ENTRE ENTIDADES CLIENTES E PERFIS, COMANDO UTILIZADO: SELECT FROM INNER JOIN
                    if(Opcao == 4)
                    {
                        printf("\n\n------------------------------TABELA CLIENTES (PERFIL)-----------------------\n\n");

                        if(mysql_query(&conexao, "SELECT  clientes.cliente_id as ID, clientes.nome as NomeCliente,clientes.cpf as Cpf, clientes.email as Email, perfis.tipo as Perfil,perfis.desconto as Desconto, perfis.quantidade as QuantItens FROM clientes INNER JOIN perfis on perfis.perfil_id = clientes.cliente_id "))
                        {
                            printf("Erro: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            Consulta = mysql_store_result(&conexao);
                        }
                        if(Consulta)
                        {
                            rs_Colunas = mysql_fetch_fields(Consulta);

                            for(i = 0; i < mysql_num_fields(Consulta); i++)
                            {
                                if(mysql_num_fields(Consulta) > 1)
                                {
                                    printf("|%s    ",(rs_Colunas[i].name));
                                }
                            }
                            printf("\n");

                            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                            {
                                printf("|");
                                for(j = 0; j < mysql_num_fields(Consulta); j++)
                                {
                                    printf("%s\t",rs_linhas[j]);
                                }
                                printf("\n");
                            }
                        }

                        mysql_free_result(Consulta);

                        printf("\n-----------------------------------------------------------------------------\n");
                    }
                    else
                    {
                        //RELAÇÃO ENTRE FUNCIONARIOS E FUNCIONARIOS_RH, COMANDO UTILIZADO: SELECT FROM INNER JOIN
                        if(Opcao == 5)
                        {
                            printf("\n\n-----------------TABELA FUNCIONARIOS(RH)-------------\n\n");

                            if(mysql_query(&conexao, "SELECT  funcionarios.funcionario_id as ID, funcionarios.nome as Nome, funcionarios.cpf as Cpf, funcionarios_rh.cargo as Cargos, funcionarios_rh.salario as Salarios, funcionarios_rh.comissao as Comissao FROM funcionarios INNER JOIN funcionarios_rh on funcionarios_rh.rh_id = funcionarios.funcionario_id"))
                            {
                                printf("Erro: %s\n",mysql_error(&conexao));
                            }
                            else
                            {
                                Consulta = mysql_store_result(&conexao);
                            }
                            if(Consulta)
                            {
                                rs_Colunas = mysql_fetch_fields(Consulta);

                                for(i = 0; i < mysql_num_fields(Consulta); i++)
                                {
                                    if(mysql_num_fields(Consulta) > 1)
                                    {
                                        printf("|%s   ",(rs_Colunas[i].name));
                                    }
                                }
                                printf("\n");

                                while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                                {
                                    printf("|");
                                    for(j = 0; j < mysql_num_fields(Consulta); j++)
                                    {
                                        printf("%s\t",rs_linhas[j]);

                                    }
                                    printf("\n");
                                }
                            }

                            mysql_free_result(Consulta);

                            printf("\n-----------------------------------------------------\n");

                        }
                        else
                        {
                            //RELAÇÃO ENTRE  A ENTIDADE  AUTOR E LIVROS, COMANDO UTILIZADO: SELECT FROM JOIN ON JOIN
                            if(Opcao == 6)
                            {
                                printf("\n\n---------------TABELA AUTORES------------\n\n");

                                if(mysql_query(&conexao, "SELECT    a.autor_id as ID,a.nome as Nome_d_Autor, c.titulo as Titulo FROM autores a JOIN autores_livros b on a.autor_id = b.livro_id JOIN livros c on b.livro_id = c.livro_id"))
                                {
                                    printf("Erro: %s\n",mysql_error(&conexao));
                                }
                                else
                                {
                                    Consulta = mysql_store_result(&conexao);
                                }
                                if(Consulta)
                                {
                                    rs_Colunas = mysql_fetch_fields(Consulta);

                                    for(i = 0; i < mysql_num_fields(Consulta); i++)
                                    {
                                        if(mysql_num_fields(Consulta) > 1)
                                        {
                                            printf("|%s",(rs_Colunas[i].name));
                                        }
                                    }
                                    printf("\n");

                                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                                    {
                                        printf("|");
                                        for(j = 0; j < mysql_num_fields(Consulta); j++)
                                        {
                                            printf("%s \t",rs_linhas[j]);

                                        }
                                        printf("\n");
                                    }
                                }

                                mysql_free_result(Consulta);

                                printf("\n-----------------------------------------\n");

                            }
                            else
                            {
                                //RELAÇÃO ENTRE LIVROS E CATEGORIAS, COMANDO UTILIZADO: SELECT FROM  INNER JOIN
                                if(Opcao == 7)
                                {
                                    printf("\n\n-------------------------TABELA CATEGORIAS--------------------\n\n");

                                    if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as Ano,livros.titulo as Titulo,categorias.titulo as Categorias FROM livros INNER JOIN categorias on livros.livro_id = categorias.categoria_id"))
                                    {
                                        printf("Erro: %s\n",mysql_error(&conexao));
                                    }
                                    else
                                    {
                                        Consulta = mysql_store_result(&conexao);
                                    }
                                    if(Consulta)
                                    {
                                        rs_Colunas = mysql_fetch_fields(Consulta);

                                        for(i = 0; i < mysql_num_fields(Consulta); i++)
                                        {
                                            if(mysql_num_fields(Consulta) > 1)
                                            {
                                                printf("|%s   ",(rs_Colunas[i].name));
                                            }
                                        }
                                        printf("\n");
                                        while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                                        {
                                            printf("|");
                                            for(j = 0; j < mysql_num_fields(Consulta); j++)
                                            {
                                                printf("%s\t",rs_linhas[j]);

                                            }
                                            printf("\n");
                                        }
                                    }

                                    mysql_free_result(Consulta);

                                    printf("\n--------------------------------------------------------------\n");

                                }
                                else
                                {
                                    printf("\n\tConsulta de Relações entre entidades Finalizada!...\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void Insert_Cliente_e_Funcionario(MYSQL conexao, Cadastro_Cliente *Cliente, Cadastro_Funcionario *Funcionario,  Primary_Key *Primary)
{
    bool Continuar = true;

    //VARIAVEL UTILIZADA PARA REQUERIMENTO OU CONSULTA ENVIADA PARA O SISTEMA EM TROCA DE INFORMAÇÕES, TRATA-SE
    // DE UMA SOLICITAÇÃO DE DADOS, OU INFORMAÇÕES, DE UMA TABELA DO BANCO MAYSQL OU COMBINAÇÃO DE TABELAS.
    char query[1024];
    int Opcao = 0;

    printf("\n\t--------------INSERIR DADOS NO BANCO MySQL WORKBENCH----------\n\n");

    while(Continuar)
    {

        do
        {
            printf("\n\t[1] - Cadastrar dados/Clientes");
            printf("\n\t[2] - Cadastrar dados/Funcionarios");
            printf("\n\t[3] - Sair");
            printf("\n\tEntrada: ");
            fflush(stdin);
            scanf("%d",&Opcao);
            system("cls");

            if(Opcao > 3 || Opcao < 1)
            {
                printf("\n\tOpcão invalida!");
            }
        }
        while(Opcao > 3 || Opcao < 1);


        if(Opcao == 1)
        {
            int Cadastrar_Cliente = 1;
            while(Cadastrar_Cliente != 0)
            {

                printf("\n\tInforme o nome do cliente: ");
                fflush(stdin);
                gets(Cliente->Nome);
                system("cls");

                printf("\n\tInforme o CPF de %s: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Cpf);
                system("cls");

                printf("\n\tInforme o e-mail de %s: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Email);
                system("cls");

                printf("\n\tInforme a Rua que %s mora: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Rua);
                system("cls");

                printf("\n\tInforme o número da residencia de %s: ",Cliente->Nome);
                fflush(stdin);
                scanf("%d",&Cliente->Numero_Residencia);
                system("cls");

                printf("\n\tInforme o complemento do Endereço  de %s: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Complemento_Endereco);
                system("cls");

                printf("\n\tInforme o Bairro de %s: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Bairro);
                system("cls");

                printf("\n\tInforme o CEP de: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Cep);
                system("cls");

                printf("\n\tInforme a Cidade que o %s mora: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Cidade);
                system("cls");

                /*INSERINDO DADOS NA TABELA ENDERECOS, UTILIZANDO O COMANDO: INSERT INTO ... VALUES...*/
                sprintf(query,"INSERT INTO enderecos (rua,numero,complemento,bairro,cep,cidade) VALUES ('%s','%d','%s','%s','%s','%s')",Cliente->Rua,Cliente->Numero_Residencia,Cliente->Complemento_Endereco,Cliente->Bairro,Cliente->Cep,Cliente->Cidade);
                if(mysql_query(&conexao, query))
                {
                    printf("\n\tNão foi possível executar a inserção de (Clientes)\nErro: %s\n",mysql_error(&conexao));
                }
                else
                {
                    strcpy(query,"");
                    Primary->id_Endereco = mysql_insert_id(&conexao);
                    system("cls");

                    printf("\n\tEndereço do Cliente cadastrado com sucesso!...\n");
                }


                printf("\n\n\t--------------------Cadastrar Número de Telefone--------------------\n\n");

                printf("\n\tInforme o DDD do Telefone de %s : ",Cliente->Nome);
                fflush(stdin);
                scanf("%d",&Cliente->Ddd);
                system("cls");

                printf("\n\tInforme o Número de Telefone de %s: ",Cliente->Nome);
                fflush(stdin);
                gets(Cliente->Numero_Telefone);
                system("cls");


                printf("\n\tQuantidade de Itens, que o %s comprou na Livraria: ",Cliente->Nome);
                fflush(stdin);
                scanf("%d",&Cliente->Quant_Itens);
                system("cls");

                if(Cliente->Quant_Itens >= 10)
                {
                    Cliente->Desconto = 10;
                    strcpy(Cliente->Tipo,"Ouro");
                }
                else
                {
                    if(Cliente->Quant_Itens < 10 && Cliente->Quant_Itens >= 5)
                    {
                        Cliente->Desconto = 5;
                        strcpy(Cliente->Tipo,"Prata");
                    }
                    else
                    {
                        if(Cliente->Quant_Itens < 5 && Cliente->Quant_Itens >= 1)
                        {
                            Cliente->Desconto = 2;
                            strcpy(Cliente->Tipo,"Bronze");
                        }
                    }
                }

                /*INSERINDO DADOS NA TABELA TELEFONES, UTILIZANDO O COMANDO: INSERT INTO...VALUES...*/
                sprintf(query,"INSERT INTO telefones (ddd,numero) VALUES ('%d','%s')",Cliente->Ddd,Cliente->Numero_Telefone);
                if(mysql_query(&conexao, query))
                {
                    printf("\n\tNão foi possível executar a inserção de (Clientes)\nErro: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Primary->id_Telefone = mysql_insert_id(&conexao);
                    system("cls");
                    strcpy(query, "");
                }
                /*INSERINDO DADOS NA TABELA PERFIS, UTILIZANDO O COMANDO: INSERT INTO...VALUES... */
                sprintf(query,"INSERT INTO perfis (tipo,desconto,quantidade) VALUES ('%s','%d','%d')",Cliente->Tipo,Cliente->Desconto,Cliente->Quant_Itens);
                if(mysql_query(&conexao, query))
                {
                    printf("\n\tNão foi possível executar a inserção de Endereços(Clientes)\nErro: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Primary->id_Perfis = mysql_insert_id(&conexao);
                    strcpy(query, "");
                }
                /*INSERINDO DADOS NA TABELA CLIENTES, UTILIZANDO O COMANDO: INSERT INTO...VALUES...*/
                sprintf(query,"INSERT INTO clientes (nome, cpf, endereco_id, perfil_id, telefone_id, email) VALUES ('%s','%s','%d','%d','%d','%s')",Cliente->Nome,Cliente->Cpf,Primary->id_Endereco,Primary->id_Perfis,Primary->id_Telefone,Cliente->Email);
                if(mysql_query(&conexao, query))
                {
                    printf("\n\tNão foi possivel cadastrar dados do Cliente!...\n");
                }
                else
                {
                    strcpy(query,"");
                    Primary->id_Cliente = mysql_insert_id(&conexao);
                    printf("\n\tCadastro do cliente efetivado com sucesso!...\n");
                }


                printf("\n\tDeseja continuar cadastrando clientes?\n\n\t[1] - SIM\n\t[0] - NÃO\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Cadastrar_Cliente);
                system("cls");

                if(Cadastrar_Cliente == 0)
                {
                    printf("\n\tVocê saiu do cadastro de clientes!...\n");
                }
                else
                {
                    if(Cadastrar_Cliente == 1)
                        printf("\n\tContinue cadastrando clientes!...\n");
                }
            }

        }
        else
        {
            if(Opcao == 2)
            {
                int Continuar_Cadastro_Funcionario = 1;
                while(Continuar_Cadastro_Funcionario != 0)
                {

                    printf("\n\tInforme o nome do Funcionario:  ");
                    fflush(stdin);
                    gets(Funcionario->Nome);
                    system("cls");

                    printf("\n\tInforme o CPF de %s: ",Funcionario->Nome);
                    fflush(stdin);
                    gets(Funcionario->Cpf);
                    system("cls");

                    printf("\n\tInforme o e-mail de %s:  ",Funcionario->Nome);
                    fflush(stdin);
                    gets(Funcionario->Email);
                    system("cls");

                    printf("\n\tInforme o endereço de %s:  ",Funcionario->Nome);
                    fflush(stdin);
                    gets(Funcionario->Rua);
                    system("cls");

                    printf("\n\tInforme o número da residencia de %s:  ",Funcionario->Nome);
                    fflush(stdin);
                    scanf("%d",&Funcionario->Numero_Residencia);
                    system("cls");

                    printf("\n\tInforme o complemento do Endereço  de %s:  ",Funcionario->Nome);
                    fflush(stdin);
                    gets(Funcionario->Complemento_Endereco);
                    system("cls");

                    printf("\n\tInforme o Bairro de %s:  ",Funcionario->Nome);
                    fflush(stdin);
                    gets(Funcionario->Bairro);
                    system("cls");

                    printf("\n\tInforme o CEP de %s:  ",Funcionario->Nome);
                    fflush(stdin);
                    gets(Funcionario->Cep);
                    system("cls");

                    printf("\n\tInforme a Cidade que o %s mora:  ",Funcionario->Nome);
                    fflush(stdin);
                    gets(Funcionario->Cidade);
                    system("cls");


                    printf("\n\n\t--------------------Cadastrar Número de Telefone--------------------\n\n");

                    printf("\n\tInforme o DDD do Telefone:  ");
                    fflush(stdin);
                    scanf("%d",&Funcionario->Ddd);
                    system("cls");

                    printf("\n\tInforme o Número:  ");
                    fflush(stdin);
                    gets(Funcionario->Numero_Telefone);
                    system("cls");


                    /*INSERINDO DADOS NA TABELATELEFONES, UTILIZANDO O COMANDO: INSERT INTO...VALUES...*/
                    sprintf(query,"INSERT INTO telefones (ddd,numero) VALUES ('%d','%s')",Funcionario->Ddd, Funcionario->Numero_Telefone);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção de (Funcionario)\nErro: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        Primary->id_Telefone = mysql_insert_id(&conexao);
                        strcpy(query, "");

                        printf("\n\tTelefone do Funcionario cadastrado com sucesso!...\n");

                    }

                    /*INSERINDO DADOS NA TABELA ENDERECOS, UTILIZANOD O COMANDO: INSERT INTO...VALUES... */
                    sprintf(query,"INSERT INTO enderecos (rua,numero,complemento,bairro,cep,cidade) VALUES ('%s','%d','%s','%s','%s','%s')",Funcionario->Rua,Funcionario->Numero_Residencia,Funcionario->Complemento_Endereco,Funcionario->Bairro,Funcionario->Cep,Funcionario->Cidade);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção de endereço(Funcionario)\nErro: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        Primary->id_Endereco = mysql_insert_id(&conexao);

                        printf("\n\tEndereço do Funcionario cadastrado com sucesso!...\n");
                    }



                    printf("\n\t---------------Cadastrar Funcionarios no RH---------------\n");

                    printf("\n\tQual o Cargo do Funcionario:  ");
                    fflush(stdin);
                    gets(Funcionario->Cargo);
                    system("cls");

                    printf("\n\tQual o salario do Funcionario:  ");
                    fflush(stdin);
                    scanf("%f",&Funcionario->Salario);
                    system("cls");

                    printf("\n\tQual a comissão do Funcionario:  ");
                    fflush(stdin);
                    scanf("%d",&Funcionario->Comissao);
                    system("cls");

                    /*INSERE DADOS NA TABELA FUNCIONARIO_RH, COM O COMADO: INSERT INTO...VALUES...*/
                    sprintf(query,"INSERT INTO funcionarios_rh (cargo,salario,comissao) VALUES ('%s','%f','%d')",Funcionario->Cargo, Funcionario->Salario, Funcionario->Comissao);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção de Funcionario(RH)\nErro: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        Primary->id_Rh = mysql_insert_id(&conexao);

                        printf("\n\tFuncionario cadastrado no RH com sucesso!...\n");
                    }

                    /*INSERE DADOS NA TABELA FUNCIOANRIOS, COM O COMANDO: INSERT INTO...VALUES...*/
                    sprintf(query,"INSERT INTO funcionarios (nome,cpf,endereco_id,telefone_id,email,rh_id) VALUES ('%s','%s','%d','%d','%s','%d')",Funcionario->Nome, Funcionario->Cpf, Primary->id_Endereco, Primary->id_Telefone, Funcionario->Email, Primary->id_Rh);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção de Funcionario\nErro: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        Primary->id_Funcionario = mysql_insert_id(&conexao);
                        system("cls");

                        printf("\n\tFuncionario cadastrado com sucesso!...\n");
                    }


                    char Cadastrar_Usuario;

                    printf("\n\tDeseja Cadastrar Usuário para o Sistema?\n\t[S] - Sim\n\t[N] - Não\n\tEntrada:  ");
                    fflush(stdin);
                    (Cadastrar_Usuario) = getchar();
                    system("cls");

                    if(Cadastrar_Usuario == 'N' || Cadastrar_Usuario == 'n')
                    {
                        printf("\n\tUsuário não Cadastrado no sistema!\n\n");
                    }
                    else
                    {
                        if(Cadastrar_Usuario == 'S' || Cadastrar_Usuario == 's')
                            printf("\n\t---------------Cadastrar Usuário para o Sistema---------------\n");


                        printf("\n\tCadastrar Login:  ");
                        fflush(stdin);
                        gets(Funcionario->Login);
                        system("cls");

                        printf("\n\tDigite a Senha:  ");
                        fflush(stdin);
                        gets(Funcionario->Senha);
                        system("cls");

                        printf("\n\tInforme a Permissão:   ");
                        fflush(stdin);
                        scanf("%d",&Funcionario->Permissoes);
                        system("cls");

                        /*INSERE DADOS NA TABELA USUARIOS, COM O COMANDO: INSERT INTO...VALUES...*/
                        sprintf(query,"INSERT INTO usuarios (funcionario_id,login,senha,permissoes) VALUES ('%d','%s','%s','%d')",Primary->id_Funcionario, Funcionario->Login, Funcionario->Senha, Funcionario->Permissoes);
                        if(mysql_query(&conexao, query))
                        {
                            printf("\n\tNão foi possível executar a inserção de Funcionario como Usuário\nErro: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            strcpy(query,"");
                            system("cls");

                            printf("\n\tFuncionario cadastrado como Usuário, com sucesso!...\n");
                        }
                    }
                    printf("\n\tDeseja continuar cadastrando dados de Funcionario?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                    fflush(stdin);
                    scanf("%d",&Continuar_Cadastro_Funcionario);
                    system("cls");

                    if(Continuar_Cadastro_Funcionario == 1)
                    {
                        system("cls");
                        printf("\n\tContinue cadastrando!...\n\n");
                    }
                    else
                    {
                        if(Continuar_Cadastro_Funcionario == 0)
                            system("cls");
                        printf("\n\tVocê saiu da opção cadastro de funcionario!...\n");
                    }

                }

            }
            printf("\n\tVocê saiu do menu cadastro Cliente/Funcionario!...\n");
            Continuar = false;
        }

    }

}
void Insert_Estoque(MYSQL conexao, Dados_Estoque *Estoque,  Primary_Key *Primary)
{
    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consultaa; //Result Set
    MYSQL_FIELD *rs_colunas;

    char query[1024];
    int Fazer_Pedido = 1;
    int Opcao = 0, id = 0;
    int Cadastrar_Fornecedor = 0;
    int Continuar_Cadastrando_Fornecedor = 1;
    bool Continuar = true;

    while(Continuar)
    {

        printf("\n\t-------------Cadastrar Livros no Estoque-------------\n");

        do
        {
            printf("\n\t[1] - Cadastrar Fornecedores");
            printf("\n\t[2] - Fazer Pedido");
            printf("\n\t[3] - Consultar Estoque ");
            printf("\n\t[4] - Sair");
            printf("\n\tEntrada:  ");
            fflush(stdin);
            scanf("%d",&Opcao);
            system("cls");

        }
        while(Opcao > 4 || Opcao < 1);


        if(Opcao == 1)
        {

            while(Continuar_Cadastrando_Fornecedor != 0 )
            {

                printf("\n\t---------------Dados do Fornecedor---------------\n");

                printf("\n\tInforme o nome do Fornecedor:  ");
                fflush(stdin);
                gets(Estoque->Fornecedor_Nome);
                system("cls");

                printf("\n\tInforme o número de Telefone do Fornecedor (%s):  ",Estoque->Fornecedor_Nome);
                fflush(stdin);
                gets(Estoque->Fornecedor_Tel);
                system("cls");

                printf("\n\tInforme o E-mail do Fornecedor (%s):  ",Estoque->Fornecedor_Nome);
                fflush(stdin);
                gets(Estoque->Fornecedor_Email);
                system("cls");

                /*INSERE DADOS NA TABELA FORNECEDORES, COM O COMANDO: INSERT INTO...VALUES...*/
                sprintf(query,"INSERT INTO fornecedores (nome,telefone,email) VALUES ('%s','%s','%s')",Estoque->Fornecedor_Nome, Estoque->Fornecedor_Tel, Estoque->Fornecedor_Email);
                if(mysql_query(&conexao, query))
                {
                    printf("\n\tNão foi possível executar a inserção de Fornecedores\nErro: %s\n",mysql_error(&conexao));
                }
                else
                {
                    system("cls");

                    strcpy(query,"");
                    Primary->id_Fornecedor = mysql_insert_id(&conexao);
                    printf("\n\tFornecedor cadastrado com sucesso!...\n");
                }

                printf("\n\tDeseja continuar fazendo pedidos ?\n");
                printf("\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Continuar_Cadastrando_Fornecedor);
                system("cls");

                if(Continuar_Cadastrando_Fornecedor == 1 || Continuar_Cadastrando_Fornecedor == 1)
                {
                    printf("\n\n\tContinue fazendo pedidos para a Livraria!\n\n");
                }
                else
                {
                    if(Continuar_Cadastrando_Fornecedor == 0 || Continuar_Cadastrando_Fornecedor == 0)
                    {
                        printf("\n\tVocê saiu do cadastro de fornecedores!...\n");
                    }
                }

            }

        }
        else
        {
            if(Opcao == 2)
            {
                while(Fazer_Pedido != 0)
                {

                    printf("\n\n");
                    ///IMPRIME DADOS DOS FORNECEDORES.
                    if(mysql_query(&conexao, "SELECT * from fornecedores"))
                    {
                        printf("Erro: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        Consultaa = mysql_store_result(&conexao);
                    }


                    if(Consultaa)
                    {

                        rs_colunas = mysql_fetch_fields(Consultaa);

                        for(int i = 0; i < mysql_num_fields(Consultaa); i++)
                        {
                            printf("\t%s",(rs_colunas[i].name));
                            if(mysql_num_fields(Consultaa) > 1)
                            {
                                printf(" | ");
                            }
                        }
                        printf("\n");

                        while((rs_linhas = mysql_fetch_row(Consultaa)) != NULL)
                        {
                            printf("\n");
                            for(int j = 0; j < mysql_num_fields(Consultaa); j++)
                            {
                                printf("\t   %s  ",rs_linhas[j]);

                            }
                        }
                    }

                    mysql_free_result(Consultaa);

                    printf("\n\n\n\tDigite o ID do Fornecedor que deseja fazer pedido: ");
                    fflush(stdin);
                    scanf("%d",&id);
                    system("cls");

                    /*VERIFICA DADOS DE FORNECEDORES */
                    sprintf(query,"SELECT * from fornecedores where fornecedores.fornecedor_id = %d",id);

                    Primary->id_Fornecedor = Checar_Fornecedor(conexao, Estoque, query, id);


                    printf("\n\t---------------Fornecedor Escolhido---------------\n\n");

                    printf("\n\n\tId: %d\n\tNome do Fornecedor: %s\n\tTelefone: %s\n\tEmail: %s\n\n",Primary->id_Fornecedor,Estoque->Fornecedor_Nome,Estoque->Fornecedor_Tel,Estoque->Fornecedor_Email);



                    printf("\n\t-------------------Informe ao Fornecedor os dados do Livro--------------------\n");

                    printf("\n\tInforme o Titulo do livro:  ");
                    fflush(stdin);
                    gets(Estoque->Titulo);
                    system("cls");

                    printf("\n\tInforme qual é a edição do Livro %s:  ",Estoque->Titulo);
                    fflush(stdin);
                    gets(Estoque->Edicao);
                    system("cls");

                    printf("\n\tInforme o ano do Livro %s:  ",Estoque->Titulo);
                    fflush(stdin);
                    scanf("%d",&Estoque->Ano);
                    system("cls");

                    printf("\n\tInforme qual o valor do livro %s:  ",Estoque->Titulo);
                    fflush(stdin);
                    scanf("%f",&Estoque->Valor_Livro);
                    system("cls");


                    printf("\n\t-------------------Categoria do Livro %s---------------\n",Estoque->Titulo);

                    printf("\n\tInforme a Categoria do Livro:  ");
                    fflush(stdin);
                    gets(Estoque->Categoria_Titulo);
                    system("cls");

                    printf("\n\t---------------Nome do Autor do Livro %s---------------\n",Estoque->Titulo);

                    printf("\n\tInforme o nome do Autor:  ");
                    fflush(stdin);
                    gets(Estoque->Autor_Nome);
                    system("cls");

                    /*INSERE DADOS NA TABELA DE AUTORES.*/
                    sprintf(query,"INSERT INTO autores (nome) VALUES ('%s')",Estoque->Autor_Nome);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção(Autores)\nERRO: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        Primary->id_Autor = mysql_insert_id(&conexao);
                        printf("\n\tAutor inserido com sucesso!...\n");
                    }

                    /*INSERE DADOS NA TABELA DE CATEGORIAS */
                    sprintf(query,"INSERT INTO categorias (titulo) VALUES ('%s')",Estoque->Categoria_Titulo);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção(Categorias)\nERRO: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        Primary->id_Categoria = mysql_insert_id(&conexao);
                        printf("\n\tCategoria inserido com sucesso!...\n");
                    }


                    printf("\n\tInforme a quantidade de exemplares que gostaria de fazer pedido:  ");
                    fflush(stdin);
                    scanf("%d",&Estoque->Quantidade);
                    system("cls");

                    printf("\n\tInforme a Data do Pedido:  ");
                    fflush(stdin);
                    gets(Estoque->Data_Pedido);
                    system("cls");

                    printf("\n\tInforme a Data de entrega dos Livros:  ");
                    fflush(stdin);
                    gets(Estoque->Data_Recebido);
                    system("cls");

                    /*INSERE DADOS NA TABELA DE LIVROS */
                    sprintf(query,"INSERT INTO livros (titulo,edicao,ano,categoria_id,valor) VALUES ('%s','%s','%d','%d','%f')",Estoque->Categoria_Titulo, Estoque->Edicao, Estoque->Ano,Primary->id_Categoria, Estoque->Valor_Livro);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção(Categorias)\nERRO: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        Primary->id_Livro = mysql_insert_id(&conexao);
                    }

                    /*INSERE DADOS NA TABELA DE AUTORES_LIVROS.*/
                    sprintf(query,"INSERT INTO autores_livros (livro_id,autor_id) VALUES ('%d','%d')",Primary->id_Livro,Primary->id_Autor);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção(autores_livros)\nERRO: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        printf("\n\tAutor de Livros inserido com sucesso!...\n");
                    }

                    /*INSERE DADOS NA TABELA DE ESTOQUE */
                    sprintf(query,"INSERT INTO estoque (livro_id,quantidade,fornecedor_id) VALUES ('%d', '%d', '%d')",Primary->id_Livro, Estoque->Quantidade,Primary->id_Fornecedor);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção(Estoque)\nERRO: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        Primary->id_Estoque = mysql_insert_id(&conexao);
                        printf("\n\tA quantidade no estoque foi inserido com sucesso!...\n");
                    }


                    Primary->id_Estoque  = mysql_insert_id(&conexao);
                    /*INSERE DADOS NA TABELA PEDIDO */
                    sprintf(query,"INSERT INTO pedido (estoque_id,data_pedido,data_recebido) VALUES ('%d','%s','%s')",Primary->id_Estoque, Estoque->Data_Pedido, Estoque->Data_Recebido);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tNão foi possível executar a inserção o Pedido ao Fornecedor\nErro: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        strcpy(query,"");
                        printf("\n\tPedido cadastrado com sucesso!...\n");
                    }

                    printf("\n\tDeseja continuar fazendo pedidos ?\n");
                    printf("\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                    fflush(stdin);
                    scanf("%d",&Fazer_Pedido);
                    system("cls");

                    if(Fazer_Pedido == 1 || Fazer_Pedido == 1)
                    {
                        printf("\n\n\tContinue fazendo pedidos para a Livraria!\n\n");
                    }
                    else
                    {
                        if(Fazer_Pedido == 0 || Fazer_Pedido == 0)
                        {
                            printf("\n\tVocê saiu da opção fazer Pedido!...\n");
                        }
                    }
                }
            }
            else
            {
                if(Opcao == 3)
                {
                    printf("\n------------------------Situação do Estoque-----------------\n\n");

                    if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                    {
                        printf("\n\tERRO: %s\n",mysql_error(&conexao));
                    }
                    else
                    {
                        Consultaa = mysql_store_result(&conexao);
                    }
                    if(Consultaa)
                    {
                        rs_colunas = mysql_fetch_fields(Consultaa);

                        for(int j = 0; j < mysql_num_fields(Consultaa); j++)
                        {
                            if(mysql_num_fields(Consultaa) > 1)
                            {
                                printf("|%s ",(rs_colunas[j].name));
                            }
                        }
                        printf("\n");

                        while((rs_linhas = mysql_fetch_row(Consultaa)) != NULL)
                        {
                            printf("|");
                            for(int i = 0; i < mysql_num_fields(Consultaa); i++)
                            {
                                printf(" %s\t",rs_linhas[i]);
                            }
                            printf("\n");
                        }
                    }

                    mysql_free_result(Consultaa);

                    printf("\n----------------------------------------------------------\n");

                    printf("\n\tDeseja fazer pedidos, escolha a opção 2 do menu!\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\n\tVocê saiu da opção fazer pedido e consultar estoque!...\n\n");
                    Continuar = false;
                }
            }
        }
    }
}


void Realizar_Vendas(MYSQL conexao, Livraria_Vendas *Venda, Primary_Key *Primary, Dados_Venda *Dados)
{
    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consulta; //Result Set
    MYSQL_FIELD *rs_Colunas;

    char query[1024];
    int i = 0, j = 0, Achou = 0, Opcao = 0;
    bool Continuar_Comprando = true;

    printf("\n\t-------------------------VENDA INICIADA-------------------------\n\n");
    system("pause");
    system("cls");


    while(Continuar_Comprando)
    {

        printf("\n\tInforme o ID do vendedor que vai atender o cliente:  ");
        fflush(stdin);
        scanf("%d",&Primary->id_Funcionario);
        system("cls");

        /*ACIONA O COMANDO SELECT PARA TRAZER DADOS DO FUNCIONARIO*/
        sprintf(query,"SELECT * from funcionarios where funcionarios.funcionario_id = %d",Primary->id_Funcionario);

        Primary->id_Funcionario = Checar_Dados_Funcionario(conexao, query, Venda, Dados, Primary);


        printf("\n\t%s: Informe o ID do Cliente para verificar se ele possui Cadastro:  ",Dados->Nome_Funcionario);
        fflush(stdin);
        scanf("%d",&Primary->id_Cliente);
        system("cls");

        /*ACIONA O COMANDO SELECT PARA TRAZER DADOS DO CLIENTE*/
        sprintf(query,"SELECT * from clientes where clientes.cliente_id = %d",Primary->id_Cliente);

        Primary->id_Cliente = Checar_Dados_Cliente(conexao, query, Venda, Dados, Primary);

        printf("\n\t%sseja bem vinda(o)! A Livraria Recôncavo Baiano. ",Dados->Nome_Cliente);
        system("pause");
        system("cls");

        printf("\n\t%s, Informe a data para anexar a nota fiscal da venda:  ",Dados->Nome_Funcionario);
        fflush(stdin);
        gets(Venda->Data_Venda);
        system("cls");

        printf("\n\t%s, Informe o número da nota Fiscal:  ",Dados->Nome_Funcionario);
        fflush(stdin);
        scanf("%d",&Venda->Nota_Fiscal);
        system("cls");


        printf("\n\n\b");
        /*IMPRIME DADOS DE LIVROS, DISPONIVES PARA AVENDA*/
        if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as Ano,livros.categoria_id as Categoria,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
        {
            printf("\n\tERRO: %s\n",mysql_error(&conexao));
        }
        else
        {
            Consulta = mysql_store_result(&conexao);
        }
        if(Consulta)
        {
            rs_Colunas = mysql_fetch_fields(Consulta);

            for(j = 0; j < mysql_num_fields(Consulta); j++)
            {
                if(mysql_num_fields(Consulta) > 1)
                {
                    printf("|%s ",(rs_Colunas[j].name));
                }
            }
            printf("\n");

            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
            {
                printf("|");
                for(i = 0; i < mysql_num_fields(Consulta); i++)
                {
                    printf(" %s\t",rs_linhas[i]);
                }
                printf("\n");
            }
        }
        printf("\n\n");

        mysql_free_result(Consulta);


        printf("\n\t%s, Informe o ID do Livro que o cliente esta comprando:  ",Dados->Nome_Funcionario);
        fflush(stdin);
        scanf("%d",&Primary->id_Livro);
        system("cls");

        /*ACIONA O COMANDO SELECT PARA TRAZER DADOS DA TABELA LIVROS*/
        sprintf(query,"SELECT * from livros where livros.livro_id = %d",Primary->id_Livro);

        Primary->id_Livro = Checar_Dados_Livro(conexao, query, Venda, Dados, Primary);

        printf("\n\tO livro que o (a) cliente %s deseja comprar é de  %s.\n",Dados->Nome_Cliente,Dados->Nome_Livro);

        /*ACIONA O COMANDO SELECT PARA TRAZER DADOS DO ESTOQUE */
        sprintf(query,"SELECT * from estoque where estoque.estoque_id = %d",Primary->id_Livro);

        Dados->Quant_Estoque =  Checar_Dados_Estoque(conexao,  query, Venda, Dados, Primary);


        if(Dados->Quant_Estoque == 0)
        {
            printf("\n\t%s(Cliente) o estoque do  livro está indisponivel!...\n",Dados->Nome_Cliente);
            printf("\n\tVamos fazer o pedido do exemplar chegará em 10 dias, ");
            system("pause");
            system("cls");

            /*ACIONA O COMANDO UPDATE PARA ATUALIZAR O ESTOQUE */
            sprintf(query, "update estoque set quantidade = %d where livro_id = %d",Dados->Quant_Estoque + 10, Primary->id_Livro);
            if(mysql_query(&conexao,query))
            {
                printf("\n\tERRO %s\n",mysql_error(&conexao));
            }
            printf("\n\t%s, o pedido foi solicitado com sucesso pode retirar o exemplar na Livraria.\n",Dados->Nome_Cliente, Dados->Nome_Livro);
        }
        /*ACIONA O COMANDO SELECT PARA MOSTRAR A QUANTIDADE EM ESTOQUE      */
        sprintf(query,"SELECT * from estoque where estoque.estoque_id = %d",Primary->id_Livro);
        Dados->Quant_Estoque =  Checar_Dados_Estoque(conexao,  query, Venda, Dados, Primary);

        Achou = Busca_id(conexao, Primary->id_Livro, query);

        if(Achou == 1)
        {
            printf("\n\tQuantidade de exemplares disponiveis no estoque: %d livros ", Dados->Quant_Estoque);
            system("pause");
            system("cls");

            if(Dados->Quant_Estoque > 0)
            {
                printf("\n\t%s(Cliente), gostaria de adquirir quantos exemplares ?   ",Dados->Nome_Cliente);
                fflush(stdin);
                scanf("%d",&Venda->Quant_Itens);
                system("cls");

                while(Venda->Quant_Itens > Dados->Quant_Estoque || Venda->Quant_Itens == 0)
                {
                    if(Venda->Quant_Itens > Dados->Quant_Estoque || Venda->Quant_Itens == 0)
                    {
                        printf("\n\tA quantidade a ser vendida é invalida! Tente novamente!\n\n");
                        printf("\n\t%s gostaria de adquirir quantos exemplares(Livros)?   ",Dados->Nome_Cliente);
                        fflush(stdin);
                        scanf("%i",&Venda->Quant_Itens);
                        system("cls");
                    }
                }
            }
        }

        printf("\n\t%s o Valor Unitario do livro (%s) custa R$ = %.2f\n\n",Dados->Nome_Cliente, Dados->Nome_Livro, Venda->Valor_Unitario);

        printf("\n\tFavor consultar o perfil do cliente, ");
        system("pause");
        system("cls");

        /*ACIONA O COMANDO SELECT PARA TRAZER DADOS DA TABELA PERFIS.*/
        int Desconto;
        sprintf(query,"SELECT * from perfis where perfis.perfil_id = %d",Primary->id_Cliente);

        Desconto = Checar_Perfil_Cliente(conexao, query, Desconto);

        printf("\n\t-----------------Perfil do Cliente---------------\n");
        if(Desconto >= 10)
        {
            Venda->Valor_Total = Venda->Valor_Unitario - (Venda->Valor_Unitario * Desconto)/100;

            printf("\n\tCliente %s é Ouro: Desconto de 10%%\n",Dados->Nome_Cliente);
        }
        else
        {
            if(Desconto < 10 && Desconto >= 5)
            {
                Venda->Valor_Total = Venda->Valor_Unitario - (Venda->Valor_Unitario * Desconto)/100;
                printf("\n\tCliente %s é Prata: Desconto de 5%%\n",Dados->Nome_Cliente);
            }
            else
            {
                if(Desconto < 5 && Desconto >= 1)
                {
                    Venda->Valor_Total = Venda->Valor_Unitario - (Venda->Valor_Unitario * Desconto)/100;
                    printf("\n\tCliente %sé Bronze: Desconto de 2%%\n",Dados->Nome_Cliente);
                }
            }
        }

        printf("\n\n\tO livro de %s custa R$ %.2f Porém, com %d%% de desconto passa a custar RS: %.2f\n",Dados->Nome_Livro, Venda->Valor_Unitario,Desconto,Venda->Valor_Total);
        Venda->Valor_Total *= Venda->Quant_Itens;

        printf("\n\tQuantidade de livros %d, Total da compra com desconto = %.2f\n",Venda->Quant_Itens, Venda->Valor_Total);


        int Opcao_Pagamento = 0;
        printf("\n\tQual a forma de pagamento senhor (a) %s:\n\t[1] - Cartão de Credito\n\t[2] - Cartão de Debito\n\t[3] - A vista\n\tEntrada:  ",Dados->Nome_Cliente);
        fflush(stdin);
        scanf("%d",&Opcao_Pagamento);
        system("cls");

        if(Opcao_Pagamento == 1)
        {
            strcpy(Venda->Opcao_Pagamento,"Cartão");
            printf("\n\tPagamento efetuado com Cartão de Credito, ");
        }
        else
        {
            if(Opcao_Pagamento == 2)
            {
                strcpy(Venda->Opcao_Pagamento, "Cartão de Debito");
                printf("\n\tPagamento efetuado com Cartão de Debito, ");
            }
            else
            {
                if(Opcao_Pagamento == 3)
                {
                    strcpy(Venda->Opcao_Pagamento, "A Vista");
                    printf("\n\tPagamento efetuado a Vista, ");
                }
            }
        }

        /*INSERE DADOS NA TABELA FORMA_PAGAMENTOS.      */
        sprintf(query,"INSERT INTO forma_pagamentos (opcao) VALUES ('%s')",Venda->Opcao_Pagamento);
        if(mysql_query(&conexao, query))
        {
            printf("\n\tNão foi possível executar a inserção(vendas)\nERRO: %s\n",mysql_error(&conexao));
        }
        else
        {
            strcpy(query,"");
            Primary->id_Forma_Pagamento = mysql_insert_id(&conexao);
            printf("realizado com sucesso!...\n");
        }

        /*INSERE DADOS NA TABELA VENDAS*/
        sprintf(query,"INSERT INTO vendas (data_venda,valor_total,cliente_id,funcionario_id,forma_pagamento_id,nota_fiscal,quantidade_itens) VALUES ('%s','%f','%d','%d','%d','%d','%d')",Venda->Data_Venda,Venda->Valor_Total,Primary->id_Cliente,Primary->id_Funcionario,Primary->id_Forma_Pagamento,Venda->Nota_Fiscal,Venda->Quant_Itens);
        if(mysql_query(&conexao, query))
        {
            printf("\n\tNão foi possível executar a inserção(vendas)\nERRO: %s\n",mysql_error(&conexao));
        }
        else
        {
            Primary->id_Vendas = mysql_insert_id(&conexao);
            printf("\n\tVolte sempre!...\n");

            /*FAZ UM UPDATE NA QUANTIDADE DE LIVROS(ATUALIZA O ESTOQUE).*/
            sprintf(query, "update estoque set quantidade = %d where livro_id = %d",Dados->Quant_Estoque - Venda->Quant_Itens, Primary->id_Livro);
            if(mysql_query(&conexao,query))
                printf("\n\tERRO %s\n",mysql_error(&conexao));
        }
        /*INSERE DADOS NA TABELA VENDAS_LIVROS*/
        strcpy(query,"");
        sprintf(query,"INSERT INTO vendas_livros (venda_id, livro_id, valor_unitario) VALUES ('%d', '%d', '%f')",Primary->id_Vendas, Primary->id_Livro,Venda->Valor_Unitario);
        if(mysql_query(&conexao, query))
        {
            printf("\n\tNão foi possível executar a inserção em (vendas_livros)\nERRO: %s\n",mysql_error(&conexao));
        }

        printf("\n\tGostaria de continuar comprando livros?\n\t[1] - SIM\n\t[2] - NÃO\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

        if(Opcao == 1)
        {
            printf("\n\tBoas Compras!...\n");
        }
        else
        {
            if(Opcao == 2)
            {
                printf("\n\t%s,Obrigado (a) volte sempre!...\n\n",Dados->Nome_Cliente);
                Continuar_Comprando = false;
            }
        }
    }

}

int Busca_id(MYSQL conexao, int id, char query[1024])
{
    MYSQL_ROW rs_linha;
    MYSQL_RES *COnsulta;

    if(mysql_query(&conexao,query))
    {
        printf("ERRo: %s\n",mysql_error(&conexao));
    }
    else
    {
        COnsulta = mysql_store_result(&conexao);
    }

    if(COnsulta)
    {
        while((rs_linha = mysql_fetch_row(COnsulta)) != NULL)
        {
            if(id == atoi(rs_linha[0]))
            {
                return 1;
            }
        }
    }
    return 0;

}

int Checar_Dados_Cliente(MYSQL conexao, char query[1024], Livraria_Vendas *Venda, Dados_Venda *Dados, Primary_Key *Primary)
{
    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consult;

    if(mysql_query(&conexao, query))
    {
        printf("\n\tERRO: %s\n",mysql_error(&conexao));
    }
    else
    {
        Consult = mysql_store_result(&conexao);
    }

    if(Consult)
    {
        while((rs_linhas = mysql_fetch_row(Consult)) != NULL)
        {
            Primary->id_Cliente = atoi(rs_linhas[0]);
            strcpy(Dados->Nome_Cliente, rs_linhas[1]);
        }
    }
    mysql_free_result(Consult);
    return  Primary->id_Cliente;
}

int Checar_Perfil_Cliente(MYSQL conexao, char query[1024], int Desconto)
{
    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consult;

    if(mysql_query(&conexao, query))
    {
        printf("\n\tERRO: %s\n",mysql_error(&conexao));
    }
    else
    {
        Consult = mysql_store_result(&conexao);
    }

    if(Consult)
    {
        while((rs_linhas = mysql_fetch_row(Consult)) != NULL)
        {
            Desconto = atoi(rs_linhas[2]);
        }
    }
    mysql_free_result(Consult);
    return  Desconto;
}
int Checar_Dados_Funcionario(MYSQL conexao, char query[1024], Livraria_Vendas *Venda, Dados_Venda *Dados, Primary_Key *Primary)
{

    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consult;
    int ID = 0;


    if(mysql_query(&conexao, query))
    {
        printf("\n\tERRO: %s\n",mysql_error(&conexao));
    }
    else
    {
        Consult = mysql_store_result(&conexao);
    }

    if(Consult)
    {
        while((rs_linhas = mysql_fetch_row(Consult)) != NULL)
        {
            ID = atoi(rs_linhas[0]);
            strcpy(Dados->Nome_Funcionario, rs_linhas[1]);
        }
    }

    mysql_free_result(Consult);

    return ID;
}

int Checar_Dados_Estoque(MYSQL conexao, char query[1024], Livraria_Vendas *Venda, Dados_Venda *Dados, Primary_Key *Primary)
{

    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consult;
    int Quantidade;


    if(mysql_query(&conexao, query))
    {
        printf("\n\tERRO: %s\n",mysql_error(&conexao));
    }
    else
    {
        Consult = mysql_store_result(&conexao);
    }

    if(Consult)
    {
        while((rs_linhas = mysql_fetch_row(Consult)) != NULL)
        {
            Quantidade = atoi(rs_linhas[2]);
        }

    }
    mysql_free_result(Consult);

    return Quantidade;

}

int Checar_Dados_Livro(MYSQL conexao, char query[1024], Livraria_Vendas *Venda, Dados_Venda *Dados, Primary_Key *Primary)
{
    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consult;
    int ID = 0;


    if(mysql_query(&conexao, query))
    {
        printf("\n\tERRO: %s\n",mysql_error(&conexao));
    }
    else
    {
        Consult = mysql_store_result(&conexao);
    }

    if(Consult)
    {
        while((rs_linhas = mysql_fetch_row(Consult)) != NULL)
        {
            ID = atoi(rs_linhas[0]);
            strcpy(Dados->Nome_Livro, rs_linhas[1]);
            Venda->Valor_Unitario = atoi(rs_linhas[5]);
        }
    }

    mysql_free_result(Consult);

    return ID;

}

int Checar_Fornecedor(MYSQL conexao,Dados_Estoque *Estoque, char query[1024], int id)
{

    int i = 0,id_Fornecedor = 0;
    MYSQL_FIELD *rs_colunas;
    MYSQL_ROW rs_linhas;
    MYSQL_RES *Consul;

    if(mysql_query(&conexao, query))
    {
        printf("\n\tERRO: %s\n",mysql_error(&conexao));
    }
    else
    {
        Consul = mysql_store_result(&conexao);
    }

    if(Consul)
    {
        rs_colunas = mysql_fetch_fields(Consul);
        while((rs_linhas = mysql_fetch_row(Consul)) != NULL)
        {
            id_Fornecedor = atoi(rs_linhas[0]);

            strcpy(Estoque->Fornecedor_Nome, rs_linhas[1]);

            strcpy(Estoque->Fornecedor_Tel, rs_linhas[2]);

            strcpy(Estoque->Fornecedor_Email, rs_linhas[3]);


        }
    }
    mysql_free_result(Consul);

    return id_Fornecedor;
}

void Update_Livros(MYSQL conexao, Dados_Estoque  Estoque)
{
    int Opcao = 0, ID = 0, Achou = 0;
    int j = 0, i = 0;
    char query[1024];
    bool Continuar_Update = true;

    MYSQL_RES *Consulta;
    MYSQL_ROW rs_linhas;
    MYSQL_FIELD *rs_Colunas;


    printf("\n\t-------------Update Livros-------------\n");

    while(Continuar_Update)
    {
        do
        {
            printf("\n\t[1] - Alterar Titulo de um Livro");
            printf("\n\t[2] - Alterar Edição de um Livro");
            printf("\n\t[3] - Alterar Ano de um Livro");
            printf("\n\t[4] - Alterar Categoria");
            printf("\n\t[5] - Alterar Nome do Autor");
            printf("\n\t[6] - Alterar Valor do Livro");
            printf("\n\t[7] - Sair\n\tEntrada:  ");
            fflush(stdin);
            scanf("%d",&Opcao);
        }
        while(Opcao > 7 || Opcao < 1);
        system("cls");


        switch(Opcao)
        {

        case 1:

            while(Continuar_Update)
            {

                printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                {
                    printf("\n\tERRO: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Consulta = mysql_store_result(&conexao);
                }
                if(Consulta)
                {
                    rs_Colunas = mysql_fetch_fields(Consulta);

                    for(j = 0; j < mysql_num_fields(Consulta); j++)
                    {
                        if(mysql_num_fields(Consulta) > 1)
                        {
                            printf("|%s ",(rs_Colunas[j].name));
                        }
                    }
                    printf("\n");

                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                    {
                        printf("|");
                        for(i = 0; i < mysql_num_fields(Consulta); i++)
                        {
                            printf(" %s\t",rs_linhas[i]);
                        }
                        printf("\n");
                    }
                }

                mysql_free_result(Consulta);

                printf("\n----------------------------------------------------------\n");

                printf("\n\tIforme o ID do Livro que deseja alterar o Titulo:  ");
                fflush(stdin);
                scanf("%d",&ID);

                sprintf(query, "SELECT  *  from livros  where  livros.livro_id = %i ",ID);

                Achou =  Busca_id(conexao, ID, query);

                if(Achou == 1)
                {

                    printf("\n\tInforme o novo Titulo do Livro:  ");
                    fflush(stdin);
                    gets(Estoque.Titulo);

                    sprintf(query, "update livros set titulo = '%s' where livro_id = %i",Estoque.Titulo, ID);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tERRO: %s\n", mysql_error(&conexao));
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                        if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                        {
                            printf("\n\tERRO: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            Consulta = mysql_store_result(&conexao);
                        }
                        if(Consulta)
                        {
                            rs_Colunas = mysql_fetch_fields(Consulta);

                            for(j = 0; j < mysql_num_fields(Consulta); j++)
                            {
                                if(mysql_num_fields(Consulta) > 1)
                                {
                                    printf("|%s ",(rs_Colunas[j].name));
                                }
                            }
                            printf("\n");

                            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                            {
                                printf("|");
                                for(i = 0; i < mysql_num_fields(Consulta); i++)
                                {
                                    printf(" %s\t",rs_linhas[i]);
                                }
                                printf("\n");
                            }
                        }

                        mysql_free_result(Consulta);

                        printf("\n----------------------------------------------------------\n");

                        printf("\n\tTitulo atualizado com sucesso!...\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("\n\tID não consta na lista, Tente novamente!...\n");
                }

                printf("\n\tDeseja continuar fazendo Update de Titulo de Livros?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Opcao);
                system("cls");

                if(Opcao == 1)
                {
                    printf("\n\tContinue fazendo Update, escolha a opçao desejada!...\n");
                }
                else
                {
                    if(Opcao == 0)
                    {
                        printf("\n\tUpdate de Titulos de Livros, Finalizado!...\n");
                        Continuar_Update = false;
                    }
                }

            }

            Continuar_Update = true;

            break;

        case 2:

            do
            {
                printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                {
                    printf("\n\tERRO: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Consulta = mysql_store_result(&conexao);
                }
                if(Consulta)
                {
                    rs_Colunas = mysql_fetch_fields(Consulta);

                    for(j = 0; j < mysql_num_fields(Consulta); j++)
                    {
                        if(mysql_num_fields(Consulta) > 1)
                        {
                            printf("|%s ",(rs_Colunas[j].name));
                        }
                    }
                    printf("\n");

                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                    {
                        printf("|");
                        for(i = 0; i < mysql_num_fields(Consulta); i++)
                        {
                            printf(" %s\t",rs_linhas[i]);
                        }
                        printf("\n");
                    }
                }

                mysql_free_result(Consulta);

                printf("\n----------------------------------------------------------\n");

                printf("\n\tIforme o ID do Livro que deseja alterar a Edição:  ");
                fflush(stdin);
                scanf("%d",&ID);

                sprintf(query, "SELECT  *  from livros  where  livros.livro_id = %i ",ID);

                Achou =  Busca_id(conexao, ID, query);

                if(Achou == 1)
                {

                    printf("\n\tInforme a nova Edição do Livro:  ");
                    fflush(stdin);
                    gets(Estoque.Edicao);

                    sprintf(query, "update livros set edicao = '%s' where livro_id = %i",Estoque.Edicao, ID);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tERRO: %s\n", mysql_error(&conexao));
                    }
                    else
                    {
                        system("cls");

                        printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                        if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                        {
                            printf("\n\tERRO: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            Consulta = mysql_store_result(&conexao);
                        }
                        if(Consulta)
                        {
                            rs_Colunas = mysql_fetch_fields(Consulta);

                            for(j = 0; j < mysql_num_fields(Consulta); j++)
                            {
                                if(mysql_num_fields(Consulta) > 1)
                                {
                                    printf("|%s ",(rs_Colunas[j].name));
                                }
                            }
                            printf("\n");

                            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                            {
                                printf("|");
                                for(i = 0; i < mysql_num_fields(Consulta); i++)
                                {
                                    printf(" %s\t",rs_linhas[i]);
                                }
                                printf("\n");
                            }
                        }

                        mysql_free_result(Consulta);

                        printf("\n----------------------------------------------------------\n");
                        printf("\n\tEdição do livro atualizada com sucesso!...\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("\n\tID não consta na lista, Tente novamente!...\n");
                }

                printf("\n\tDeseja continuar fazendo Update de Edição de Livros?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Opcao);
                system("cls");

                if(Opcao == 1)
                {
                    printf("\n\tContinue fazendo Update, escolha a opçao desejada!...\n");
                }
                if(Opcao == 0)
                {
                    printf("\n\tUpdate de Edição de Livros, Finalizado!...\n");
                    Continuar_Update = false;
                }
            }

            while(Continuar_Update);
            Continuar_Update = true;

            break;

        case 3:

            do
            {

                printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                {
                    printf("\n\tERRO: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Consulta = mysql_store_result(&conexao);
                }
                if(Consulta)
                {
                    rs_Colunas = mysql_fetch_fields(Consulta);

                    for(j = 0; j < mysql_num_fields(Consulta); j++)
                    {
                        if(mysql_num_fields(Consulta) > 1)
                        {
                            printf("|%s ",(rs_Colunas[j].name));
                        }
                    }
                    printf("\n");

                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                    {
                        printf("|");
                        for(i = 0; i < mysql_num_fields(Consulta); i++)
                        {
                            printf(" %s\t",rs_linhas[i]);
                        }
                        printf("\n");
                    }
                }

                mysql_free_result(Consulta);

                printf("\n----------------------------------------------------------\n");

                printf("\n\tIforme o ID do Livro que deseja alterar o Ano:  ");
                fflush(stdin);
                scanf("%d",&ID);

                sprintf(query, "SELECT  *  from livros  where  livros.livro_id = %i ",ID);

                Achou =  Busca_id(conexao, ID, query);

                if(Achou == 1)
                {

                    printf("\n\tInforme o novo Ano do Livro:  ");
                    fflush(stdin);
                    scanf("%d",&Estoque.Ano);

                    sprintf(query, "update livros set ano = '%d' where livro_id = %i",Estoque.Ano, ID);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tERRO: %s\n", mysql_error(&conexao));
                    }
                    else
                    {
                        system("cls");

                        printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                        if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                        {
                            printf("\n\tERRO: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            Consulta = mysql_store_result(&conexao);
                        }
                        if(Consulta)
                        {
                            rs_Colunas = mysql_fetch_fields(Consulta);

                            for(j = 0; j < mysql_num_fields(Consulta); j++)
                            {
                                if(mysql_num_fields(Consulta) > 1)
                                {
                                    printf("|%s ",(rs_Colunas[j].name));
                                }
                            }
                            printf("\n");

                            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                            {
                                printf("|");
                                for(i = 0; i < mysql_num_fields(Consulta); i++)
                                {
                                    printf(" %s\t",rs_linhas[i]);
                                }
                                printf("\n");
                            }
                        }

                        mysql_free_result(Consulta);

                        printf("\n----------------------------------------------------------\n");
                        printf("\n\tAno do Livro atualizado com sucesso!...\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("\n\tID não consta na lista, Tente novamente!...\n");
                }

                printf("\n\tDeseja continuar fazendo Update do Ano dos Livros?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Opcao);
                system("cls");

                if(Opcao == 1)
                {
                    printf("\n\tContinue fazendo Update, escolha a opçao desejada!...\n");
                }
                if(Opcao == 0)
                {
                    printf("\n\tUpdate do Ano dos Livros, Finalizado!...\n");
                    Continuar_Update = false;
                }
            }

            while(Continuar_Update);
            Continuar_Update = true;

            break;

        case 4:

            do
            {

                printf("\n\n-------------------------TABELA CATEGORIAS--------------------\n\n");

                if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as Ano,livros.titulo as Titulo,categorias.titulo as Categorias FROM livros INNER JOIN categorias on livros.livro_id = categorias.categoria_id"))
                {
                    printf("Erro: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Consulta = mysql_store_result(&conexao);
                }
                if(Consulta)
                {
                    rs_Colunas = mysql_fetch_fields(Consulta);

                    for(i = 0; i < mysql_num_fields(Consulta); i++)
                    {
                        if(mysql_num_fields(Consulta) > 1)
                        {
                            printf("|%s   ",(rs_Colunas[i].name));
                        }
                    }
                    printf("\n");
                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                    {
                        printf("|");
                        for(j = 0; j < mysql_num_fields(Consulta); j++)
                        {
                            printf("%s\t",rs_linhas[j]);

                        }
                        printf("\n");
                    }
                }

                mysql_free_result(Consulta);

                printf("\n--------------------------------------------------------------\n");

                printf("\n\tIforme o ID do Livro que deseja alterar a Categoria:  ");
                fflush(stdin);
                scanf("%d",&ID);

                sprintf(query, "SELECT  *  from categorias  where  categorias.categoria_id = %i ",ID);

                Achou =  Busca_id(conexao, ID, query);

                if(Achou == 1)
                {

                    printf("\n\tInforme a nova Categora do Livro:  ");
                    fflush(stdin);
                    gets(Estoque.Categoria_Titulo);

                    sprintf(query, "update categorias set titulo = '%s' where categoria_id = %i",Estoque.Categoria_Titulo, ID);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tERRO: %s\n", mysql_error(&conexao));
                    }
                    else
                    {
                        system("cls");

                        printf("\n\n-------------------------TABELA CATEGORIAS--------------------\n\n");

                        if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as Ano,livros.titulo as Titulo,categorias.titulo as Categorias FROM livros INNER JOIN categorias on livros.livro_id = categorias.categoria_id"))
                        {
                            printf("Erro: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            Consulta = mysql_store_result(&conexao);
                        }
                        if(Consulta)
                        {
                            rs_Colunas = mysql_fetch_fields(Consulta);

                            for(i = 0; i < mysql_num_fields(Consulta); i++)
                            {
                                if(mysql_num_fields(Consulta) > 1)
                                {
                                    printf("|%s   ",(rs_Colunas[i].name));
                                }
                            }
                            printf("\n");
                            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                            {
                                printf("|");
                                for(j = 0; j < mysql_num_fields(Consulta); j++)
                                {
                                    printf("%s\t",rs_linhas[j]);

                                }
                                printf("\n");
                            }
                        }

                        mysql_free_result(Consulta);

                        printf("\n--------------------------------------------------------------\n");
                        printf("\n\tCategoria atualizada com sucesso!...\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("\n\tID não consta na lista, Tente novamente!...\n");
                }

                printf("\n\tDeseja continuar fazendo Update de Categorias de Livros?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Opcao);
                system("cls");

                if(Opcao == 1)
                {
                    printf("\n\tContinue fazendo Update, escolha a opçao desejada!...\n");
                }
                if(Opcao == 0)
                {
                    printf("\n\tUpdate de Categorias de Livros, Finalizado!...\n");
                    Continuar_Update = false;
                }
            }

            while(Continuar_Update);
            Continuar_Update = true;

            break;

        case 5:

            do
            {
                printf("\n\n---------------TABELA AUTORES------------\n\n");

                if(mysql_query(&conexao, "SELECT    a.autor_id as ID,a.nome as Nome_d_Autor, c.titulo as Titulo FROM autores a JOIN autores_livros b on a.autor_id = b.livro_id JOIN livros c on b.livro_id = c.livro_id"))
                {
                    printf("Erro: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Consulta = mysql_store_result(&conexao);
                }
                if(Consulta)
                {
                    rs_Colunas = mysql_fetch_fields(Consulta);

                    for(i = 0; i < mysql_num_fields(Consulta); i++)
                    {
                        if(mysql_num_fields(Consulta) > 1)
                        {
                            printf("|%s",(rs_Colunas[i].name));
                        }
                    }
                    printf("\n");

                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                    {
                        printf("|");
                        for(j = 0; j < mysql_num_fields(Consulta); j++)
                        {
                            printf("%s \t",rs_linhas[j]);

                        }
                        printf("\n");
                    }
                }

                mysql_free_result(Consulta);

                printf("\n-----------------------------------------\n");


                printf("\n\tIforme o ID do Livro que deseja alterar o Autor:  ");
                fflush(stdin);
                scanf("%d",&ID);

                sprintf(query, "SELECT  *  from autores  where  autores.autor_id = %i ",ID);

                Achou =  Busca_id(conexao, ID, query);

                if(Achou == 1)
                {

                    printf("\n\tInforme o novo nome do Autor do Livro:  ");
                    fflush(stdin);
                    gets(Estoque.Autor_Nome);

                    sprintf(query, "update autores set nome = '%s' where autor_id = %i",Estoque.Autor_Nome, ID);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tERRO: %s\n", mysql_error(&conexao));
                    }
                    else
                    {
                        system("cls");

                        printf("\n\n---------------TABELA AUTORES------------\n\n");

                        if(mysql_query(&conexao, "SELECT    a.autor_id as ID,a.nome as Nome_d_Autor, c.titulo as Titulo FROM autores a JOIN autores_livros b on a.autor_id = b.livro_id JOIN livros c on b.livro_id = c.livro_id"))
                        {
                            printf("Erro: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            Consulta = mysql_store_result(&conexao);
                        }
                        if(Consulta)
                        {
                            rs_Colunas = mysql_fetch_fields(Consulta);

                            for(i = 0; i < mysql_num_fields(Consulta); i++)
                            {
                                if(mysql_num_fields(Consulta) > 1)
                                {
                                    printf("|%s",(rs_Colunas[i].name));
                                }
                            }
                            printf("\n");

                            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                            {
                                printf("|");
                                for(j = 0; j < mysql_num_fields(Consulta); j++)
                                {
                                    printf("%s \t",rs_linhas[j]);

                                }
                                printf("\n");
                            }
                        }

                        mysql_free_result(Consulta);

                        printf("\n-----------------------------------------\n");

                        printf("\n\tAutor atualizado com sucesso!...\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("\n\tID não consta na lista, Tente novamente!...\n");
                }

                printf("\n\tDeseja continuar fazendo Update de Autores de Livros?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Opcao);
                system("cls");

                if(Opcao == 1)
                {
                    printf("\n\tContinue fazendo Update, escolha a opçao desejada!...\n");
                }
                if(Opcao == 0)
                {
                    printf("\n\tUpdate de Autores de Livros, Finalizado!...\n");
                    Continuar_Update = false;
                }
            }

            while(Continuar_Update);
            Continuar_Update = true;

            break;

        case 6:

            do
            {

                printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                {
                    printf("\n\tERRO: %s\n",mysql_error(&conexao));
                }
                else
                {
                    Consulta = mysql_store_result(&conexao);
                }
                if(Consulta)
                {
                    rs_Colunas = mysql_fetch_fields(Consulta);

                    for(j = 0; j < mysql_num_fields(Consulta); j++)
                    {
                        if(mysql_num_fields(Consulta) > 1)
                        {
                            printf("|%s ",(rs_Colunas[j].name));
                        }
                    }
                    printf("\n");

                    while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                    {
                        printf("|");
                        for(i = 0; i < mysql_num_fields(Consulta); i++)
                        {
                            printf(" %s\t",rs_linhas[i]);
                        }
                        printf("\n");
                    }
                }

                mysql_free_result(Consulta);

                printf("\n----------------------------------------------------------\n");


                printf("\n\tIforme o ID do Livro que deseja alterar o Valor ($):  ");
                fflush(stdin);
                scanf("%d",&ID);

                sprintf(query, "SELECT  *  from livros  where  livros.livro_id = %i ",ID);

                Achou =  Busca_id(conexao, ID, query);

                if(Achou == 1)
                {

                    printf("\n\tInforme o novo valor do Livro R$:  ");
                    fflush(stdin);
                    scanf("%f",&Estoque.Valor_Livro);

                    sprintf(query, "update livros set valor = '%f' where livro_id = %i",Estoque.Valor_Livro, ID);
                    if(mysql_query(&conexao, query))
                    {
                        printf("\n\tERRO: %s\n", mysql_error(&conexao));
                    }
                    else
                    {
                        system("cls");

                        printf("\n\n---------------------TABELA LIVROS-----------------------\n\n");

                        if(mysql_query(&conexao,"SELECT livros.livro_id as ID,livros.edicao as Edição,livros.ano as AnoLivro,estoque.quantidade as Quantidade,livros.valor as Valor,livros.titulo as Titulo FROM livros INNER JOIN estoque on livros.livro_id = estoque.estoque_id"))
                        {
                            printf("\n\tERRO: %s\n",mysql_error(&conexao));
                        }
                        else
                        {
                            Consulta = mysql_store_result(&conexao);
                        }
                        if(Consulta)
                        {
                            rs_Colunas = mysql_fetch_fields(Consulta);

                            for(j = 0; j < mysql_num_fields(Consulta); j++)
                            {
                                if(mysql_num_fields(Consulta) > 1)
                                {
                                    printf("|%s ",(rs_Colunas[j].name));
                                }
                            }
                            printf("\n");

                            while((rs_linhas = mysql_fetch_row(Consulta)) != NULL)
                            {
                                printf("|");
                                for(i = 0; i < mysql_num_fields(Consulta); i++)
                                {
                                    printf(" %s\t",rs_linhas[i]);
                                }
                                printf("\n");
                            }
                        }

                        mysql_free_result(Consulta);

                        printf("\n----------------------------------------------------------\n");
                        printf("\n\tValor do livro atualizado com sucesso!...\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("\n\tID não consta na lista, Tente novamente!...\n");
                }

                printf("\n\tDeseja continuar fazendo Update de valor de Livros?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
                fflush(stdin);
                scanf("%d",&Opcao);
                system("cls");

                if(Opcao == 1)
                {
                    printf("\n\tContinue fazendo Update, escolha a opçao desejada!...\n");
                }
                if(Opcao == 0)
                {
                    printf("\n\tUpdate de Valores de Livros, Finalizado!...\n");
                    Continuar_Update = false;
                }
            }

            while(Continuar_Update);
            Continuar_Update = true;

            break;

        default:

            printf("\n\tUpdate Finalizado!...\n");

        }

        if(Opcao == 7)
        {
            Continuar_Update = false;
        }
        else
        {
            printf("\n\tDeseja continuar fazendo Update na (Entidade Livros)?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
            fflush(stdin);
            scanf("%d",&Opcao);
            system("cls");

            if(Opcao == 1)
            {
                printf("\n\tContinue fazendo Update, escolha a opçao desejada!...\n");
            }
            if(Opcao == 0)
            {
                printf("\n\tUpdate Finalizado!...\n");
                Continuar_Update = false;
            }
        }
    }
}
