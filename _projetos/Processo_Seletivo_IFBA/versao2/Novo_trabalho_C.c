#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>


//FUNÇÃO QUE IMPRIME O (MENU).
int imprime_menu(int totcursos);
//**************************

//ESTRUTURA QUE FUNCIONA COMO CADASTRO DOS CURSOS OFERTADOS:
struct cadastro_curso
{
    char codigo_curso[50];
    char nome_curso[500];
    int quant_vagas;
    char turno_curso[600];
    float c,c1,c2,pcd,a;
};
//FAZ O CADASTRO DOS CURSOS.
int cadastrar_cursos_de_TI(struct cadastro_curso cad[],int totcursos);
//ALTERA OS DADOS DOS CURSOS.
void alterar_curso(struct cadastro_curso cad[],int totcursos);
//IMPRIME OS CURSOS COM TURNO.
void imprime_curso_com_turno(struct cadastro_curso cad[],int totcursos);
//______________________________________________________________________________________________________________

//ESTRUTURA QUE INSCREVE CANDIDATOS NO CURSO:
struct inscrever_candidato
{
    char nome[100];
    char nome_curso[300];
    char inscricao_turno[300];
    char cpf[20];
    float nota_enem;
    char tipo_vaga[300];
};
//INSCREVE OS CANDIDATOS.
int inscricao_do_candidato(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidato,int totcursos);
//IMPRIME A INSCRIÇÃO DO CANDIDATO COM OS DADOS CADASTRADOS.
void imprime_inscricao_do_candidato(struct inscrever_candidato candidato[],int quant_candidato);
//ALTERA A INSCRIÇÃO DO CANDIDATO COM A CONFIRMAÇÃO DO CPF CADASTRADO.
void alteracoes_do_candidato(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidato,int totcursos);
//GERA LISTA DE INSCRITOS POR CADA CURSO, SEPARADO.
void gera_lista_de_inscritos(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidato,int totcursos);

//FUNÇÃO, QUE FAZ O CALCULO PARA SEPARAR (VAGAS POR TIPOS)...
void visualizar_vaga_portipo(struct cadastro_curso cad[],int totcursos);
//FUNÇÃO QUE IMPRIME VAGAS POR TIPO
void imprime_tipos_de_vagas(struct cadastro_curso cad[],int totcursos);
//______________________________________________________________________________________________________________
//ESTRUTURA QUE RECEBE INSTRUÇÕES SOBRE CANDIDATO TIPO VAGA c1. PARA GERAR LISTA DE CLASSIFICAÇÃO:
struct tipo_vaga_c1
{
    float nota_c1;
    char cpf_c1[20];
    char nome_c1[100];
    char nome_curso_c1[300];
    char tipo_vaga_c1[300];
    char turno_curso_c1[300];
} c1[100];
//RECEBE OS DADOS CADASTRADOS PELOS CANDIDATOS,QUE CONCORREM AO TIPO DE VAGA((C1) RENDA <= 1,5 SALÁRIOS)
void classificacao_por_curso_e_tipovaga_c1(struct inscrever_candidato candidato[], struct tipo_vaga_c1 c1[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso);

//GERA A LISTA DE CLASSIFICAÇÃO DO CANDIDATO: INFORMA SE O CANDIDATO FOI APROVADO OU SE ESTA NA LISTA DE ESPERA.
void imprime_tipo_vaga_c1_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_c1 c1[],int opcaocurso,int quant_candidatos,int totcursos);
//______________________________________________________________________________________________________________
//ESTRUTURA QUE RECEBE INSTRUÇÕES SOBRE CANDIDATO TIPO VAGA c2. PARA GERAR LISTA DE CLASSIFICAÇÃO
struct tipo_vaga_c2
{
    float nota_c2;
    char cpf_c2[20];
    char nome_c2[100];
    char nome_curso_c2[300];
    char tipo_vaga_c2[300];
    char turno_curso_c2[300];
} c2[100];

//RECEBE OS DADOS CADASTRADOS PELOS CANDIDATOS,QUE CONCORREM AO TIPO DE VAGA((C2) RENDA > 1,5 SALÁRIOS)
void classificacao_por_curso_e_tipovaga_c2(struct inscrever_candidato candidato[],struct tipo_vaga_c2 c2[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso);
//GERA A LISTA DE CLASSIFICAÇÃO DO CANDIDATO: INFORMA SE O CANDIDATO FOI APROVADO OU SE ESTA NA LISTA DE ESPERA.
void imprime_tipo_vaga_c2_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_c2 c2[],int opcaocurso,int quant_candidatos,int totcursos);
//_____________________________________________________________________________________________________________
//ESTRUTURA QUE RECEBE INSTRUÇÕES SOBRE CANDIDATO TIPO VAGA PCD. PARA GERAR LISTA DE CLASSIFICAÇÃO
struct tipo_vaga_pcd
{
    float nota_pcd;
    char cpf_pcd[20];
    char nome_pcd[100];
    char nome_curso_pcd[300];
    char tipo_vaga_pcd[300];
    char turno_curso_pcd[300];
} pcd[100];
//RECEBE OS DADOS CADASTRADOS PELOS CANDIDATOS,QUE CONCORREM AO TIPO DE VAGA((PCD)PESSOAS COM DEFICIENCIA).
void classificacao_por_curso_e_tipovaga_pcd(struct inscrever_candidato candidato[],struct tipo_vaga_pcd pcd[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso);
//GERA A LISTA DE CLASSIFICAÇÃO DO CANDIDATO: INFORMA SE O CANDIDATO FOI APROVADO OU SE ESTA NA LISTA DE ESPERA.
void imprime_tipo_vaga_pcd_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_pcd pcd[],int opcaocurso,int quant_candidatos,int totcursos);
//_______________________________________________________________________________________________________________
//ESTRUTURA QUE RECEBE INSTRUÇÕES SOBRE CANDIDATO TIPO VAGA A. PARA GERAR LISTA DE CLASSIFICAÇÃO
struct tipo_vaga_a
{
    float nota_a;
    char cpf_a[20];
    char nome_a[100];
    char nome_curso_a[200];
    char tipo_vaga_a[300];
    char turno_curso_a[300];
} a[100];
//RECEBE OS DADOS CADASTRADOS PELOS CANDIDATOS,QUE CONCORREM AO TIPO DE VAGA((A) AMPLA CONCORRÊNCIA).
void classificar_por_curso_e_tipovaga_a(struct inscrever_candidato candidato[],struct tipo_vaga_a a[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso);
//GERA A LISTA DE CLASSIFICAÇÃO DO CANDIDATO: INFORMA SE O CANDIDATO FOI APROVADO OU SE ESTA NA LISTA DE ESPERA.
void imprime_tipo_vaga_a_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_a a[],int opcaocurso,int quant_candidatos,int totcursos);
//RECEBE DADOS DA STRUCT(C1,C2,PCD,A),PARA GERAR LISTA DE CLASSIFICAÇÃO
void gerar_lista_de_classificacao(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidatos,int totcursos);
//______________________________________________________________________________________________________________

struct tipo_vagac1
{
    float nota_c1;
    char cpf_c1[20];
    char nome_c1[100];
    char nome_curso_c1[300];
    char tipo_vaga_c1[300];
    char turno_curso_c1[300];

} vaga_c1[100];

void classificacao_por_tipovaga_c1(struct inscrever_candidato candidato[], struct tipo_vagac1 vaga_c1[],struct cadastro_curso cad[],int quant_candidato,int totcursos);

void imprime_tipo_vaga_c1_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagac1 vaga_c1[],int quant_candidatos,int totcursos);

struct tipo_vagac2
{
    float nota_c2;
    char cpf_c2[20];
    char nome_c2[100];
    char nome_curso_c2[300];
    char tipo_vaga_c2[300];
    char turno_curso_c2[300];

} vaga_c2[100];

void classificacao_por_tipovaga_c2(struct inscrever_candidato candidato[], struct tipo_vagac2 vaga_c2[],struct cadastro_curso cad[],int quant_candidato,int totcursos);

void imprime_tipo_vaga_c2_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagac2 vaga_c2[],int quant_candidato,int totcursos);

struct tipo_vagapcd
{
    float nota_pcd;
    char cpf_pcd[20];
    char nome_pcd[100];
    char nome_curso_pcd[300];
    char tipo_vaga_pcd[300];
    char turno_curso_pcd[300];
} vaga_pcd[100];

void classificacao_por_tipovaga_pcd(struct inscrever_candidato candidato[], struct tipo_vagapcd vaga_pcd[],struct cadastro_curso cad[],int quant_candidato,int totcursos);

void imprime_tipo_vaga_pcd_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagapcd vaga_pcd[],int quant_candidato,int totcursos);

struct tipo_vagaa
{
    float nota_a;
    char cpf_a[20];
    char nome_a[100];
    char nome_curso_a[200];
    char tipo_vaga_a[300];
    char turno_curso_a[300];
} vaga_a[100];

void classificacao_por_tipovaga_a(struct inscrever_candidato candidato[], struct tipo_vagaa vaga_a[],struct cadastro_curso cad[],int quant_candidato,int totcursos);

void imprime_tipo_vaga_a_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagaa vaga_a[],int quant_candidatos,int totcursos);

struct aprovados
{
    float nota_aprovado;
    char cpf_aprovado[100];
    char nome_aprovado[200];
    char nome_curso_aprovado[200];
    char tipo_vaga_aprovado[300];
    char turno_curso_aprovado[300];

} tipo_aprovado[100];

void classificacao_reordenada_por_curso_e_tipo_vaga_aprovado(struct inscrever_candidato candidato[],struct aprovados tipo_aprovado[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso);

struct lista_de_espera
{
    float nota_espera;
    char cpf_espera[20];
    char nome_espera[100];
    char nome_curso_espera[300];
    char tipo_vaga_espera[300];
    char turno_curso_espera[300];

    struct tipo_vaga_c1 c1;
    struct tipo_vaga_c2 c2;
    struct tipo_vaga_pcd pcd;
    struct tipo_vaga_a a;

} lista_espera[100];
void classificacao_reordenar_por_curso_e_tipovaga_espera(struct inscrever_candidato candidato[],struct tipo_vaga_c1 c1[],struct tipo_vaga_c2 c2[],struct tipo_vaga_pcd pcd[],struct tipo_vaga_a a[],struct lista_de_espera lista_espera[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso);

void imprime_tipo_vaga_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct aprovados tipo_aprovado[],struct lista_de_espera lista_espera[],int opcaocurso,int quant_candidatos,int totcursos);

int main()
{
    setlocale(LC_ALL,"portuguese");

    SetConsoleTitle("Cores com system");

    //VARIÁVEL DO TIPO BOLEANA:
    bool sair=true;//SAI DO PROGRAMA SE O USUÁRIO DIGITAR A OPÇÃO 8.
//_____________________________________________________________________________________________________________
    //VARIÁVEIS DO TIPO INTEIRO:
    int opcao=0;//UTILIZADA PARA ESCOLHER RECEBER A OPÇÃO DESEJADA DO USUÁRIO.
    int numinscricao=0;//QUANTIDADE DE INSCRIÇÃO DE CANDIDATOS
    int quant_cursos=-1;//QUANTIDADE DE CURSOS CADASTRADOS PELO USUÁRIO.
    char c[20];
//______________________________________________________________________________________________________________

    /******************************
     *STRUCT DE CADASTRO DE CURSOS*
     ******************************/
    struct cadastro_curso cad[200];

    /**********************************
     *STRUCT DE INSCRIÇÃO DO CANDIDATO*
     **********************************/
    struct inscrever_candidato candidato[100];

    /********************************************************************************************
     *ESTRUTURAS QUE RECEBEM DADOS DA STRUCT:(INSCREVER_CANDIDATO), CONFORME O SEU TIPO DE VAGA.*
     ********************************************************************************************/
    /*struct tipo_vaga_c1 c1[100];

     struct tipo_vaga_c2 c2[100];

     struct tipo_vaga_pcd pcd[100];

     struct tipo_vaga_a a[100];*/
//********************************************************************************************


    while(sair)
    {
        //FUNÇÃO(MENU):
        opcao=imprime_menu(quant_cursos);

        switch(opcao)
        {
        //CADASTRO DOS CURSOS
        case 1:

            quant_cursos++;
            //FUNÇÃO QUE RETORNA COM A QUANTIDADE DE CURSOS CADASTRADOS
            quant_cursos=cadastrar_cursos_de_TI(cad,quant_cursos);

            break;

        //ALTERA OS CURSOS CONFORME VONTADE DO USUÁRIO
        case 2:

            alterar_curso(cad,quant_cursos);

            break;

        //SEPARA E VISUALIZA VAGAS POR TIPOS.
        case 3:

            //FUNÇÃO QUE FAZ O CALCULO DE VAGAS POR TIPOS DE COTA.
            visualizar_vaga_portipo(cad,quant_cursos);
            //FUNÇÃO QUE IMPRIME TIPOS DE VAGAS.
            imprime_tipos_de_vagas(cad,quant_cursos);

            break;

        //INSCRIÇÃO DO CANDIDATO
        case 4:

            numinscricao=inscricao_do_candidato(candidato,cad,numinscricao,quant_cursos);
            //CONTADOR QUE CONTA A QUANTIDADE DE CANDIDATOS INSCRITOS
            numinscricao++;

            break;

        //ALTERA A INSCRIÇÃO DO CANDIDATO.
        case 5:

            alteracoes_do_candidato(candidato,cad,numinscricao,quant_cursos);

            break;

        //GERA A LISTA DE INSCRITOS, POR CADA CURSO SEPARADO.
        case 6:

            gera_lista_de_inscritos(candidato,cad,numinscricao,quant_cursos);

            break;

        //GERA A LISTA DE CLASSIFICAÇÃO.
        case 7:

            gerar_lista_de_classificacao(candidato,cad,numinscricao,quant_cursos);

            break;

        //SAI DO PROGRAMA:
        case 8:

            printf("\n\n\t*********************\n");
            printf("\tObrigado, boa sorte!\n\tAss: Albert");
            printf("\n\t*********************\n\n");

            sair=false;
            break;
        }

    }
    system("pause");

    return 0;

}

int imprime_menu(int totcursos)
{
    char comando[9]="color 2e";
    system(comando);

    char a;
    int x=0;

    if(totcursos==-1)
    {
        printf("                                                              ____________________________________________\n");
        printf("\t\t\t\t\t                     {Apos ler o versículo, digite qualquer tecla!}\n");
        printf("                                                              ********************************************");
        printf("\n\t\t\t\t\t                              _____________________________\n");
        printf("\t\t\t\t\t                             {***{*********************}***}\n");
        printf("\t\t\t\t\t\t                         {SEJA FORTE E CORAJOSO}");
        printf("\n\t\t\t\t\t\t                         {*****Josué: 1:9******}");
        printf("\n\t\t\t\t\t\t                         {_____________________}");
        setbuf(stdin,NULL);
        a=getchar();

        system("cls");
    }

    printf("\n\n______________________________________________________________________________________________________________________________________________________________________");
    printf("\n{*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|************************************|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|**}\n");
    printf("{_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|____PROCESSO SELETIVO DO IFBA SAJ___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|__}\n");
    printf("**********************************************************************************************************************************************************************");


    printf("\n\n\n\n                                                        \t{****************************************}\n");
    printf("                                                         \t|1 - CADASTRAR CURSO                     |");
    printf("\n                                                        \t{________________________________________}\n");
    printf("                                                        \t|****************************************|");
    printf("\n                                                        \t{2 - ALTERAR CURSO                       }");
    printf("\n                                                        \t|________________________________________|\n");
    printf("                                                         \t{****************************************}");
    printf("\n                                                        \t|3 - SEPARAR E VISUALIZAR VAGAS POR TIPOS|");
    printf("\n                                                        \t{________________________________________}\n");
    printf("                                                         \t|****************************************|");
    printf("\n                                                        \t{4 - INSCREVER CANDIDATO                 }");
    printf("\n                                                        \t|________________________________________|\n");
    printf("                                                         \t{****************************************}");
    printf("\n                                                         \t|5 - ALTERAR INSCRIÇÃO                   |");
    printf("\n                                                         \t{________________________________________}\n");
    printf("                                                         \t|****************************************|");
    printf("\n                                                        \t{6 - GERAR LISTA DE INSCRITOS            }");
    printf("\n                                                        \t|________________________________________|\n");
    printf("                                                        \t{****************************************}");
    printf("\n                                                         \t|7 - GERAR CLASSIFICAÇÃO                 |");
    printf("\n                                                        \t{________________________________________}\n");
    printf("                                                          \t|****************************************|");
    printf("\n                                                        \t{8 - SAIR                                }");
    printf("\n                                                        \t|________________________________________|\n");
    printf("                                                        \t{*******}********************************}");
    printf("\n                                                        \t\7|ENTRADA|--> ");
    setbuf(stdin,NULL);
    scanf("%d",&x);
    return x;
    system("cls");

}

int cadastrar_cursos_de_TI (struct cadastro_curso cad[],int totcursos)
{
    system("cls");
    int codigo_repetido=0;
    int continuar=0;
    int y=0,i=0,x=0;
    int opcao_cadastroturno=0;
    bool codigo_e_vaga=true;
    bool continuar_cad_cursos=true;
    bool quantidade_vagas=true;
    bool codigo_certo=true;
    char nome_curso[50];
    char confirmar_codigo[50];
    char comando[9]="color 1e";
    system(comando);

    totcursos=totcursos;
    while(continuar_cad_cursos)
    {

        for(i=0; i<=totcursos; i++)
        {
            printf("\n\n|_____________________________________________________________________________________________________________________________________________________________________|\n");
            printf("|**********************************************************************CADASTRAR %d° CURSO*****************************************************************************|\n",totcursos+1);

            codigo_e_vaga=true;
            while(codigo_e_vaga)
            {

                //SO SAI DO LAÇO DE REPETIÇÃO QUANDO O USUÁRIO DIGITA NÚMERO, PARA O CODIGO DO CURSO.
                codigo_certo=true;
                y=0;
                do
                {
                    printf("\n\t _________________________\n");
                    printf("\t|Informe o código do curso| ");
                    printf("\n\t|_________________________| ");
                    printf("\n\t|*******|*****************|");
                    printf("\n\t|ENTRADA|-->  ");
                    setbuf(stdin,NULL);
                    gets(confirmar_codigo);

                    if(isdigit(confirmar_codigo[y])!=0)
                    {
                        y++;
                        codigo_certo=false;
                        strcpy(cad[totcursos].codigo_curso,confirmar_codigo);
                    }
                    else
                    {
                        system("cls");
                        strcpy(comando,"color 4f");
                        system(comando);
                        printf("\n\a|*********************************************************************************************************************************************************************|\n");
                        printf("|                                                                O CODIGO DO CURSO NÃO PODE SER LETRA                                                                 |\n");
                        printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
                        printf("|*********************************************************************************************************************************************************************|\n\n");
                        codigo_certo=true;
                    }

                }
                while(codigo_certo);

                codigo_repetido=0;
                //CONFIRMA SE O CODIGO DO CURSO É REPETIDO
                for(y=0; y<=totcursos; y++)
                {
                    if(strcmp(confirmar_codigo,cad[y].codigo_curso)==0)
                    {
                        codigo_repetido++;
                    }

                    if(codigo_repetido==2)
                    {
                        system("cls");
                        strcpy(comando,"color 4f");
                        system(comando);

                        printf("\n\a|*********************************************************************************************************************************************************************|\n");
                        printf("|                                                     ESSE CÓDIGO JÁ FOI CADASTRADO, FAVOR INFORME OUTRO CÓDIGO!                                                      |\n");
                        printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
                        printf("|*********************************************************************************************************************************************************************|\n\n");
                        codigo_e_vaga=true;
                        break;

                    }
                    else
                    {
                        system("cls");
                        codigo_e_vaga=false;
                        strcpy(comando,"color 1e");
                        system(comando);
                    }

                }
            }

            codigo_certo=true;
            do
            {

                printf("\n\t _______________________\n");
                printf("\t|Informe o nome do curso| ");
                printf("\n\t|_______________________| ");
                printf("\n\t|*******|***************|");
                printf("\n\t|ENTRADA|-->  ");
                setbuf(stdin,NULL);
                gets(nome_curso);
                system("cls");

                if(isalpha(nome_curso[x])!=0||nome_curso[x]==32)
                {
                    x++;
                    strcpy(cad[totcursos].nome_curso,nome_curso);
                    codigo_certo=false;
                }
                else
                {
                    strcpy(comando,"color 4f");
                    system(comando);
                    printf("\n\a______________________________________________________________________________________________________________________________________________________________________");
                    printf(" |**********************************************************************************************************************************************************************|");
                    printf("|                                                               NÃO EXISTE NOME DE CURSOS COM NÚMEROS                                                                  |");
                    printf("|______________________________________________________________________________________________________________________________________________________________________|");
                    printf("|**********************************************************************************************************************************************************************|\n\n");

                }

            }
            while(codigo_certo);

            //QUANTIDADE DE VAGAS NÃO PODE SE <=0.
            quantidade_vagas=true;
            strcpy(comando,"color 1e");
            system(comando);
            while(quantidade_vagas)
            {
                printf("\n\t _____________________________\n");
                printf("\t|Quantidade de vagas ofertadas|: ");
                printf("\n\t|_____________________________|: ");
                printf("\n\t|*******|*********************|");
                printf("\n\t|ENTRADA|-->  ");
                setbuf(stdin,NULL);
                scanf("%d",&cad[totcursos].quant_vagas);


                if(cad[totcursos].quant_vagas<=0)
                {
                    system("cls");
                    strcpy(comando,"color 4f");
                    system(comando);

                    printf("\n\a|*********************************************************************************************************************************************************************|\n");
                    printf("|                                                      O CURSO NÃO PODE TER QUANTIDADE DE VAGAS = [%d]                                                                 |\n",cad[totcursos].quant_vagas);
                    printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
                    printf("|*********************************************************************************************************************************************************************|\n\n");
                    quantidade_vagas=true;
                }
                else
                {
                    system("cls");
                    strcpy(comando,"color 1e");
                    system(comando);
                    quantidade_vagas=false;
                }

            }

            //TURNO DO CURSO TEM QUE SER <=3 OU >=1
            do
            {

                printf("\n|__________________________________________________________|Escolha a opção do turno para o curso|____________________________________________________________________|\n");
                printf("|**********************************************************|*************************************|********************************************************************|\n");
                printf("\n\n\t{***************}");
                printf("\n\t{1 - Matutino   }");
                printf("\n\t{2 - Vespertino }");
                printf("\n\t{3 - Noturno    }");
                printf("\n\t|*******|********");
                printf("\n\t|ENTRADA|-->  ");

                setbuf(stdin,NULL);
                scanf("%d",&opcao_cadastroturno);
                getchar();

                if(opcao_cadastroturno>3||opcao_cadastroturno<1)
                {
                    system("cls");
                    strcpy(comando,"color 4f");
                    system(comando);
                    continuar=3;
                    printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                    printf(" |**********************************************************************************************************************************************************************|");
                    printf("|                                                                        DIGITE A OPÇÃO CORRETA!                                                                       |");
                    printf("|______________________________________________________________________________________________________________________________________________________________________|");
                    printf("|**********************************************************************************************************************************************************************|\n\n");

                }

            }
            while(opcao_cadastroturno>3||opcao_cadastroturno<1);


            if(opcao_cadastroturno==1)
            {
                strcpy(cad[totcursos].turno_curso,"Matutino");

            }
            else
            {
                if(opcao_cadastroturno==2)
                {
                    strcpy(cad[totcursos].turno_curso,"Vespertino");

                }
                else
                {
                    if(opcao_cadastroturno==3)
                    {
                        strcpy(cad[totcursos].turno_curso,"Noturno");

                    }
                }
            }

            //IMPRIME CADASTRO DO CURSO
            system("cls");
            strcpy(comando,"color 1e");
            system(comando);
            printf("\n\t***************************************\n");
            printf("\t|Codigo do curso: %s\n\t|Nome do curso: %s\n\t|Quantidade de vagas: %d\n\t|Turno do curso: %s",
                   cad[totcursos].codigo_curso,cad[totcursos].nome_curso,cad[totcursos].quant_vagas,cad[totcursos].turno_curso);
            printf("\n\t|_______________________________________\n");
            printf("\t|Curso de %s cadastrado com sucesso!|",cad[totcursos].nome_curso);
            printf("\n\t****************************************\n");

            do
            {

                printf("\n\n|______________________________________________________________|DESEJA CONTINUAR CADASTRANDO CURSOS?|________________________________________________________________|\n");
                printf("|**************************************************************|************************************|****************************************************************|\n");

                printf("\n\n\t{**********}");
                printf("\n\t{1 - [SIM] }");
                printf("\n\t{2 - [NÃO] }");
                printf("\n\t|*******|***\n");
                printf("\t|ENTRADA|--> ");

                setbuf(stdin,NULL);
                scanf("%d",&continuar);
                getchar();
                system("cls");

                if(continuar==1)
                {
                    totcursos++;
                }
                else
                {
                    if(continuar==2)
                    {
                        continuar_cad_cursos=false;
                        i=totcursos;
                    }
                    else
                    {
                        system("cls");
                        strcpy(comando,"color 4f");
                        system(comando);
                        continuar=3;
                        printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                        printf(" |**********************************************************************************************************************************************************************|");
                        printf("|                                                                        DIGITE A OPÇÃO CORRETA!                                                                       |");
                        printf("|______________________________________________________________________________________________________________________________________________________________________|");
                        printf("|**********************************************************************************************************************************************************************|\n\n");

                    }
                }

            }
            while(continuar>2||continuar<=0);
            strcpy(comando,"color 1e");
            system(comando);

        }

    }
    return totcursos;
};

void alterar_curso(struct cadastro_curso cad[],int totcursos)
{
    system("cls");
    char comparar_codigo_do_curso[50];
    int codigo_existe=0;
    int opcao_alterar_cadastrocurso=0;
    int continuar=0;
    int i=0;
    bool codigo=true;
    char comando[9];


    while(codigo)
    {
        strcpy(comando,"color 1e");
        system(comando);

        do
        {

            printf("\n\n|_____________________________________________________________________________________________________________________________________________________________________|\n");
            printf("|*************************************************************************ALTERAR CURSOS******************************************************************************|\n");

            printf("\n\n\t _______________________________________________________________________\n");
            printf("\t|Digite o codigo do curso, que você deseja alterar os dados cadastrados | ");
            printf("\n\t|_______________________________________________________________________|  ");
            printf("\n\t|*******|**************************************************************|");
            printf("\n\t|ENTRADA|-->  ");
            setbuf(stdin,NULL);
            gets(comparar_codigo_do_curso);


            for(i=0; i<=totcursos; i++)
            {
                if(strcmp(cad[i].codigo_curso,comparar_codigo_do_curso)==0)
                {
                    codigo_existe=1;
                }
            }
            if(codigo_existe==0)
            {
                system("cls");
                strcpy(comando,"color 4f");
                system(comando);
                printf("\n\n\a|*********************************************************************************************************************************************************************|\n");
                printf("|                                                    CODIGO DO CURSO INEXISTENTE, POR FAVOR DIGITE O CODIGO CORRETO!                                                  |");
                printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                printf("\n|*********************************************************************************************************************************************************************|\n\n");
            }
        }
        while(codigo_existe<=0);
        system("cls");
        strcpy(comando,"color 0c");
        system(comando);

        //CODIGO EXISTIR == 1.
        do
        {

            if(codigo_existe==1)
            {
                printf("\n\t _________________________________\n");
                printf("\t{*********************************}\n");
                printf("\t{      O QUE DESEJA ALTERAR?      }");
                printf("\n\t{_________________________________}\n");
                printf("\t{*********************************}\n\t{1 - Alterar nome do curso\t  }\n\t{2 - alterar quantidade de vagas  }\n\t{3 - Alterar turno do curso       }\n\t{4 - Todas as alternativas        }\n\t{5 - sair\t\t\t  }\n\t{*******|*************************\n\t|ENTRADA|-->  ");
                setbuf(stdin,NULL);
                scanf("%d",&opcao_alterar_cadastrocurso);
                getchar();
                system("cls");
            }

            if(opcao_alterar_cadastrocurso>5||opcao_alterar_cadastrocurso<=0)
            {
                system("cls");
                strcpy(comando,"color 4f");
                system(comando);
                printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                printf(" |**********************************************************************************************************************************************************************|");
                printf("|                                                                        DIGITE A OPÇÃO CORRETA!                                                                       |");
                printf("|______________________________________________________________________________________________________________________________________________________________________|");
                printf("|**********************************************************************************************************************************************************************|\n\n");

            }

        }
        while(opcao_alterar_cadastrocurso>5||opcao_alterar_cadastrocurso<=0);


        //ALTERA O NOME DO CURSO.
        if(opcao_alterar_cadastrocurso==1)
        {
            system("cls");
            strcpy(comando,"color 1e");
            system(comando);

            for(i=0; i<=totcursos; i++)
            {
                if(cad[i].codigo_curso==comparar_codigo_do_curso)
                {
                    printf("\n\t ___________________________________________________________\n");
                    printf("\t{**********************************************************}\n");
                    printf("\t{Alterar nome do curso de (%s) para ",cad[i].nome_curso);
                    printf("\n\t{__________________________________________________________} ");
                    printf("\n\t{*******|***************************************************");
                    printf("\n\t|ENTRADA|-->  ");
                    setbuf(stdin,NULL);
                    gets(cad[i].nome_curso);

                    codigo=false;
                }
            }
            system("cls");
            for(i=0; i<=totcursos; i++)
            {
                if(cad[i].codigo_curso==comparar_codigo_do_curso)
                {

                    printf("\n\t{********************************************\n");
                    printf("\t{Curso: %s\n\t{Quantidade de vagas: %d\n\t{Turno do curso: %s\n\t{",
                           cad[i].nome_curso,cad[i].quant_vagas,cad[i].turno_curso);
                    printf("\n\t{CURSO ALTERADO COM SUCESSO!\n");
                    printf("\t********************************************\n");
                }
            }

        }
        else

        {
            //ALTERA QUANTIDADE DE VAGAS DO CURSO
            if(opcao_alterar_cadastrocurso==2)
            {
                for(i=0; i<=totcursos; i++)
                {
                    if(cad[i].codigo_curso==comparar_codigo_do_curso)
                    {
                        do
                        {

                            printf("\n\t __________________________________________________\n");
                            printf("\t|Alterar quantidade de vagas ofertadas de (%d) para|",cad[i].quant_vagas);
                            printf("\n\t|__________________________________________________| ");
                            printf("\n\t|*******|******************************************|\n");
                            printf("\t|ENTRADA|-->  ");
                            setbuf(stdin,NULL);
                            scanf("%d",&cad[i].quant_vagas);

                            if(cad[i].quant_vagas<=0)
                            {
                                system("cls");
                                printf("\n\t\a ____________________________________________");
                                printf("\n\t|Proibido trocar quantidade de vagas para [%d]|",cad[i].quant_vagas);
                                printf("\n\t**********************************************");

                            }

                        }
                        while(cad[i].quant_vagas<=0);

                        codigo=false;
                    }
                }
                system("cls");

                for(i=0; i<=totcursos; i++)
                {
                    if(cad[i].codigo_curso==comparar_codigo_do_curso)
                    {

                        printf("\n\t************************************************************\n");
                        printf("\t{Curso: %s\n\t{Quantidade de vagas: %d\n\t{Turno do curso: %s\n\t",
                               cad[i].nome_curso,cad[i].quant_vagas,cad[i].turno_curso);
                        printf("\n\t{CURSO ALTERADO COM SUCESSO!\n");
                        printf("\t************************************************************\n");
                    }
                }

            }
            else
            {
                //ALTERA TURNO DO CURSO.
                if(opcao_alterar_cadastrocurso==3)
                {
                    for(i=0; i<=totcursos; i++)
                    {

                        if(cad[i].codigo_curso==comparar_codigo_do_curso)
                        {
                            printf("\n\t ______________________________________________\n");
                            printf("\t|Alterar turno do curso de (%s) para   |",cad[i].turno_curso);
                            printf("\n\t|______________________________________________| ");
                            printf("\n\t|*******|***************************************");
                            printf("\n\t|ENTRADA|-->  ");
                            setbuf(stdin,NULL);
                            gets(cad[i].turno_curso);
                            codigo=false;
                        }

                    }
                    system("cls");
                    for(i=0; i<=totcursos; i++)
                    {
                        if(cad[i].codigo_curso==comparar_codigo_do_curso)
                        {

                            printf("\n\t{********************************************************\n");
                            printf("\t{Curso: %s\n\t{Quantidade de vagas: %d\n\t{Turno do curso: %s\n\t",
                                   cad[i].nome_curso,cad[i].quant_vagas,cad[i].turno_curso);
                            printf("\n\t{CURSO ALTERADO COM SUCESSO!\n");
                            printf("\t********************************************************\n");
                        }
                    }

                }
                else
                {
                    //ALTERA TODAS AS OPÇÕES.
                    if(opcao_alterar_cadastrocurso==4)
                    {
                        for(i=0; i<=totcursos; i++)
                        {

                            if(cad[i].codigo_curso==comparar_codigo_do_curso)
                            {

                                printf("\n\t ___________________________________________________________\n");
                                printf("\t{**********************************************************}\n");
                                printf("\t{Alterar nome do curso de (%s) para ",cad[i].nome_curso);
                                printf("\n\t{__________________________________________________________} ");
                                printf("\n\t{*******|***************************************************");
                                printf("\n\t|ENTRADA|-->  ");
                                setbuf(stdin,NULL);
                                gets(cad[i].nome_curso);

                                printf("\n\t __________________________________________________\n");
                                printf("\t|Alterar quantidade de vagas ofertadas de (%d) para|",cad[i].quant_vagas);
                                printf("\n\t|__________________________________________________| ");
                                printf("\n\t|*******|******************************************|\n");
                                printf("\t|ENTRADA|-->  ");
                                setbuf(stdin,NULL);
                                scanf("%d",&cad[i].quant_vagas);

                                printf("\n\t ______________________________________________\n");
                                printf("\t|Alterar turno do curso de (%s) para   |",cad[i].turno_curso);
                                printf("\n\t|______________________________________________| ");
                                printf("\n\t|*******|***************************************");
                                printf("\n\t|ENTRADA|-->  ");
                                setbuf(stdin,NULL);
                                gets(cad[i].turno_curso);


                                codigo=false;
                            }

                        }
                        system("cls");
                        for(i=0; i<=totcursos; i++)
                        {
                            if(cad[i].codigo_curso==comparar_codigo_do_curso)
                            {

                                printf("\n\t{*************************************************************\n");
                                printf("\t{Curso: %s\n\t{Quantidade de vagas: %d\n\t{Turno do curso: %s\n\t",
                                       cad[i].nome_curso,cad[i].quant_vagas,cad[i].turno_curso);
                                printf("\n\t{CURSO ALTERADO COM SUCESSO!\n");
                                printf("\t*************************************************************\n");
                            }
                        }
                    }
                    else
                    {
                        //SAI DA OPÇÃO.
                        if(opcao_alterar_cadastrocurso==5)
                        {
                            system("cls");
                            strcpy(comando,"color 1e");
                            system(comando);
                            printf("\n\a|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
                            printf("|                                                                  VOCÊ SAIU DA OPÇÃO ALTERAR CURSOS!                                                                 |");
                            printf("\n|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
                            codigo=false;
                        }
                    }
                }
            }
        }


        if(opcao_alterar_cadastrocurso==5)
        {
            codigo=false;
        }
        else
        {
            strcpy(comando,"color 7d");
            system(comando);
            do
            {

                printf("\n\n|______________________________________________________________|DESEJA CONTINUAR ALTERANDO CURSOS?|________________________________________________________________|\n");
                printf("|**************************************************************|************************************|****************************************************************|\n");

                printf("\n\n\t{**********}");
                printf("\n\t{1 - [SIM] }");
                printf("\n\t{2 - [NÃO] }");
                printf("\n\t|*******|***\n");
                printf("\t|ENTRADA|--> ");
                setbuf(stdin,NULL);
                scanf("%d",&continuar);
                getchar();
                system("cls");

                if(continuar==1)
                {
                    codigo=true;

                }
                else
                {
                    if(continuar==2)
                    {
                        codigo=false;

                    }
                    else
                    {

                        strcpy(comando,"color 4f");
                        system(comando);
                        continuar=3;
                        printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                        printf(" |**********************************************************************************************************************************************************************|");
                        printf("|                                                                        DIGITE A OPÇÃO CORRETA!                                                                       |");
                        printf("|______________________________________________________________________________________________________________________________________________________________________|");
                        printf("|**********************************************************************************************************************************************************************|\n\n");

                    }
                }

            }
            while(continuar>2||continuar<1);
        }


    }

};

//IMPRIME CURSO COM TURNO.
void imprime_curso_com_turno(struct cadastro_curso cad[],int totcursos)
{
    int i=0;
    char comando[10]="color 0f";
    system(comando);

    printf("\n\t|***************CURSOS DISPONIVEIS***************|\n ");

    for(i=0; i<=totcursos; i++)
    {

        printf("\t|________________________________________________|\n");
        printf("\t|%d - %s: Turno(%s)",i+1,cad[i].nome_curso,cad[i].turno_curso);
        printf("\n\t|________________________________________________|\n");
        printf("\t|************************************************|\n");

    }

};

//IMPRIME INSCRIÇÃO DO CANDIDATO
void imprime_inscricao_do_candidato(struct inscrever_candidato candidato[],int quant_candidato)
{
    system("cls");
    char comando[20]="color 09";
    system(comando);
    char t;

    printf("\n\t***************************INSCRITO EM: %s*******************\n",candidato[quant_candidato].nome_curso);
    printf("\t|nome: %s                                                          ",candidato[quant_candidato].nome);
    printf("\n\t|curso: %s                                                       ",candidato[quant_candidato].nome_curso);
    printf("\n\t|cpf: %s                                                         ",candidato[quant_candidato].cpf);
    printf("\n\t|Turno: %s                                                       ",candidato[quant_candidato].inscricao_turno);
    printf("\n\t|tipo vaga: %s                                                   ",candidato[quant_candidato].tipo_vaga);
    printf("\n\t|Enem: %.2f                                                      ",candidato[quant_candidato].nota_enem);
    printf("\n\t|______________________________________________________________\n");
    printf("\t|Inscrição realizada com sucesso!                              |");
    printf("\n\t****************************************************************\n\n");

    printf("\t************************************************");
    printf("\n\t|Depois de conferir sua inscrição,digite enter!|");
    printf("\n\t************************************************");
    setbuf(stdin,NULL);
    t=getchar();
    system("cls");

};

//CALCULO DE VAGAS POR TIPO
void visualizar_vaga_portipo(struct cadastro_curso cad[],int totcursos)
{
    int i=0;

    for(i=0; i<=totcursos; i++)
    {
        cad[i].c=(float)cad[i].quant_vagas*0.50;
        cad[i].c1=((float)cad[i].quant_vagas*0.25);
        cad[i].c1=ceil(cad[i].c1);
        cad[i].c2=cad[i].c-cad[i].c1;
        cad[i].pcd=((float)cad[i].quant_vagas*0.05);
        cad[i].pcd=ceil(cad[i].pcd);
        cad[i].a=((float)cad[i].quant_vagas-cad[i].c)-cad[i].pcd;

    }

};

//IMPRIME QUANTIDADE DE VAGAS POR TIPO.
void imprime_tipos_de_vagas(struct cadastro_curso cad[],int totcursos)
{
    char sair;
    system("cls");
    char comando[9]="color 0c";
    system(comando);

    printf("|___________________________________________________________________|     TIPO DE VAGAS    |__________________________________________________________________________|\n");
    printf("|*******************************************************************|**********************|**************************************************************************|\n");


    for(int i=0; i<=totcursos; i++)
    {
        printf("\n\n\t\t\t\t\t                             |*******%s*******|\n",cad[i].nome_curso);

        printf("\n\t\t\t\t\t\t{**************************************************************}\n");
        printf("\t\t\t\t\t\t{Codigo do curso: %s\t\t                               }",cad[i].codigo_curso);
        printf("\n\t\t\t\t\t\t{Nome do curso: %s\t                                       }",cad[i].nome_curso);
        printf("\n\t\t\t\t\t\t{Quantidade de vagas: %d\t\t\t               }",cad[i].quant_vagas);
        printf("\n\t\t\t\t\t\t{Turno do curso: %s\t\t                       }",cad[i].turno_curso);
        printf("\n\t\t\t\t\t\t{______________________________________________________________}\n");
        printf("\t\t\t\t\t\t|                                                              |\n");
        printf("\t\t\t\t\t\t****************************************************************\n");
        printf("\t\t\t\t\t\t|Conta escola pública: %.0f vagas                                |",cad[i].c);
        printf("\n\t\t\t\t\t\t|                                                              |");
        printf("\n\t\t\t\t\t\t|1° - Renda maior ou igual a 1 salário minimo: C1 = %.0f vagas    |",cad[i].c1);
        printf("\n\t\t\t\t\t\t|2° - Renda menor que 1 salário minimo: C2 = %.0f vagas           |",cad[i].c2);
        printf("\n\t\t\t\t\t\t|______________________________________________________________|\n");
        printf("\t\t\t\t\t\t|**************************************************************|\n");
        printf("\t\t\t\t\t\t|______________________________________________________________|");
        printf("\n\t\t\t\t\t\t****************************************************************\n");
        printf("\t\t\t\t\t\t|3° - Pessoas com deficiência: PCD = %.0f vagas                   |",cad[i].pcd);
        printf("\n\t\t\t\t\t\t|______________________________________________________________|");
        printf("\n\t\t\t\t\t\t****************************************************************\n");
        printf("\t\t\t\t\t\t|4° - Ampla concorrência: A = %.0f vagas                         |",cad[i].a);
        printf("\n\t\t\t\t\t\t|______________________________________________________________|");
        printf("\n\n|_____________________________________________________________________________________________________________________________________________________________________|\n");
        printf("|*********************************************************************************************************************************************************************|\n");

    }
    printf("|Digite qualquer tecla para sair |");
    printf("\n|*******|************************|\n");
    printf("|ENTRADA|-->  ");
    setbuf(stdin,NULL);
    sair=getchar();
    system("cls");

}

//FAZ A INSCRIÇÃO DO CANDIDATO
int inscricao_do_candidato(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    system("cls");
    int i=0;
    int x=0;
    int y=0;
    int existe_cpf=0;
    int opcao_curso=0;
    int opcao_tipo_vaga=0;
    bool confirmar_cpf=true;
    bool escolheu_curso=true;
    bool digitou_cpf_com_numero=true;
    bool digitou_nome_com_letra=true;
    char c;
    char nome[50];
    char cpf[20];
    char comando[9];

    quant_candidato=quant_candidato;

    //SE NÃO EXISTIR CURSO CADASTRADO, AVISA AO USUÁRIO
    if(totcursos==-1)
    {
        system("cls");
        strcpy(comando,"color 4f");
        system(comando);
        printf("\n\a|*********************************************************************************************************************************************************************|\n");
        printf("|                                                               NÃO EXISTE CURSO CADASTRADO NO MOMENTO!                                                               |\n");
        printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
        printf("|*********************************************************************************************************************************************************************|\n\n");
        printf("\n\t _____________________________________________");
        printf("\n\t|  Não existe curso cadastrado no momento!    |");
        printf("\n\t**************|Fique esperto!|*****************");
        printf("\n\t              ****************");
        printf("\n\t               Digite ENTER!");
        setbuf(stdin,NULL);
        c=getchar();
        system("cls");
    }
    else
    {
        strcpy(comando,"color 09");
        system(comando);

        do
        {
            bool digitou_cpf_com_numero=true;

            do
            {
                printf("\n\t _________________");
                printf("\n\t{*****************}\n");
                printf("\t{Digite o seu NOME} ");
                printf("\n\t{_________________} ");
                printf("\n\t|*******|**********");
                printf("\n\t|ENTRADA|-->  ");
                setbuf(stdin,NULL);
                gets(nome);

                if(isalpha(nome[y])!=0)
                {
                    y++;
                    digitou_nome_com_letra=false;
                    strcpy(candidato[quant_candidato].nome,nome);
                }
                else
                {
                    system("cls");
                    strcpy(comando,"color 4f");
                    system(comando);
                    printf("\n|*********************************************************************************************************************************************************************|\n");
                    printf("|                                                                   NÃO EXISTE NOME COM NÚMEROS                                                                       |\n");
                    printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
                    printf("|*********************************************************************************************************************************************************************|\n\n");
                }

            }
            while(digitou_nome_com_letra);
            digitou_nome_com_letra=true;

            //USUÁRIO SO PODE USAR NÚMERO PARA O CPF.
            do
            {
                printf("\n\t _________________");
                printf("\n\t{*****************}\n");
                printf("\t{Digite o seu CPF } ");
                printf("\n\t{_________________} ");
                printf("\n\t|*******|**********");
                printf("\n\t|ENTRADA|-->  ");
                setbuf(stdin,NULL);
                gets(cpf);

                if(isdigit(cpf[x])!=0)
                {
                    x++;
                    digitou_cpf_com_numero=false;
                    strcpy(candidato[quant_candidato].cpf,cpf);
                }
                else
                {
                    system("cls");
                    strcpy(comando,"color 4f");
                    system(comando);
                    printf("\n\a|*********************************************************************************************************************************************************************|\n");
                    printf("|                                                                 NÃO EXISTE CPF COM LETRAS                                                                           |\n");
                    printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
                    printf("|*********************************************************************************************************************************************************************|\n\n");

                }

            }
            while(digitou_cpf_com_numero);
            x=0;
            //BLOQUEIO PARA INSCRIÇÃO DE CPF REPETIDO.SO É PERMITIDO UM CPF POR INSCRIÇÃO.
            for(i=-1; i<quant_candidato; i++)
            {
                if(strcmp(candidato[i].cpf,candidato[quant_candidato].cpf)==0)
                {
                    existe_cpf++;
                }
            }
            if(existe_cpf==1)
            {

                system("cls");
                strcpy(comando,"color 4f");
                system(comando);
                printf("\n\a|_____________________________________________________________________________________________________________________________________________________________________|\n");
                printf("|*********************************************************************************************************************************************************************|\n");
                printf("|                                                                  CPF %s INVÁLIDO!",candidato[quant_candidato].cpf);
                printf("\n|                                                         EXISTE UM CPF INSCRITO COM ESSE NÚMERO!                                                                     |");
                printf("\n|_____________________________________________________________________________________________________________________________________________________________________|\n");
                printf("|*********************************************************************************************************************************************************************|");
                existe_cpf=0;
            }
            else
            {
                if(existe_cpf==0)
                {
                    confirmar_cpf=false;
                    existe_cpf=0;
                }

            }

        }
        while(confirmar_cpf);

        system("cls");
        strcpy(comando,"color 09");
        system(comando);
        printf("\n\t _________________________________");
        printf("\n\t{*********************************}\n");
        printf("\t{Informe a sua nota total do ENEM } ");
        printf("\n\t{_________________________________} ");
        printf("\n\t|*******|**************************");
        printf("\n\t|ENTRADA|-->  ");
        setbuf(stdin,NULL);
        scanf("%f",&candidato[quant_candidato].nota_enem);
        system("cls");

        opcao_curso=0;

        //CANDIDATO ESCOLHE CURSO ACOMPANHADO DE TURNO.
        do
        {

            imprime_curso_com_turno(cad,totcursos);

            printf("\n\t ________________________________\n");
            printf("\t{Digite a opção do curso desejado}");
            printf("\n\t{________________________________}");
            printf("\n\t|*******|************************ ");
            printf("\n\t|ENTRADA|-->  ");
            setbuf(stdin,NULL);
            scanf("%d",&opcao_curso);
            system("cls");
            if(opcao_curso<=totcursos+1&&opcao_curso>=1)
            {
                strcpy(candidato[quant_candidato].nome_curso,cad[opcao_curso-1].nome_curso);
                strcpy(candidato[quant_candidato].inscricao_turno,cad[opcao_curso-1].turno_curso);

                escolheu_curso=false;
                opcao_curso=0;
            }
            else
            {
                printf("\n \a_____________________________________________________________________________________________________________________________________________________________________");
                printf(" \n|*********************************************************************************************************************************************************************|");
                printf("\n|                                                                        CURSO INVALIDO!                                                                              |");
                printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                printf("\n***********************************************************************************************************************************************************************\n\n");
            }

        }
        while(escolheu_curso);
        escolheu_curso=true;

        //CANDIDATO ESCOLHE VAGA POR TIPO...
        do
        {
            system("cls");
            strcpy(comando,"color 0e");
            system(comando);

            printf("\n|__________________________________________________________|INFORME O TIPO DE VAGA|___________________________________________________________________________________|\n");
            printf("|**********************************************************|**********************|***********************************************************************************|\n");

            printf("\n\t _____________________________________________________\n");
            printf("\t{\t\tCOTA ESCOLA PÚBLICA                   }");
            printf("\n\t|                                                     |");
            printf("\n\t{_____________________________________________________}\n");
            printf("\t|1 - C1: Renda maior ou igual a R$1,5 salários minimos|");
            printf("\n\t{_____________________________________________________}\n");
            printf("\t|2 - C2: Renda menor que R$1,5 salário minimo         |");
            printf("\n\t{_____________________________________________________}\n");
            printf("\t|_____________________________________________________|\n");
            printf("\t{3 - PCD: Pessoa com deficiencia                      }");
            printf("\n\t|_____________________________________________________|\n");
            printf("\t{_____________________________________________________}\n");
            printf("\t|4 - A: Ampla concorrência                            | ");
            printf("\n\t{_____________________________________________________}");
            printf("\n\t|*****************************************************|");
            printf("\n\t|ENTRADA|-->  ");

            setbuf(stdin,NULL);
            scanf("%d",&opcao_tipo_vaga);


            if(opcao_tipo_vaga==1)
            {
                strcpy(candidato[quant_candidato].tipo_vaga,"C1: Renda maior ou igual a R$ 1,5 salários");

            }
            else
            {
                if(opcao_tipo_vaga==2)
                {
                    strcpy(candidato[quant_candidato].tipo_vaga,"C2: Renda menor que R$ 1,5 salários");
                }
                else
                {
                    if(opcao_tipo_vaga==3)
                    {
                        strcpy(candidato[quant_candidato].tipo_vaga,"PCD: Pessoa com deficiencia");
                    }
                    else if(opcao_tipo_vaga==4)
                    {
                        strcpy(candidato[quant_candidato].tipo_vaga,"A: Ampla concorrência");
                    }
                }
            }
            if(opcao_tipo_vaga>4||opcao_tipo_vaga<=0)
            {
                system("cls");
                strcpy(comando,"color 4f");
                system(comando);
                printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                printf(" |**********************************************************************************************************************************************************************|");
                printf("|                                                                        DIGITE A OPÇÃO CORRETA!                                                                       |");
                printf("|______________________________________________________________________________________________________________________________________________________________________|");
                printf("|**********************************************************************************************************************************************************************|\n\n");

            }

        }
        while(opcao_tipo_vaga>4||opcao_tipo_vaga<=0);

        imprime_inscricao_do_candidato(candidato,quant_candidato);
    }
    return quant_candidato;

};

//ALTERA INSCRIÇÃO DE CANDIDATO
void alteracoes_do_candidato(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    system("cls");
    char realizar_alteracao='n';
    bool alterar_inscricao=true;
    bool confirmar_cpf=true;
    char compararcpf[15];
    int alterar_curso=1;
    int alterar_turno=0;
    int opcao_alterar_curso=0;
    int opcao_tipo_vaga=0;
    int i=0,x=0,j=0;
    int quant_turnos=0;
    int cpf_valido=0;
    char comando[10];

    do
    {
        while(alterar_inscricao)
        {

            if(realizar_alteracao=='n')
            {
                system("cls");
                strcpy(comando,"color 0e");
                system(comando);

                do
                {
                    printf("\n\t _____________________________________");
                    printf("\n\t|*************************************|\n");
                    printf("\t|Deseja realmente alterar a inscrição?|");
                    printf("\n\t|_____________________________________|");
                    printf("\n\t|*************************************|");
                    printf("\n\t|Digite: [s] para sim                 |");
                    printf("\n\t|Digite: [n] para não                 |");
                    printf("\n\t|_____________________________________|");
                    printf("\n\t|*******|*****************************|\n");
                    printf("\t|Entrada|-->  ");
                    setbuf(stdin,NULL);
                    realizar_alteracao=getchar();
                    system("cls");

                    if(realizar_alteracao=='s'||realizar_alteracao=='n')
                    {
                        x=1;

                    }

                }
                while(x!=1);
                x=0;
            }
            system("cls");
            strcpy(comando,"color 1f");
            system(comando);
            if(realizar_alteracao=='s')
            {
                //CONFERE SE O CPF FOI INSCRITO EM ALGUM CURSO
                confirmar_cpf=true;
                while(confirmar_cpf)
                {
                    printf("\n\t ___________________________________________");
                    printf("\n\t{*******************************************}\n");
                    printf("\t{Informe o CPF que foi feito(a) a inscrição } ");
                    printf("\n\t{___________________________________________} ");
                    printf("\n\t|*******|***********************************");
                    printf("\n\t|ENTRADA|-->  ");
                    setbuf(stdin,NULL);
                    gets(compararcpf);

                    //SE O CPF ESTIVER INSCRITO EM ALGUM CURSO, IMPRIME INSCRIÇÃO DO CANDIDATO
                    for(i=0; i<=quant_candidato; i++)
                    {
                        if(strcmp(candidato[i].cpf,compararcpf)==0)
                        {
                            system("cls");
                            strcpy(comando,"color 0e");
                            system(comando);
                            printf("\n\t*********CANDIDATO(A) DO CURSO (%s)******************\n",candidato[i].nome_curso);
                            printf("\t|Nome: %s                                 \n\t|CPF: %s                                 \n\t|Curso: %s                                \n\t|Turno: %s                                \n\t|Tipo vaga: %s                            \n\t|Enem: %.2f                             |"
                                   ,candidato[i].nome,candidato[i].cpf,candidato[i].nome_curso,candidato[i].inscricao_turno,candidato[i].tipo_vaga,candidato[i].nota_enem);
                            printf("\n\t*******************************************************\n\t");
                        }
                    }

                    for(i=0; i<=quant_candidato; i++)
                    {
                        if(strcmp(candidato[i].cpf,compararcpf)==0)
                        {
                            cpf_valido=1;
                            confirmar_cpf=false;
                        }

                    }
                    if(cpf_valido==0)
                    {
                        system("cls");
                        strcpy(comando,"color 4f");
                        system(comando);
                        printf("\n|_____________________________________________________________________________________________________________________________________________________________________|\n");
                        printf("|*********************************************************************************************************************************************************************|\n");
                        printf("|                                                                  CPF %s INVÁLIDO!                                                                            |",compararcpf);
                        printf("\n|                                                     NÃO EXISTE UM CPF INSCRITO COM ESSE NÚMERO!                                                                     |");
                        printf("\n|_____________________________________________________________________________________________________________________________________________________________________|\n");
                        printf("|*********************************************************************************************************************************************************************|");

                    }

                }

            }
            //MENU DE ALTERAR INSCRIÇÃO.
            if(realizar_alteracao=='s')
            {
                opcao_alterar_curso=0;
                strcpy(comando,"color 0e");
                system(comando);

                do
                {


                    printf("\n\t __________________________________");
                    printf("\n\t|**********************************|");
                    printf("\n\t|QUAL DESSAS OPÇÕES DESEJA ALTERAR?|");
                    printf("\n\t|----------------------------------|");
                    printf("\n\t|__________________________________|\n");
                    printf("\t|1 - CURSO                         |");
                    printf("\n\t|----------------------------------|\n");

                    printf("\t|2 - TURNO                         |");
                    printf("\n\t|__________________________________|\n");
                    printf("\t|3 - CURSO E TURNO                 |");
                    printf("\n\t|----------------------------------|\n");
                    printf("\t|4 - NOTA DO ENEM                  |");
                    printf("\n\t|__________________________________|\n");
                    printf("\t|5 - TIPO VAGA                     |");
                    printf("\n\t|----------------------------------|\n");
                    printf("\t|6 - SAIR                          |");
                    printf("\n\t|__________________________________|");
                    printf("\n\t|*******|**************************|\n");
                    printf("\t|ENTRADA|-->  ");
                    setbuf(stdin,NULL);
                    scanf("%d",&opcao_alterar_curso);
                    system("cls");

                    if(opcao_alterar_curso>6||opcao_alterar_curso<1)
                    {
                        strcpy(comando,"color 4f");
                        system(comando);
                        printf("\n\a _____________________________________________________________________________________________________________________________________________________________________");
                        printf(" \n|*********************************************************************************************************************************************************************|");
                        printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
                        printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                        printf("\n***********************************************************************************************************************************************************************\n\n");

                    }

                }
                while(opcao_alterar_curso>6||opcao_alterar_curso<1);

                //OPÇÃO ALTERAR CURSO
                if(opcao_alterar_curso==1)
                {
                    imprime_curso_com_turno(cad,totcursos);

                    do
                    {
                        printf("\n\t __________________________________________\n");
                        printf("\t{Digite a opção do curso que deseja alterar}");
                        printf("\n\t{__________________________________________}");
                        printf("\n\t|*******|********************************** ");
                        printf("\n\t|ENTRADA|-->  ");
                        setbuf(stdin,NULL);
                        scanf("%d",&alterar_curso);

                        if(alterar_curso>totcursos+1||alterar_curso<1)
                        {
                            system("cls");
                            imprime_curso_com_turno(cad,totcursos);

                            printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                            printf(" |**********************************************************************************************************************************************************************|");
                            printf("|                                                                        ESCOLHA A OPÇÃO CORRETA!                                                                      |");
                            printf("|______________________________________________________________________________________________________________________________________________________________________|");
                            printf("|**********************************************************************************************************************************************************************|\n\n");


                        }
                        else
                        {
                            for(i=0; i<quant_candidato; i++)
                            {

                                if(candidato[i].cpf==compararcpf&&alterar_curso>=totcursos+1||alterar_curso>=1)
                                {
                                    system("cls");
                                    strcpy(comando,"color 0a");
                                    system(comando);
                                    strcpy(candidato[i].nome_curso,cad[alterar_curso-1].nome_curso);
                                    strcpy(candidato[i].inscricao_turno,cad[alterar_curso-1].turno_curso);

                                    printf("\n\t****************Alterado com sucesso!******************\n");
                                    printf("\t|_____________________________________________________|\n");
                                    printf("\t|Nome: %s ",candidato[i].nome);
                                    printf("\n\t|CPF: %s",candidato[i].cpf);
                                    printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                    printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                    printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                    printf("\n\t|Enem: %f",candidato[i].nota_enem);
                                    printf("\n\t|\n");
                                    printf("\t********************************************************\n");

                                }

                            }
                            alterar_inscricao=false;
                        }
                    }
                    while(alterar_curso>totcursos+1||alterar_curso<=0);

                }
                else
                {
                    //OPÇÃO ALTERAR TURNO
                    if(opcao_alterar_curso==2)
                    {
                        do
                        {
                            for(i=0; i<quant_candidato; i++)
                            {
                                if(candidato[i].cpf==compararcpf)
                                {
                                    x=i;
                                }
                            }
                            for(i=0; i<=totcursos; i++)
                            {
                                if(strcmp(cad[i].nome_curso,candidato[x].nome_curso)==0)
                                {
                                    printf("\n\n\t|**********************************|");
                                    printf("\n\t %d - %s                    ",i+1,cad[i].turno_curso);
                                    quant_turnos++;
                                }
                            }
                            printf("\n\t|**********************************|");
                            printf("\n\t __________________________________ \n");
                            printf("\t|Turnos disponiveis para seu curso!|");
                            printf("\n\t|__________________________________|");
                            printf("\n\t|*******|**************************|");
                            printf("\n\t|ENTRADA|-->  ");
                            setbuf(stdin,NULL);
                            scanf("%d",&alterar_curso);

                            if(alterar_curso>totcursos+1||alterar_curso<1)
                            {
                                system("cls");
                                strcpy(comando,"color 4f");
                                system(comando);
                                printf("\n \a_____________________________________________________________________________________________________________________________________________________________________");
                                printf(" \n|*********************************************************************************************************************************************************************|");
                                printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
                                printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                                printf("\n***********************************************************************************************************************************************************************\n\n");

                            }
                            else
                            {
                                if(alterar_curso<=totcursos||alterar_curso>=1)
                                {

                                    for(i=0; i<quant_candidato; i++)
                                    {
                                        if(strcmp(candidato[i].cpf,compararcpf)==0)
                                        {
                                            system("cls");
                                            strcpy(comando,"color 0e");
                                            system(comando);

                                            strcpy(candidato[i].inscricao_turno,cad[alterar_curso-1].turno_curso);

                                            printf("\n\t*****************Alterado com sucesso!*****************\n");
                                            printf("\t|Nome: %s ",candidato[i].nome);
                                            printf("\n\t|CPF: %s",candidato[i].cpf);
                                            printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                            printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                            printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                            printf("\n\t|Enem: %f",candidato[i].nota_enem);
                                            printf("\n\t|\n");
                                            printf("\t*********************************************************\n");
                                            alterar_inscricao=false;
                                        }

                                    }
                                }
                            }

                        }
                        while(alterar_curso>totcursos+1||alterar_curso<=0);

                    }
                    else
                    {
                        //ALTERA CURSO E TURNO
                        if(opcao_alterar_curso==3)
                        {
                            imprime_curso_com_turno(cad,totcursos);

                            do
                            {
                                printf("\n\n\t _______________________________________________________________________");
                                printf("\n\t|***********************************************************************|\n");
                                printf("\t|   Digite a opção do curso,juntamente com o turno que deseja alterar   | ");
                                printf("\n\t|_______________________________________________________________________|  ");
                                printf("\n\t|*******|***************************************************************|");
                                printf("\n\t|ENTRADA|-->  ");
                                setbuf(stdin,NULL);
                                scanf("%d",&alterar_curso);

                                if(alterar_curso>totcursos+1||alterar_curso<=0)
                                {
                                    imprime_curso_com_turno(cad,totcursos);

                                    printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                                    printf(" |**********************************************************************************************************************************************************************|");
                                    printf("|                                                                        ESCOLHA A OPÇÃO CORRETA!                                                                      |");
                                    printf("|______________________________________________________________________________________________________________________________________________________________________|");
                                    printf("|**********************************************************************************************************************************************************************|\n\n");

                                }
                                else
                                {
                                    for(i=0; i<quant_candidato; i++)
                                    {

                                        if(strcmp(candidato[i].cpf,compararcpf)==0&&alterar_curso>=totcursos+1||alterar_curso>=1)
                                        {
                                            system("cls");
                                            strcpy(comando,"color 0a");
                                            system(comando);
                                            strcpy(candidato[i].nome_curso,cad[alterar_curso-1].nome_curso);
                                            strcpy(candidato[i].inscricao_turno,cad[alterar_curso-1].turno_curso);

                                            printf("\n\t****************Alterado com sucesso!******************\n");
                                            printf("\t|_____________________________________________________|\n");
                                            printf("\t|Nome: %s ",candidato[i].nome);
                                            printf("\n\t|CPF: %s",candidato[i].cpf);
                                            printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                            printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                            printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                            printf("\n\t|Enem: %f",candidato[i].nota_enem);
                                            printf("\n\t|\n");
                                            printf("\t********************************************************\n");

                                        }

                                    }
                                    alterar_inscricao=false;
                                }
                            }
                            while(alterar_curso>totcursos+1||alterar_curso<=0);

                        }
                        else
                        {
                            //ALTERA NOTA DO ENEM
                            if( opcao_alterar_curso==4)
                            {
                                for(i=0; i<=quant_candidato; i++)
                                {

                                    if(strcmp(candidato[i].cpf,compararcpf)==0)
                                    {
                                        printf("\n\t _____________________________________________");
                                        printf("\n\t{*********************************************}\n");
                                        printf("\t{Informe a sua nota do ENEM,que deseja alterar} ");
                                        printf("\n\t{_____________________________________________} ");
                                        printf("\n\t|*******|*************************************");
                                        printf("\n\t|ENTRADA|-->  ");
                                        setbuf(stdin,NULL);
                                        scanf("%f",&candidato[i].nota_enem);
                                    }
                                }

                                for(i=0; i<=quant_candidato; i++)
                                {

                                    if(strcmp(candidato[i].cpf,compararcpf)==0)
                                    {

                                        system("cls");
                                        strcpy(comando,"color 08");
                                        system(comando);
                                        printf("\n\t**********Nota alterada com sucesso!********************\n");
                                        printf("\t|______________________________________________________|\n");
                                        printf("\t|Nome: %s",candidato[i].nome);
                                        printf("\n\t|CPF: %s",candidato[i].cpf);
                                        printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                        printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                        printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                        printf("\n\t|Enem: %.2f",candidato[i].nota_enem);
                                        printf("\n\t|_______________________________________________________\n");
                                        printf("\t********************************************************\n");
                                    }

                                }
                                alterar_inscricao=false;
                            }
                            else
                            {
                                //ALTERA O TIPO DE VAGA QUE O CANDIDATO ESTA CONCORRENDO
                                if(opcao_alterar_curso==5)
                                {
                                    do
                                    {

                                        system("cls");
                                        strcpy(comando,"color 7c");
                                        system(comando);
                                        printf("\n|__________________________________________________________|INFORME O TIPO DE VAGA|___________________________________________________________________________________|\n");
                                        printf("|**********************************************************|**********************|***********************************************************************************|\n");

                                        printf("\n\t _____________________________________________________\n");
                                        printf("\t{\t\tCOTA ESCOLA PÚBLICA                   }");
                                        printf("\n\t|                                                     |");
                                        printf("\n\t{_____________________________________________________}\n");
                                        printf("\t|1 - C1: Renda maior ou igual a R$1,5 salários minimos|");
                                        printf("\n\t{_____________________________________________________}\n");
                                        printf("\t|2 - C2: Renda menor que R$1,5 salário minimo         |");
                                        printf("\n\t{_____________________________________________________}\n");
                                        printf("\t|_____________________________________________________|\n");
                                        printf("\t{3 - PCD: Pessoa com deficiencia                      }");
                                        printf("\n\t|_____________________________________________________|\n");
                                        printf("\t{_____________________________________________________}\n");
                                        printf("\t|4 - A: Ampla concorrência                            | ");
                                        printf("\n\t{_____________________________________________________}");
                                        printf("\n\t|*****************************************************|");
                                        printf("\n\t|ENTRADA|-->  ");
                                        setbuf(stdin,NULL);
                                        scanf("%d",&opcao_tipo_vaga);


                                        if(opcao_tipo_vaga==1)
                                        {
                                            for(i=0; i<quant_candidato; i++)
                                            {
                                                if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                {
                                                    strcpy(candidato[i].tipo_vaga,"C1: Renda maior ou igual a R$ 1,5 salários");

                                                }
                                            }

                                            for(i=0; i<=quant_candidato; i++)
                                            {

                                                if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                {
                                                    system("cls");
                                                    strcpy(comando,"color 0b");
                                                    system(comando);

                                                    printf("\n\t****************Cota alterada com sucesso!*************\n");
                                                    printf("\t|_____________________________________________________|\n");
                                                    printf("\t|Nome: %s ",candidato[i].nome);
                                                    printf("\n\t|CPF: %s",candidato[i].cpf);
                                                    printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                                    printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                                    printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                                    printf("\n\t|Enem: %f",candidato[i].nota_enem);
                                                    printf("\n\t|\n");
                                                    printf("\t********************************************************\n");

                                                }

                                            }
                                            alterar_inscricao=false;
                                        }
                                        else
                                        {
                                            if(opcao_tipo_vaga==2)
                                            {
                                                for(i=0; i<quant_candidato; i++)
                                                {
                                                    if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                    {
                                                        strcpy(candidato[i].tipo_vaga,"C2: Renda menor que R$ 1,5 salário");

                                                    }
                                                }

                                                for(i=0; i<=quant_candidato; i++)
                                                {

                                                    if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                    {
                                                        system("cls");
                                                        strcpy(comando,"color 0f");
                                                        system(comando);

                                                        printf("\n\t****************Cota alterada com sucesso!*************\n");
                                                        printf("\t|_____________________________________________________|\n");
                                                        printf("\t|Nome: %s ",candidato[i].nome);
                                                        printf("\n\t|CPF: %s",candidato[i].cpf);
                                                        printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                                        printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                                        printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                                        printf("\n\t|Enem: %f",candidato[i].nota_enem);
                                                        printf("\n\t|\n");
                                                        printf("\t********************************************************\n");


                                                    }

                                                }
                                                alterar_inscricao=false;
                                            }
                                            else
                                            {
                                                if(opcao_tipo_vaga==3)
                                                {
                                                    for(i=0; i<=quant_candidato; i++)
                                                    {
                                                        if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                        {
                                                            strcpy(candidato[i].tipo_vaga,"PCD: Pessoa com deficiencia");

                                                        }
                                                    }

                                                    for(i=0; i<=quant_candidato; i++)
                                                    {

                                                        if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                        {
                                                            system("cls");
                                                            strcpy(comando,"color 0d");
                                                            system(comando);

                                                            printf("\n\t****************Cota alterada com sucesso!*************\n");
                                                            printf("\t|_____________________________________________________|\n");
                                                            printf("\t|Nome: %s ",candidato[i].nome);
                                                            printf("\n\t|CPF: %s",candidato[i].cpf);
                                                            printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                                            printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                                            printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                                            printf("\n\t|Enem: %f",candidato[i].nota_enem);
                                                            printf("\n\t|\n");
                                                            printf("\t********************************************************\n");


                                                        }

                                                    }
                                                    alterar_inscricao=false;
                                                }
                                                else if(opcao_tipo_vaga==4)
                                                {
                                                    for(i=0; i<=quant_candidato; i++)
                                                    {
                                                        if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                        {
                                                            strcpy(candidato[i].tipo_vaga,"A: Ampla concorrência");

                                                        }
                                                    }

                                                    for(i=0; i<=quant_candidato; i++)
                                                    {

                                                        if(strcmp(candidato[i].cpf,compararcpf)==0)
                                                        {
                                                            system("cls");
                                                            strcpy(comando,"color 09");
                                                            system(comando);

                                                            printf("\n\t****************Cota alterada com sucesso!*************\n");
                                                            printf("\t|_____________________________________________________|\n");
                                                            printf("\t|Nome: %s ",candidato[i].nome);
                                                            printf("\n\t|CPF: %s",candidato[i].cpf);
                                                            printf("\n\t|Curso: %s",candidato[i].nome_curso);
                                                            printf("\n\t|Turno: %s",candidato[i].inscricao_turno);
                                                            printf("\n\t|Tipo vaga: %s",candidato[i].tipo_vaga);
                                                            printf("\n\t|Enem: %f",candidato[i].nota_enem);
                                                            printf("\n\t|\n");
                                                            printf("\t********************************************************\n");


                                                        }

                                                    }
                                                    alterar_inscricao=false;
                                                }
                                            }
                                        }
                                        if(opcao_tipo_vaga>5||opcao_tipo_vaga<=0)
                                        {
                                            printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                                            printf(" |**********************************************************************************************************************************************************************|");
                                            printf("|                                                                        DIGITE A OPÇÃO CORRETA!                                                                       |");
                                            printf("|______________________________________________________________________________________________________________________________________________________________________|");
                                            printf("|**********************************************************************************************************************************************************************|\n\n");

                                        }
                                    }
                                    while(opcao_tipo_vaga>5||opcao_tipo_vaga<=0);
                                }
                                else
                                {
                                    if(opcao_alterar_curso==6)
                                    {
                                        alterar_inscricao=false;
                                    }
                                }

                            }
                        }
                    }
                }
            }
            else
            {
                if(realizar_alteracao=='n')
                {
                    system("cls");
                    strcpy(comando,"color 4f");
                    system(comando);
                    printf("\n ______________________________________________________________________________________________________________________________________________________________________");
                    printf(" |**********************************************************************************************************************************************************************|");
                    printf("|                                                                        ALTERAÇÃO NÃO REALIZADA!                                                                      |");
                    printf("|______________________________________________________________________________________________________________________________________________________________________|");
                    printf("|**********************************************************************************************************************************************************************|\n\n");

                    alterar_inscricao=false;
                }
            }
        }

        if(realizar_alteracao=='n'||opcao_alterar_curso==6)
        {
            alterar_inscricao=false;
        }
        else
        {
            do
            {

                printf("\n\t _____________________________________");
                printf("\n\t|*************************************|\n");
                printf("\t|  CONTINUAR ALTERANDO A INSCRIÇÃO?   |");
                printf("\n\t|_____________________________________|");
                printf("\n\t|*************************************|");
                printf("\n\t|Digite: [s] para sim                 |");
                printf("\n\t|Digite: [n] para não                 |");
                printf("\n\t|_____________________________________|");
                printf("\n\t|*******|*****************************|\n");
                printf("\t|Entrada|-->  ");
                setbuf(stdin,NULL);
                realizar_alteracao=getchar();

                if(realizar_alteracao=='s'||realizar_alteracao=='n')
                {
                    alterar_inscricao=true;
                    x=1;
                }
            }
            while(x!=1);
        }

    }
    while(alterar_inscricao);

};

//GERA LISTA DE INSCRITOS POR CURSO
void gera_lista_de_inscritos(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    system("cls");
    int y=0;
    int i=0;
    int opcao=0;
    int opcao_tipo_cota=0;
    int continuar=0;
    bool gerar_inscritos=true;
    char comando[10]="color 2e";
    system(comando);

    if(quant_candidato<=0)
    {
        printf("\n\tNão tem candidato!");
    }

    do
    {
        do
        {

            printf("\n|__________________________________________________________|       Gerar lista de inscritos      |____________________________________________________________________|\n");
            printf("|**********************************************************|*************************************|********************************************************************|\n");
            printf("\n\n\t{*********************************}");
            printf("\n\t{1 - Gerar Lista Por Curso        }");
            printf("\n\t{2 - Gerar Lista por Tipo de Vaga }");
            printf("\n\t{3 - Sair                         }");
            printf("\n\t|*******|**************************");
            printf("\n\t|ENTRADA|-->  ");
            setbuf(stdin,NULL);
            scanf("%d",&opcao);

            if(opcao>3||opcao<1)
            {
                printf("\n \a_____________________________________________________________________________________________________________________________________________________________________");
                printf(" \n|*********************************************************************************************************************************************************************|");
                printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
                printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                printf("\n***********************************************************************************************************************************************************************\n\n");

            }

        }
        while(opcao>3||opcao<1);

        if(opcao==1)
        {
            for(y=0; y<=totcursos; y++)
            {
                printf("\n\n\t|**********************************%s*******************************|\n",cad[y].nome_curso);
                printf("\t|__________________________________________________________________|\n\n");
                for(i=0; i<quant_candidato; i++)
                {

                    if(strcmp(candidato[i].nome_curso,cad[y].nome_curso)==0)
                    {
                        printf("\n\t|**********%s************************|\n",candidato[i].nome);
                        printf("\t|_______________________________________________________\n");
                        printf("\t|*******************************************************|\n");
                        printf("\t|Nome: %s                                 \n\t|CPF: %s                                 \n\t|Curso: %s                                \n\t|Turno: %s                                \n\t|Tipo vaga: %s                            \n\t|Enem: %.2f                             "
                               ,candidato[i].nome,candidato[i].cpf,candidato[i].nome_curso,candidato[i].inscricao_turno,candidato[i].tipo_vaga,candidato[i].nota_enem);
                        printf("\n\t|_______________________________________________________|\n");
                        printf("\t*********************************************************\n\n");
                    }
                }

            }

        }
        else
        {
            if(opcao==2)
            {
                printf("\n|______________________________________________________________________|INFORME O TIPO DE VAGA|_______________________________________________________________________|\n");
                printf("|**********************************************************************|**********************|***********************************************************************|\n");

                do
                {
                    printf("\n\t _____________________________________________________\n");
                    printf("\t{\t\tCOTA ESCOLA PÚBLICA                   }");
                    printf("\n\t|                                                     |");
                    printf("\n\t{_____________________________________________________}\n");
                    printf("\t|1 - C1: Renda maior ou igual a R$1,5 salários minimos|");
                    printf("\n\t{_____________________________________________________}\n");
                    printf("\t|2 - C2: Renda menor que R$1,5 salário minimo         |");
                    printf("\n\t{_____________________________________________________}\n");
                    printf("\t|_____________________________________________________|\n");
                    printf("\t{3 - PCD: Pessoa com deficiencia                      }");
                    printf("\n\t|_____________________________________________________|\n");
                    printf("\t{_____________________________________________________}\n");
                    printf("\t|4 - A: Ampla concorrência                            | ");
                    printf("\n\t{_____________________________________________________}");
                    printf("\n\t|*****************************************************|");
                    printf("\n\t|ENTRADA|-->  ");
                    setbuf(stdin,NULL);
                    scanf("%d",&opcao_tipo_cota);

                    if(opcao_tipo_cota>4||opcao_tipo_cota<1)
                    {
                        printf("\n \a_____________________________________________________________________________________________________________________________________________________________________");
                        printf(" \n|*********************************************************************************************************************************************************************|");
                        printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
                        printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                        printf("\n***********************************************************************************************************************************************************************\n\n");

                    }

                }
                while(opcao_tipo_cota>4||opcao_tipo_cota<1);

                if(opcao_tipo_cota==1)
                {
                    system("cls");
                    printf("\n|_______________________________________________________________|C1: Renda maior ou igual a R$ 1,5 salários|__________________________________________________________|\n");
                    printf("|*********************************************************************************************************************************************************************|\n");

                    for(i=0; i<quant_candidato; i++)
                    {
                        if(strcmp(candidato[i].tipo_vaga,"C1: Renda maior ou igual a R$ 1,5 salários")==0)
                        {
                            printf("\t|_______________________________________________________\n");
                            printf("\t|*******************************************************|\n");
                            printf("\t|Nome: %s                                 \n\t|CPF: %s                                 \n\t|Curso: %s                                \n\t|Turno: %s                                \n\t|Tipo vaga: %s                            \n\t|Enem: %.2f                             "
                                   ,candidato[i].nome,candidato[i].cpf,candidato[i].nome_curso,candidato[i].inscricao_turno,candidato[i].tipo_vaga,candidato[i].nota_enem);
                            printf("\n\t|_______________________________________________________|\n");
                            printf("\t*********************************************************\n\n");
                        }
                    }
                }
                else
                {
                    if(opcao_tipo_cota==2)
                    {
                        system("cls");
                        printf("\n|___________________________________________________________________|C2: Renda menor que R$ 1,5 salários|_____________________________________________________________|\n");
                        printf("|*********************************************************************************************************************************************************************|\n");

                        for(i=0; i<quant_candidato; i++)
                        {
                            if(strcmp(candidato[i].tipo_vaga,"C2: Renda menor que R$ 1,5 salários")==0)
                            {
                                printf("\t|_______________________________________________________\n");
                                printf("\t|*******************************************************|\n");
                                printf("\t|Nome: %s                                 \n\t|CPF: %s                                 \n\t|Curso: %s                                \n\t|Turno: %s                                \n\t|Tipo vaga: %s                            \n\t|Enem: %.2f                             "
                                       ,candidato[i].nome,candidato[i].cpf,candidato[i].nome_curso,candidato[i].inscricao_turno,candidato[i].tipo_vaga,candidato[i].nota_enem);
                                printf("\n\t|_______________________________________________________|\n");
                                printf("\t*********************************************************\n\n");
                            }
                        }
                    }
                    else
                    {
                        if(opcao_tipo_cota==3)
                        {
                            system("cls");
                            printf("\n|_____________________________________________________________________|PCD: Pessoa com deficiencia|___________________________________________________________________|\n");
                            printf("|*********************************************************************************************************************************************************************|\n");

                            for(i=0; i<quant_candidato; i++)
                            {
                                if(strcmp(candidato[i].tipo_vaga,"PCD: Pessoa com deficiencia")==0)
                                {
                                    printf("\t|_______________________________________________________\n");
                                    printf("\t|*******************************************************|\n");
                                    printf("\t|Nome: %s                                 \n\t|CPF: %s                                 \n\t|Curso: %s                                \n\t|Turno: %s                                \n\t|Tipo vaga: %s                            \n\t|Enem: %.2f                             "
                                           ,candidato[i].nome,candidato[i].cpf,candidato[i].nome_curso,candidato[i].inscricao_turno,candidato[i].tipo_vaga,candidato[i].nota_enem);
                                    printf("\n\t|_______________________________________________________|\n");
                                    printf("\t*********************************************************\n\n");
                                }
                            }
                        }
                        else
                        {
                            if(opcao_tipo_cota==4)
                            {
                                system("cls");
                                printf("\n|_______________________________________________________________________|A: Ampla concorrência|_______________________________________________________________________|\n");
                                printf("|*********************************************************************************************************************************************************************|\n");

                                for(i=0; i<quant_candidato; i++)
                                {
                                    if(strcmp(candidato[i].tipo_vaga,"A: Ampla concorrência")==0)
                                    {
                                        printf("\t|_______________________________________________________\n");
                                        printf("\t|*******************************************************|\n");
                                        printf("\t|Nome: %s                                 \n\t|CPF: %s                                 \n\t|Curso: %s                                \n\t|Turno: %s                                \n\t|Tipo vaga: %s                            \n\t|Enem: %.2f                             "
                                               ,candidato[i].nome,candidato[i].cpf,candidato[i].nome_curso,candidato[i].inscricao_turno,candidato[i].tipo_vaga,candidato[i].nota_enem);
                                        printf("\n\t|_______________________________________________________|\n");
                                        printf("\t*********************************************************\n\n");
                                    }
                                }
                            }
                        }
                    }

                }
            }

            else
            {
                system("cls");
                printf("\n\a|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
                printf("|                                                                  VOCÊ SAIU DA OPÇÃO GERAR LISTA DE INSCRITOS!                                                       |");
                printf("\n|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
            }
        }

        if(opcao==3)
        {
            gerar_inscritos=false;
        }
        else
        {
            do
            {

                printf("\n\n|______________________________________________________________|  DESEJA CONTINUAR COM A PESQUISA?  |________________________________________________________________|\n");
                printf("|**************************************************************|************************************|****************************************************************|\n");

                printf("\n\n\t{**********}");
                printf("\n\t{1 - [SIM] }");
                printf("\n\t{2 - [NÃO] }");
                printf("\n\t|*******|***\n");
                printf("\t|ENTRADA|--> ");
                setbuf(stdin,NULL);
                scanf("%d",&continuar);

                if(continuar==1)
                {
                    gerar_inscritos=true;
                    opcao=0;
                }
                else
                {
                    if(continuar==2)
                    {
                        gerar_inscritos=false;
                    }
                    else
                    {
                        printf("\n _____________________________________________________________________________________________________________________________________________________________________");
                        printf(" \n|*********************************************************************************************************************************************************************|");
                        printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
                        printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                        printf("\n***********************************************************************************************************************************************************************\n\n");
                        gerar_inscritos=true;
                    }
                }
            }
            while(continuar>2||continuar<1);
        }
        system("cls");
    }
    while(gerar_inscritos);

}

//STRUCT TIPO_VAGA_C1, RECEBE DADOS DO CANDIDATO INSCRITO CONFORME O TIPO DE CURSO E VAGA QUE ELE ESTA CONCORRENDO
void classificacao_por_curso_e_tipovaga_c1(struct inscrever_candidato candidato[], struct tipo_vaga_c1 c1[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso)

{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];

    //ABASTECE STRUCT TIPO_VAGA_C1
    for(i=0; i<quant_candidatos; i++)
    {
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(candidato[i].tipo_vaga,"C1: Renda maior ou igual a R$ 1,5 salários")==0)
        {
            c1[cont].nota_c1=candidato[i].nota_enem;
            strcpy(c1[cont].nome_c1,candidato[i].nome);
            strcpy(c1[cont].cpf_c1,candidato[i].cpf);
            strcpy(c1[cont].nome_curso_c1,candidato[i].nome_curso);
            strcpy(c1[cont].tipo_vaga_c1,"C1: Renda maior ou igual a R$ 1,5 salários");
            cont++;
        }
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0)
        {
            strcpy(c1[x].turno_curso_c1,candidato[i].inscricao_turno);
            x++;
        }

    }

    //REORDENA: NOTA,NOME E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(c1[l].nota_c1<c1[j].nota_c1)
            {
                aux_nota=c1[l].nota_c1;
                c1[l].nota_c1=c1[j].nota_c1;
                c1[j].nota_c1=aux_nota;

                strcpy(aux_nome,c1[l].nome_c1);
                strcpy(c1[l].nome_c1,c1[j].nome_c1);
                strcpy(c1[j].nome_c1,aux_nome);

                strcpy(aux_cpf,c1[l].cpf_c1);
                strcpy(c1[l].cpf_c1,c1[j].cpf_c1);
                strcpy(c1[j].cpf_c1,aux_cpf);
            }
        }
    }

};

void imprime_tipo_vaga_c1_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_c1 c1[],int opcaocurso,int quant_candidatos,int totcursos)
{
    int i=0;
    int j=0;
    int cont=0;
    char espera;
    char comando[10]="color 2e";
    system(comando);

    printf("\n\n\n|_________________________________________________________________|     LISTA DE APROVADOS     |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n\n\n");

    printf("\n\n\n\t ________________________________________________________________________");
    printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);



    for(i=0; i<cad[opcaocurso-1].c1; i++)
    {
        if(strcmp(cad[opcaocurso-1].nome_curso,c1[j].nome_curso_c1)==0&&c1[i].nota_c1==c1[i].nota_c1&&c1[i].nota_c1!=0)
        {

            printf("\n\t _______________________________________________________________________\n");
            printf("\t{***********************************************************************}\n");
            printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
            printf("\n\t{_______________________________________________________________________}\n");
            printf("\t{***********************************************************************}");
            printf("\n\t{Nome: %s",c1[i].nome_c1);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{CPF: %s",c1[i].cpf_c1);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Curso: %s",c1[i].nome_curso_c1);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Turno: %s",c1[i].turno_curso_c1);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Tipo vaga: %s",c1[i].tipo_vaga_c1);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Enem: %.2f",c1[i].nota_c1);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t*************************************************************************\n");

        }

    }
    for(int x=0; x<quant_candidatos; x++)
    {

        if(strcmp(c1[x].tipo_vaga_c1,"C1: Renda maior ou igual a R$ 1,5 salários")==0)
        {
            cont++;
        }
    }

    if(cont==1)
    {
        printf("\n\t _____________________________________________________");
        printf("\n\t|            So existe 1 curso cadastrado!            |");
        printf("\n\t*******************|Fique esperto!|********************");
        printf("\n\t                   ****************\n\n");
    }

    else
    {
        printf("\n\t ____________________________________________");
        printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
        printf("\n\t|*************|*******************************");
        printf("\n\t|Digite ENTER!|-->  ");
        setbuf(stdin,NULL);
        espera=getchar();
        strcpy(comando,"color 0f");
        system(comando);

        printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
        printf("|*****************************************************************|****************************|**********************************************************************|\n");


        //LISTA DE ESPERA
        for(j=cad[opcaocurso-1].c1; j<quant_candidatos; j++)
        {

            if(strcmp(cad[opcaocurso-1].nome_curso,c1[j].nome_curso_c1)==0&&c1[j].nota_c1==c1[j].nota_c1&&c1[j].nota_c1!=0)
            {
                //system("cls");
                char comando[10]="color 01";
                system(comando);

                printf("\n\t ________________________________________________________________________");
                printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);


                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",c1[j].nome_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",c1[j].cpf_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",c1[j].nome_curso_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",c1[j].turno_curso_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",c1[j].tipo_vaga_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",c1[j].nota_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }

        }
    }
    printf("\n\t _____________________________________________________________");
    printf("\n\t|Não fui eu que ordenei a você?                               |");
    printf("\n\t|Seja forte e corajoso! Não se apavore nem desanime,          |\n");
    printf("\t|pois o Senhor,o seu Deus,estará com você por onde você andar.|");
    printf("\n\t|*********|*************************************************  |");
    printf("\n\t[Josué 1:9]                                                   |");
    printf("\n\t***************************************************************\n\n");

}

//STRUCT TIPO_VAGA_C1, RECEBE DADOS DO CANDIDATO INSCRITO CONFORME O TIPO DE CURSO E VAGA QUE ELE ESTA CONCORRENDO
void classificacao_por_curso_e_tipovaga_c2(struct inscrever_candidato candidato[],struct tipo_vaga_c2 c2[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];

    //ABASTECE OS VETORES DA STRUCT: TIPO_VAGA_C2
    for(i=0; i<quant_candidatos; i++)
    {
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(candidato[i].tipo_vaga,"C2: Renda menor que R$ 1,5 salários")==0)
        {
            c2[cont].nota_c2=candidato[i].nota_enem;
            strcpy(c2[cont].nome_c2,candidato[i].nome);
            strcpy(c2[cont].cpf_c2,candidato[i].cpf);
            strcpy(c2[cont].nome_curso_c2,candidato[i].nome_curso);
            strcpy(c2[cont].tipo_vaga_c2,"C2: Renda menor que R$ 1,5 salário");
            cont++;

        }
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0)
        {
            strcpy(c2[x].turno_curso_c2,candidato[i].inscricao_turno);
            x++;
        }

    }

    //FAZ A REORDENAÇÃO DE NOME,NOTA E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(c2[l].nota_c2<c2[j].nota_c2)
            {
                aux_nota=c2[l].nota_c2;
                c2[l].nota_c2=c2[j].nota_c2;
                c2[j].nota_c2=aux_nota;

                strcpy(aux_nome,c2[l].nome_c2);
                strcpy(c2[l].nome_c2,c2[j].nome_c2);
                strcpy(c2[j].nome_c2,aux_nome);

                strcpy(aux_cpf,c2[l].cpf_c2);
                strcpy(c2[l].cpf_c2,c2[j].cpf_c2);
                strcpy(c2[j].cpf_c2,aux_cpf);
            }
        }
    }

};

//IMPRIME O RESULTADO
void imprime_tipo_vaga_c2_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_c2 c2[],int opcaocurso,int quant_candidatos,int totcursos)
{

    int i=0;
    int j=0;
    int cont=0;
    char comando[10]="color 0e";
    system(comando);
    char enter;

    printf("\n\n|_________________________________________________________________|     LISTA DE APROVADOS    |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n");

    printf("\n\t ________________________________________________________________________");
    printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);

    for(i=0; i<cad[opcaocurso-1].c2; i++)
    {
        if(strcmp(cad[opcaocurso-1].nome_curso,c2[i].nome_curso_c2)==0&&c2[i].nota_c2==c2[i].nota_c2&&c2[i].nota_c2!=0)
        {
            printf("\n\t _______________________________________________________________________\n");
            printf("\t{***********************************************************************}\n");
            printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
            printf("\n\t{_______________________________________________________________________}\n");
            printf("\t{***********************************************************************}");
            printf("\n\t{Nome: %s",c2[i].nome_c2);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{CPF: %s",c2[i].cpf_c2);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Curso: %s",c2[i].nome_curso_c2);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Turno: %s",c2[i].turno_curso_c2);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Tipo vaga: %s",c2[i].tipo_vaga_c2);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Enem: %.2f",c2[i].nota_c2);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t*************************************************************************\n");
            cont++;
        }

    }
    for(int x=0; x<quant_candidatos; x++)
    {

        if(strcmp(c2[x].tipo_vaga_c2,"C2: Renda menor que R$ 1,5 salário")==0)
        {
            cont++;
        }
    }

    if(cont==1)
    {
        printf("\n\t _____________________________________________________");
        printf("\n\t|            So existe 1 curso cadastrado!            |");
        printf("\n\t*******************|Fique esperto!|********************");
        printf("\n\t                   ****************\n\n");
    }

    else
    {

        printf("\n\t ____________________________________________");
        printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
        printf("\n\t|*************|*******************************");
        printf("\n\t|Digite ENTER!|-->  ");
        setbuf(stdin,NULL);
        enter=getchar();
        strcpy(comando,"color 0e");
        system(comando);

        printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
        printf("|*****************************************************************|****************************|**********************************************************************|\n");


//LISTA DE ESPERA
        for(j=cad[opcaocurso-1].c2+1; j<quant_candidatos; j++)
        {

            if(strcmp(cad[opcaocurso-1].nome_curso,c2[j].nome_curso_c2)==0&&c2[j].nota_c2==c2[j].nota_c2&&c2[j].nota_c2!=0)
            {
                strcpy(comando,"color 0a");
                system(comando);

                printf("\n\t ________________________________________________________________________");
                printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);


                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",c2[j].nome_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",c2[j].cpf_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",c2[j].nome_curso_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",c2[j].turno_curso_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",c2[j].tipo_vaga_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",c2[j].nota_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }
        }
    }
    printf("\n\t _________________________________________________");
    printf("\n\t|Ao Rei eterno, o Deus único, imortal e invisível,|");
    printf("\n\t|seja honra e gloria para todo o sempre.Amém.     |\n");
    printf("\t|************|************************************|");
    printf("\n\t[Timóteo 1:17]                                    |");
    printf("\n\t***************************************************\n\n");

}

//ABASTECE A STRUCT TIPO_VAGA_PCD
void classificacao_por_curso_e_tipovaga_pcd(struct inscrever_candidato candidato[],struct tipo_vaga_pcd pcd[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];

//STRUCT TIPO_VAGA_PCD RECEBE DADOS DO CANDIDATO CONFORME A SUA INSCRIÇÃO
    for(i=0; i<quant_candidatos; i++)
    {
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(candidato[i].tipo_vaga,"PCD: Pessoa com deficiencia")==0)
        {
            pcd[cont].nota_pcd=candidato[i].nota_enem;
            strcpy(pcd[cont].nome_pcd,candidato[i].nome);
            strcpy(pcd[cont].cpf_pcd,candidato[i].cpf);
            strcpy(pcd[cont].nome_curso_pcd,candidato[i].nome_curso);
            strcpy(pcd[cont].tipo_vaga_pcd,"PCD: Pessoa com deficiencia");
            cont++;
        }
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0)
        {
            strcpy(pcd[x].turno_curso_pcd,candidato[i].inscricao_turno);
            x++;
        }
    }

    //FAZ A REORDENAÇÃO DE NOTA,NOME E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(pcd[l].nota_pcd<pcd[j].nota_pcd)
            {
                aux_nota=pcd[l].nota_pcd;
                pcd[l].nota_pcd=pcd[j].nota_pcd;
                pcd[j].nota_pcd=aux_nota;

                strcpy(aux_nome,pcd[l].nome_pcd);
                strcpy(pcd[l].nome_pcd,pcd[j].nome_pcd);
                strcpy(pcd[j].nome_pcd,aux_nome);

                strcpy(aux_cpf,pcd[l].cpf_pcd);
                strcpy(pcd[l].cpf_pcd,pcd[j].cpf_pcd);
                strcpy(pcd[j].cpf_pcd,aux_cpf);
            }
        }
    }

};

//IMPRIME O RESULTADO
void imprime_tipo_vaga_pcd_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_pcd pcd[],int opcaocurso,int quant_candidatos,int totcursos)
{
    int i=0;
    int j=0;
    int cont=0;
    char enter;
    char comando[10]="color 0d";
    system(comando);

    for(i=0; i<cad[opcaocurso-1].pcd; i++)
    {

        printf("\n\n|_________________________________________________________________|      LISTA DE APROVADOS     |_____________________________________________________________________|\n");
        printf("|*****************************************************************|****************************|**********************************************************************|\n");

        printf("\n\n\t ________________________________________________________________________");
        printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);


        if(strcmp(cad[opcaocurso-1].nome_curso,pcd[j].nome_curso_pcd)==0&&pcd[i].nota_pcd==pcd[i].nota_pcd&&pcd[i].nota_pcd!=0)
        {
            printf("\n\t _______________________________________________________________________\n");
            printf("\t{***********************************************************************}\n");
            printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
            printf("\n\t{_______________________________________________________________________}\n");
            printf("\t{***********************************************************************}");
            printf("\n\t{Nome: %s",pcd[i].nome_pcd);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{CPF: %s",pcd[i].cpf_pcd);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Curso: %s",pcd[i].nome_curso_pcd);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Turno: %s",pcd[i].turno_curso_pcd);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Tipo vaga: %s",pcd[i].tipo_vaga_pcd);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Enem: %.2f",pcd[i].nota_pcd);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t*************************************************************************\n");

        }

    }
    for(int x=0; x<quant_candidatos; x++)
    {

        if(strcmp(pcd[x].tipo_vaga_pcd,"PCD: Pessoa com deficiencia")==0)
        {
            cont++;
        }
    }

    if(cont==1)
    {
        printf("\n\t _____________________________________________________");
        printf("\n\t|            So existe 1 curso cadastrado!            |");
        printf("\n\t*******************|Fique esperto!|********************");
        printf("\n\t                   ****************\n\n");
    }
    else
    {
        printf("\n\t ____________________________________________");
        printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
        printf("\n\t|*************|*******************************");
        printf("\n\t|Digite ENTER!|-->  ");
        setbuf(stdin,NULL);
        enter=getchar();
        strcpy(comando,"color 5f");
        system(comando);

        printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
        printf("|*****************************************************************|****************************|**********************************************************************|\n");


//LISTA DE ESPERA
        for(j=cad[opcaocurso-1].pcd; j<quant_candidatos; j++)
        {

            if(strcmp(cad[opcaocurso-1].nome_curso,pcd[j].nome_curso_pcd)==0&&pcd[j].nota_pcd==pcd[j].nota_pcd&&pcd[j].nota_pcd!=0)
            {

                printf("\n\t ________________________________________________________________________");
                printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);


                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",pcd[i].nome_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",pcd[i].cpf_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",pcd[i].nome_curso_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",pcd[i].turno_curso_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",pcd[i].tipo_vaga_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",pcd[i].nota_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }
        }
    }
    printf("\n\t _______________________________________________________________________");
    printf("\n\t|Ame o senhor, o seu Deus, de todo o seu coração,                       |");
    printf("\n\t|de toda a sua alma, de todo o seu entendimeto e de todas as suas forças|");
    printf("\n\t|O segundo é este: Ame o seu próximo como a si mesmo.                   |");
    printf("\n\t|Não existe mandamento maior do que estes.                              |\n");
    printf("\t|***********************************************************************|");
    printf("\n\t[Marcos 12:30-31]                                                       |");
    printf("\n\t*************************************************************************\n\n");
}

//STRUCT TIPO_VAGA_A RCEBE DADOS DO CANDIDATO INSCRITO
void classificacao_por_curso_e_tipovaga_a(struct inscrever_candidato candidato[],struct tipo_vaga_a a[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];

//ABASTECE A STRUCT TIPO_VAGA_A
    for(i=0; i<quant_candidatos; i++)
    {
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(candidato[i].tipo_vaga,"A: Ampla concorrência")==0)
        {
            a[cont].nota_a=candidato[i].nota_enem;
            strcpy(a[cont].nome_a,candidato[i].nome);
            strcpy(a[cont].cpf_a,candidato[i].cpf);
            strcpy(a[cont].nome_curso_a,candidato[i].nome_curso);
            strcpy(a[cont].tipo_vaga_a,"A: Ampla concorrência");
            cont++;
        }
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0)
        {
            strcpy(a[x].turno_curso_a,candidato[i].inscricao_turno);
            x++;
        }

    }

    //FAZ A REORDENAÇÃO DE NOME,NOTA E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(a[l].nota_a<a[j].nota_a)
            {
                aux_nota=a[l].nota_a;
                a[l].nota_a=a[j].nota_a;
                a[j].nota_a=aux_nota;

                strcpy(aux_nome,a[l].nome_a);
                strcpy(a[l].nome_a,a[j].nome_a);
                strcpy(a[j].nome_a,aux_nome);

                strcpy(aux_cpf,a[l].cpf_a);
                strcpy(a[l].cpf_a,a[j].cpf_a);
                strcpy(a[j].cpf_a,aux_cpf);
            }
        }
    }
};

//IMPRIME RESULTADO
void imprime_tipo_vaga_a_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vaga_a a[],int opcaocurso,int quant_candidatos,int totcursos)
{
    int i=0;
    int j=0;
    int cont=0;
    char enter;
    char comando[10]="color 08";
    system(comando);

    printf("\n\n|_________________________________________________________________|      LISTA DE APROVADOS     |_____________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n");

    printf("\n\n\t ________________________________________________________________________");
    printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);

    for(i=0; i<cad[opcaocurso-1].a; i++)
    {

        if(strcmp(cad[opcaocurso-1].nome_curso,a[i].nome_curso_a)==0&&a[i].nota_a==a[i].nota_a&&a[i].nota_a!=0)
        {
            printf("\n\t _______________________________________________________________________\n");
            printf("\t{***********************************************************************}\n");
            printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
            printf("\n\t{_______________________________________________________________________}\n");
            printf("\t{***********************************************************************}");
            printf("\n\t{Nome: %s",a[i].nome_a);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{CPF: %s",a[i].cpf_a);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Curso: %s",a[i].nome_curso_a);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Turno: %s",a[i].turno_curso_a);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Tipo vaga: %s",a[i].tipo_vaga_a);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Enem: %.2f",a[i].nota_a);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t*************************************************************************\n");

        }

    }
    for(int x=0; x<quant_candidatos; x++)
    {

        if(strcmp(a[x].tipo_vaga_a,"A: Ampla concorrência")==0)
        {
            cont++;
        }
    }

    if(cont==1)
    {
        printf("\n\t _____________________________________________________");
        printf("\n\t|            So existe 1 curso cadastrado!            |");
        printf("\n\t*******************|Fique esperto!|********************");
        printf("\n\t                   ****************\n\n");
    }
    else
    {
        printf("\n\t ____________________________________________");
        printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
        printf("\n\t|*************|*******************************");
        printf("\n\t|Digite ENTER!|-->  ");
        setbuf(stdin,NULL);
        enter=getchar();
        strcpy(comando,"color 0e");
        system(comando);

        printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
        printf("|*****************************************************************|****************************|**********************************************************************|\n");


        //LISTA DE ESPERA
        for(j=cad[opcaocurso-1].a+1; j<quant_candidatos; j++)
        {
            if(strcmp(cad[opcaocurso-1].nome_curso,a[j].nome_curso_a)==0&&a[j].nota_a==a[j].nota_a&&a[j].nota_a!=0)
            {

                printf("\n\t ________________________________________________________________________");
                printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);


                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",a[j].nome_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",a[j].cpf_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",a[j].nome_curso_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",a[j].turno_curso_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",a[j].tipo_vaga_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",a[j].nota_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }
        }
    }
    printf("\n\t _________________________________________________________________");
    printf("\n\t|E a perseverança deve ter ação completa, a fim de que vocês sejam|");
    printf("\n\t|maduros e íntegros, sem que falte a vocês coisa alguma.          |\n");
    printf("\t|*********|*******************************************************|");
    printf("\n\t[Tiago 1:4]                                                       |");
    printf("\n\t*******************************************************************\n\n");
}

void classificacao_reordenada_por_curso_e_tipo_vaga_aprovado(struct inscrever_candidato candidato[],struct aprovados tipo_aprovado[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso)
{
    int cont=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];
    char aux_cota[80];

//ABASTECE A STRUCT TIPO_VAGA_A
    for(i=0; i<quant_candidatos; i++)
    {
        if(strcmp(candidato[i].nome_curso,cad[opcaocurso-1].nome_curso)==0)
        {
            tipo_aprovado[cont].nota_aprovado=candidato[i].nota_enem;
            strcpy(tipo_aprovado[cont].nome_aprovado,candidato[i].nome);
            strcpy(tipo_aprovado[cont].cpf_aprovado,candidato[i].cpf);
            strcpy(tipo_aprovado[cont].nome_curso_aprovado,candidato[i].nome_curso);
            strcpy(tipo_aprovado[cont].tipo_vaga_aprovado,candidato[i].tipo_vaga);
            strcpy(tipo_aprovado[cont].turno_curso_aprovado,candidato[i].inscricao_turno);
            cont++;
        }
    }

    //FAZ A REORDENAÇÃO DE NOME,NOTA E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(tipo_aprovado[l].nota_aprovado<tipo_aprovado[j].nota_aprovado)
            {
                aux_nota=tipo_aprovado[l].nota_aprovado;
                tipo_aprovado[l].nota_aprovado=tipo_aprovado[j].nota_aprovado;
                tipo_aprovado[j].nota_aprovado=aux_nota;

                strcpy(aux_nome,tipo_aprovado[l].nome_aprovado);
                strcpy(tipo_aprovado[l].nome_aprovado,tipo_aprovado[j].nome_aprovado);
                strcpy(tipo_aprovado[j].nome_aprovado,aux_nome);

                strcpy(aux_cpf,tipo_aprovado[l].cpf_aprovado);
                strcpy(tipo_aprovado[l].cpf_aprovado,tipo_aprovado[j].cpf_aprovado);
                strcpy(tipo_aprovado[j].cpf_aprovado,aux_cpf);

                strcpy(aux_cota,tipo_aprovado[l].tipo_vaga_aprovado);
                strcpy(tipo_aprovado[l].tipo_vaga_aprovado,tipo_aprovado[j].tipo_vaga_aprovado);
                strcpy(tipo_aprovado[j].tipo_vaga_aprovado,aux_cota);
            }
        }
    }

}


void classificacao_reordenar_por_curso_e_tipovaga_espera(struct inscrever_candidato candidato[],struct tipo_vaga_c1 c1[],struct tipo_vaga_c2 c2[],struct tipo_vaga_pcd pcd[],struct tipo_vaga_a a[],struct lista_de_espera lista_espera[],struct cadastro_curso cad[],int quant_candidatos,int opcaocurso)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];
    char aux_cota[80];


    //ABASTECE A STRUCT TIPO_VAGA_A
    for(int y=cad[opcaocurso-1].c1; y<quant_candidatos; y++)
    {
        if(strcmp(candidato[y].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(c1[y].tipo_vaga_c1,"C1: Renda maior ou igual a R$ 1,5 salários")==0&&c1[y].nota_c1!=0)
        {
            lista_espera[cont].nota_espera=c1[y].nota_c1;
            strcpy(lista_espera[cont].nome_espera,c1[y].nome_c1);
            strcpy(lista_espera[cont].cpf_espera,c1[y].cpf_c1);
            strcpy(lista_espera[cont].nome_curso_espera,c1[y].nome_curso_c1);
            strcpy(lista_espera[cont].tipo_vaga_espera,"C1: Renda maior ou igual a R$ 1,5 salários");
            strcpy(lista_espera[cont].turno_curso_espera,c1[y].turno_curso_c1);
            cont++;
        }

    }
    for(int b=cad[opcaocurso-1].c2+1; b<quant_candidatos; b++)
     {
         if(strcmp(candidato[b].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(c2[b].tipo_vaga_c2,"C2: Renda menor que R$ 1,5 salário")==0&&c2[b].nota_c2!=0)
         {
             lista_espera[cont].nota_espera=c2[b].nota_c2;
             strcpy(lista_espera[cont].nome_espera,c2[b].nome_c2);
             strcpy(lista_espera[cont].cpf_espera,c2[b].cpf_c2);
             strcpy(lista_espera[cont].nome_curso_espera,c2[b].nome_curso_c2);
             strcpy(lista_espera[cont].tipo_vaga_espera,"C2: Renda menor que R$ 1,5 salário");
             strcpy(lista_espera[cont].turno_curso_espera,c2[b].turno_curso_c2);
             cont++;
         }

     }

     for(int a=cad[opcaocurso-1].pcd; a<quant_candidatos; a++)
     {
         if(strcmp(candidato[a].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(pcd[a].tipo_vaga_pcd,"PCD: Pessoa com deficiencia")==0&&pcd[a].nota_pcd!=0)
         {
             lista_espera[cont].nota_espera=pcd[a].nota_pcd;
             strcpy(lista_espera[cont].nome_espera,pcd[a].nome_pcd);
             strcpy(lista_espera[cont].cpf_espera,pcd[a].cpf_pcd);
             strcpy(lista_espera[cont].nome_curso_espera,pcd[a].nome_curso_pcd);
             strcpy(lista_espera[cont].tipo_vaga_espera,"PCD: Pessoa com deficiencia");
             strcpy(lista_espera[cont].turno_curso_espera,pcd[a].turno_curso_pcd);
             cont++;
         }

     }

      for(int x=cad[opcaocurso-1].a+1; x<quant_candidatos; x++)
     {
         if(strcmp(candidato[x].nome_curso,cad[opcaocurso-1].nome_curso)==0&&strcmp(a[x].tipo_vaga_a,"A: Ampla concorrência")==0&&a[x].nota_a!=0)
         {
             lista_espera[cont].nota_espera=a[x].nota_a;
             strcpy(lista_espera[cont].nome_espera,a[x].nome_a);
             strcpy(lista_espera[cont].cpf_espera,a[x].cpf_a);
             strcpy(lista_espera[cont].nome_curso_espera,a[x].nome_curso_a);
             strcpy(lista_espera[cont].tipo_vaga_espera,"A: Ampla concorrência");
             strcpy(lista_espera[cont].turno_curso_espera,a[x].turno_curso_a);
             cont++;
         }

     }

     //FAZ A REORDENAÇÃO DE NOME,NOTA E CPF
     for(l=0; l<cont; l++)
     {
         for(j=l+1; j<cont; j++)
         {
             if(lista_espera[l].nota_espera<lista_espera[j].nota_espera)
             {
                 aux_nota=lista_espera[l].nota_espera;
                 lista_espera[l].nota_espera=lista_espera[j].nota_espera;
                 lista_espera[j].nota_espera=aux_nota;

                 strcpy(aux_nome,lista_espera[l].nome_espera);
                 strcpy(lista_espera[l].nome_espera,lista_espera[j].nome_espera);
                 strcpy(lista_espera[j].nome_espera,aux_nome);

                 strcpy(aux_cpf,lista_espera[l].cpf_espera);
                 strcpy(lista_espera[l].cpf_espera,lista_espera[j].cpf_espera);
                 strcpy(lista_espera[j].cpf_espera,aux_cpf);

                 strcpy(aux_cota,lista_espera[l].tipo_vaga_espera);
                 strcpy(lista_espera[l].tipo_vaga_espera,lista_espera[j].tipo_vaga_espera);
                 strcpy(lista_espera[j].tipo_vaga_espera,aux_cota);
             }
         }
     }

}

void imprime_tipo_vaga_por_curso_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct aprovados tipo_aprovado[],struct lista_de_espera espera[],int opcaocurso,int quant_candidatos,int totcursos)
{
    int i=0;
    int x=0;
    int colocacao=0;
    int tipo_c1=0;
    int tipo_c2=0;
    int tipo_pcd=0;
    int tipo_a=0;
    char esp;
    char comando[10]="color 2e";
    system(comando);

    printf("\n\n\n|_________________________________________________________________|     LISTA DE APROVADOS     |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n\n\n");

    printf("\n\n\n\t ________________________________________________________________________");
    printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);

    do
    {
        visualizar_vaga_portipo(cad,totcursos);

        if(strcmp(tipo_aprovado[i].tipo_vaga_aprovado,"C1: Renda maior ou igual a R$ 1,5 salários")==0&&tipo_c1<cad[opcaocurso-1].c1&&tipo_aprovado[i].nota_aprovado!=0)
        {
            tipo_c1++;
            colocacao++;
            printf("\n\t _______________________________________________________________________\n");
            printf("\t{***********************************************************************}\n");
            printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",colocacao);
            printf("\n\t{_______________________________________________________________________}\n");
            printf("\t{***********************************************************************}");
            printf("\n\t{Nome: %s",tipo_aprovado[i].nome_aprovado);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{CPF: %s",tipo_aprovado[i].cpf_aprovado);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Curso: %s",tipo_aprovado[i].nome_curso_aprovado);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Turno: %s",tipo_aprovado[i].turno_curso_aprovado);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Tipo vaga: %s",tipo_aprovado[i].tipo_vaga_aprovado);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Enem: %.2f",tipo_aprovado[i].nota_aprovado);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t*************************************************************************\n");

        }
        else
        {

            visualizar_vaga_portipo(cad,totcursos);
            if(strcmp(tipo_aprovado[i].tipo_vaga_aprovado,"C2: Renda menor que R$ 1,5 salários")==0&&tipo_c2<cad[opcaocurso-1].c2&&tipo_aprovado[i].nota_aprovado!=0)
            {
                tipo_c2++;
                colocacao++;
                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",colocacao);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",tipo_aprovado[i].nome_aprovado);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",tipo_aprovado[i].cpf_aprovado);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",tipo_aprovado[i].nome_curso_aprovado);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",tipo_aprovado[i].turno_curso_aprovado);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",tipo_aprovado[i].tipo_vaga_aprovado);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",tipo_aprovado[i].nota_aprovado);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }
            else
            {

                if(strcmp(tipo_aprovado[i].tipo_vaga_aprovado,"PCD: Pessoa com deficiencia")==0&&tipo_pcd<cad[opcaocurso-1].pcd&&tipo_aprovado[i].nota_aprovado!=0)
                {
                    tipo_pcd++;
                    colocacao++;
                    printf("\n\t _______________________________________________________________________\n");
                    printf("\t{***********************************************************************}\n");
                    printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",colocacao);
                    printf("\n\t{_______________________________________________________________________}\n");
                    printf("\n\t{CPF: %s",tipo_aprovado[i].cpf_aprovado);
                    printf("\n\t{_______________________________________________________________________}");
                    printf("\n\t{***********************************************************************}");
                    printf("\n\t{Curso: %s",tipo_aprovado[i].nome_curso_aprovado);
                    printf("\n\t{_______________________________________________________________________}");
                    printf("\n\t{***********************************************************************}");
                    printf("\n\t{Turno: %s",tipo_aprovado[i].turno_curso_aprovado);
                    printf("\n\t{_______________________________________________________________________}");
                    printf("\n\t{***********************************************************************}");
                    printf("\n\t{Tipo vaga: %s",tipo_aprovado[i].tipo_vaga_aprovado);
                    printf("\n\t{_______________________________________________________________________}");
                    printf("\n\t{***********************************************************************}");
                    printf("\n\t{Enem: %.2f",tipo_aprovado[i].nota_aprovado);
                    printf("\n\t{_______________________________________________________________________}");
                    printf("\n\t*************************************************************************\n");

                }
                else
                {

                    if(strcmp(tipo_aprovado[i].tipo_vaga_aprovado,"A: Ampla concorrência")==0&&tipo_a<cad[opcaocurso-1].a&&tipo_aprovado[i].nota_aprovado!=0)
                    {
                        tipo_a++;
                        colocacao++;
                        printf("\n\t _______________________________________________________________________\n");
                        printf("\t{***********************************************************************}\n");
                        printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",colocacao);
                        printf("\n\t{_______________________________________________________________________}\n");
                        printf("\t{***********************************************************************}");
                        printf("\n\t{Nome: %s",tipo_aprovado[i].nome_aprovado);
                        printf("\n\t{_______________________________________________________________________}");
                        printf("\n\t{***********************************************************************}");
                        printf("\n\t{CPF: %s",tipo_aprovado[i].cpf_aprovado);
                        printf("\n\t{_______________________________________________________________________}");
                        printf("\n\t{***********************************************************************}");
                        printf("\n\t{Curso: %s",tipo_aprovado[i].nome_curso_aprovado);
                        printf("\n\t{_______________________________________________________________________}");
                        printf("\n\t{***********************************************************************}");
                        printf("\n\t{Turno: %s",tipo_aprovado[i].turno_curso_aprovado);
                        printf("\n\t{_______________________________________________________________________}");
                        printf("\n\t{***********************************************************************}");
                        printf("\n\t{Tipo vaga: %s",tipo_aprovado[i].tipo_vaga_aprovado);
                        printf("\n\t{_______________________________________________________________________}");
                        printf("\n\t{***********************************************************************}");
                        printf("\n\t{Enem: %.2f",tipo_aprovado[i].nota_aprovado);
                        printf("\n\t{_______________________________________________________________________}");
                        printf("\n\t*************************************************************************\n");

                    }
                }
            }
        }
        i++;

    }
    while(i<quant_candidatos);


    printf("\n\t _______________________________________________________________________");
    printf("\n\t|Ame o senhor, o seu Deus, de todo o seu coração,                       |");
    printf("\n\t|de toda a sua alma, de todo o seu entendimeto e de todas as suas forças|");
    printf("\n\t|O segundo é este: Ame o seu próximo como a si mesmo.                   |");
    printf("\n\t|Não existe mandamento maior do que estes.                              |\n");
    printf("\t|***********************************************************************|");
    printf("\n\t[Marcos 12:30-31]                                                       |");
    printf("\n\t*************************************************************************\n\n");

    printf("\n\t ____________________________________________");
    printf("\n\t{Leu e meditou no versículo?                 }");
    printf("\n\t{********************************************}");
    printf("\n\t{Não encontrou seu nome na lista de aprovado?}");
    printf("\n\t|*************|******************************}");
    printf("\n\t|Digite ENTER!|-->  ");
    setbuf(stdin,NULL);
    esp=getchar();
    strcpy(comando,"color 0f");
    system(comando);


    printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n");

    printf("\n\t ________________________________________________________________________");
    printf("\n\t|****************************CURSO DE %s***************************|\n\n",cad[opcaocurso-1].nome_curso);
    //LISTA DE ESPERA

    for(x=0; x<quant_candidatos; x++)
    {

        if(lista_espera[x].nota_espera==lista_espera[x].nota_espera&&lista_espera[x].nota_espera!=0)
        {

            colocacao++;
            printf("\n\t _______________________________________________________________________\n");
            printf("\t{***********************************************************************}\n");
            printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",colocacao);
            printf("\n\t{_______________________________________________________________________}\n");
            printf("\t{***********************************************************************}");
            printf("\n\t{Nome: %s",lista_espera[x].nome_espera);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{CPF: %s",lista_espera[x].cpf_espera);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Curso: %s",lista_espera[x].nome_curso_espera);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Turno: %s",lista_espera[x].turno_curso_espera);
            printf("\n\t{______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Tipo vaga: %s",lista_espera[x].tipo_vaga_espera);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t{***********************************************************************}");
            printf("\n\t{Enem: %.2f",lista_espera[x].nota_espera);
            printf("\n\t{_______________________________________________________________________}");
            printf("\n\t*************************************************************************\n");


        }
    }

    printf("\n\t _________________________________________________________________");
    printf("\n\t|E a perseverança deve ter ação completa, a fim de que vocês sejam|");
    printf("\n\t|maduros e íntegros, sem que falte a vocês coisa alguma.          |\n");
    printf("\t|*********|*******************************************************|");
    printf("\n\t[Tiago 1:4]                                                       |");
    printf("\n\t*******************************************************************\n\n");
};



void classificacao_por_tipovaga_c1(struct inscrever_candidato candidato[], struct tipo_vagac1 vaga_c1[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];
    char aux_nome_curso[50];

    //ABASTECE STRUCT TIPO_VAGA_C1
    for(i=0; i<quant_candidato; i++)
    {
        if(strcmp(candidato[i].tipo_vaga,"C1: Renda maior ou igual a R$ 1,5 salários")==0)
        {
            vaga_c1[cont].nota_c1=candidato[i].nota_enem;
            strcpy(vaga_c1[cont].nome_c1,candidato[i].nome);
            strcpy(vaga_c1[cont].cpf_c1,candidato[i].cpf);
            strcpy(vaga_c1[cont].nome_curso_c1,candidato[i].nome_curso);
            strcpy(vaga_c1[cont].tipo_vaga_c1,"C1: Renda maior ou igual a R$ 1,5 salários");
            strcpy(vaga_c1[x].turno_curso_c1,candidato[i].inscricao_turno);
            x++;
            cont++;
        }

    }

    //REORDENA: NOTA,NOME E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(vaga_c1[l].nota_c1<vaga_c1[j].nota_c1)
            {
                aux_nota=vaga_c1[l].nota_c1;
                vaga_c1[l].nota_c1=vaga_c1[j].nota_c1;
                vaga_c1[j].nota_c1=aux_nota;

                strcpy(aux_nome,vaga_c1[l].nome_c1);
                strcpy(vaga_c1[l].nome_c1,vaga_c1[j].nome_c1);
                strcpy(vaga_c1[j].nome_c1,aux_nome);

                strcpy(aux_cpf,vaga_c1[l].cpf_c1);
                strcpy(vaga_c1[l].cpf_c1,vaga_c1[j].cpf_c1);
                strcpy(vaga_c1[j].cpf_c1,aux_cpf);

                strcpy(aux_nome_curso,vaga_c1[l].nome_curso_c1);
                strcpy(vaga_c1[l].nome_curso_c1,vaga_c1[j].nome_curso_c1);
                strcpy(vaga_c1[l].nome_curso_c1,aux_nome_curso);
            }
        }
    }

}
void imprime_tipo_vaga_c1_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagac1 vaga_c1[],int quant_candidato,int totcursos)
{
    int i=0;
    int j=0;
    int y=0;
    int controle=0;
    char comando[10]="color 01";
    system(comando);

    printf("\n\n\n|_________________________________________________________________|     LISTA DE APROVADOS     |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n\n\n");

    printf("\n\n\n|_______________________________________________________________|C1: Renda maior ou igual a R$ 1,5 salários|__________________________________________________________|\n");
    printf("|*********************************************************************************************************************************************************************|\n");


    for(y=0; y<=totcursos; y++)
    {
        do
        {
            if(strcmp(cad[y].nome_curso,vaga_c1[i].nome_curso_c1)==0&&vaga_c1[i].nota_c1==vaga_c1[i].nota_c1&&vaga_c1[i].nota_c1!=0)
            {

                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_c1[i].nome_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_c1[i].cpf_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_c1[i].nome_curso_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_c1[i].turno_curso_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_c1[i].tipo_vaga_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_c1[i].nota_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");
                controle++;
            }

            i++;

        }
        while(controle<cad[y].c1);
        controle=0;
        i=0;
    }

    printf("\n\t ____________________________________________");
    printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
    printf("\n\t|*************|*******************************");
    printf("\n\t|Digite ENTER!|-->  ");
    setbuf(stdin,NULL);
    char espera=getchar();

    controle=0;
    printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n");

    //LISTA DE ESPERA
    visualizar_vaga_portipo(cad,totcursos);
    for(i=0; i<=totcursos; i++)
    {
        j=cad[i].c1;
        do
        {
            j++;
            if(strcmp(cad[i].nome_curso,vaga_c1[j].nome_curso_c1)==0&&vaga_c1[j].nota_c1==vaga_c1[j].nota_c1&&vaga_c1[j].nota_c1!=0)
            {
                char comando[10]="color 01";
                system(comando);

                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_c1[j].nome_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_c1[j].cpf_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_c1[j].nome_curso_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_c1[j].turno_curso_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_c1[j].tipo_vaga_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_c1[j].nota_c1);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }

        }
        while(j<quant_candidato);
        j=0;
    }
    printf("\n\t _____________________________________________________________");
    printf("\n\t|Não fui eu que ordenei a você?                               |");
    printf("\n\t|Seja forte e corajoso! Não se apavore nem desanime,          |\n");
    printf("\t|pois o Senhor,o seu Deus,estará com você por onde você andar.|");
    printf("\n\t|*********|*************************************************  |");
    printf("\n\t[Josué 1:9]                                                   |");
    printf("\n\t***************************************************************\n\n");


}

void classificacao_por_tipovaga_c2(struct inscrever_candidato candidato[], struct tipo_vagac2 vaga_c2[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];
    char aux_nome_curso[50];

    //ABASTECE STRUCT TIPO_VAGA_C1
    for(i=0; i<quant_candidato; i++)
    {
        if(strcmp(candidato[i].tipo_vaga,"C2: Renda menor que R$ 1,5 salários")==0)
        {
            vaga_c2[cont].nota_c2=candidato[i].nota_enem;
            strcpy(vaga_c2[cont].nome_c2,candidato[i].nome);
            strcpy(vaga_c2[cont].cpf_c2,candidato[i].cpf);
            strcpy(vaga_c2[cont].nome_curso_c2,candidato[i].nome_curso);
            strcpy(vaga_c2[cont].tipo_vaga_c2,"C2: Renda menor que R$ 1,5 salários");
            strcpy(vaga_c2[x].turno_curso_c2,candidato[i].inscricao_turno);
            x++;
            cont++;
        }

    }

    //REORDENA: NOTA,NOME E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(vaga_c2[l].nota_c2<vaga_c2[j].nota_c2)
            {
                aux_nota=vaga_c2[l].nota_c2;
                vaga_c2[l].nota_c2=vaga_c2[j].nota_c2;
                vaga_c2[j].nota_c2=aux_nota;

                strcpy(aux_nome,vaga_c2[l].nome_c2);
                strcpy(vaga_c2[l].nome_c2,vaga_c2[j].nome_c2);
                strcpy(vaga_c2[j].nome_c2,aux_nome);

                strcpy(aux_cpf,vaga_c2[l].cpf_c2);
                strcpy(vaga_c2[l].cpf_c2,vaga_c2[j].cpf_c2);
                strcpy(vaga_c2[j].cpf_c2,aux_cpf);

                // strcpy(aux_nome_curso,c2[l].nome_curso_c2);
                //strcpy(c2[l].nome_curso_c2,c2[j].nome_curso_c2);
                // strcpy(c2[l].nome_curso_c2,aux_nome_curso);
            }
        }
    }

}

void imprime_tipo_vaga_c2_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagac2 vaga_c2[],int quant_candidato,int totcursos)
{
    int i=0;
    int j=0;
    int y=0;
    int controle=0;
    char comando[10]="color 01";
    system(comando);

    printf("\n\n\n|_________________________________________________________________|     LISTA DE APROVADOS     |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n\n\n");

    printf("\n\n\n|___________________________________________________________________|C2: RENDA MENOR QUE R$ 1,5 salários|_____________________________________________________________|\n");
    printf("|*********************************************************************************************************************************************************************|\n");

    for(y=0; y<=totcursos; y++)
    {
        do
        {
            if(strcmp(cad[y].nome_curso,vaga_c2[i].nome_curso_c2)==0&&vaga_c2[i].nota_c2==vaga_c2[i].nota_c2&&vaga_c2[i].nota_c2!=0)
            {

                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_c2[i].nome_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_c2[i].cpf_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_c2[i].nome_curso_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_c2[i].turno_curso_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_c2[i].tipo_vaga_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_c2[i].nota_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");
                controle++;
            }

            i++;

        }
        while(controle<cad[y].c2);
        controle=0;
        i=0;
    }

    printf("\n\t ____________________________________________");
    printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
    printf("\n\t|*************|*******************************");
    printf("\n\t|Digite ENTER!|-->  ");
    setbuf(stdin,NULL);
    char espera=getchar();


    printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n");

    //LISTA DE ESPERA
    visualizar_vaga_portipo(cad,totcursos);
    j=cad[i].c2+1;
    for(i=0; i<=totcursos; i++)
    {

        do
        {
            j++;
            if(strcmp(cad[i].nome_curso,vaga_c2[j].nome_curso_c2)==0&&vaga_c2[j].nota_c2==vaga_c2[j].nota_c2&&vaga_c2[j].nota_c2!=0)
            {
                char comando[10]="color 01";
                system(comando);

                printf("\n\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_c2[j].nome_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_c2[j].cpf_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_c2[j].nome_curso_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_c2[j].turno_curso_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_c2[j].tipo_vaga_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_c2[j].nota_c2);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }

        }
        while(j<quant_candidato);
        j=0;
        j=cad[i].c2+1;
        j++;

    }
    printf("\n\t _____________________________________________________________");
    printf("\n\t|Não fui eu que ordenei a você?                               |");
    printf("\n\t|Seja forte e corajoso! Não se apavore nem desanime,          |\n");
    printf("\t|pois o Senhor,o seu Deus,estará com você por onde você andar.|");
    printf("\n\t|*********|*************************************************  |");
    printf("\n\t[Josué 1:9]                                                   |");
    printf("\n\t***************************************************************\n\n");

}
void classificacao_por_tipovaga_pcd(struct inscrever_candidato candidato[], struct tipo_vagapcd vaga_pcd[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];

//STRUCT TIPO_VAGA_PCD RECEBE DADOS DO CANDIDATO CONFORME A SUA INSCRIÇÃO
    for(i=0; i<quant_candidato; i++)
    {
        if(strcmp(candidato[i].tipo_vaga,"PCD: Pessoa com deficiencia")==0)
        {
            vaga_pcd[cont].nota_pcd=candidato[i].nota_enem;
            strcpy(vaga_pcd[cont].nome_pcd,candidato[i].nome);
            strcpy(vaga_pcd[cont].cpf_pcd,candidato[i].cpf);
            strcpy(vaga_pcd[cont].nome_curso_pcd,candidato[i].nome_curso);
            strcpy(vaga_pcd[cont].tipo_vaga_pcd,"PCD: Pessoa com deficiencia");
            strcpy(vaga_pcd[x].turno_curso_pcd,candidato[i].inscricao_turno);
            x++;
            cont++;

        }

    }

    //FAZ A REORDENAÇÃO DE NOTA,NOME E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(vaga_pcd[l].nota_pcd<vaga_pcd[j].nota_pcd)
            {
                aux_nota=vaga_pcd[l].nota_pcd;
                vaga_pcd[l].nota_pcd=vaga_pcd[j].nota_pcd;
                vaga_pcd[j].nota_pcd=aux_nota;

                strcpy(aux_nome,vaga_pcd[l].nome_pcd);
                strcpy(vaga_pcd[l].nome_pcd,vaga_pcd[j].nome_pcd);
                strcpy(vaga_pcd[j].nome_pcd,aux_nome);

                strcpy(aux_cpf,vaga_pcd[l].cpf_pcd);
                strcpy(vaga_pcd[l].cpf_pcd,vaga_pcd[j].cpf_pcd);
                strcpy(vaga_pcd[j].cpf_pcd,aux_cpf);
            }
        }
    }

}

void imprime_tipo_vaga_pcd_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagapcd vaga_pcd[],int quant_candidato,int totcursos)
{
    int i=0;
    int j=0;
    int y=0;
    int controle=0;
    char comando[10]="color 01";
    system(comando);

    printf("\n\n\n|_________________________________________________________________|     LISTA DE APROVADOS     |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n\n\n");

    printf("\n\n\n|______________________________________________________________________|PCD: PESSOA COM DEFICIENCIA|__________________________________________________________________|\n");
    printf("|*********************************************************************************************************************************************************************|\n");


    for(y=0; y<=totcursos; y++)
    {
        do
        {
            if(strcmp(cad[y].nome_curso,vaga_pcd[i].nome_curso_pcd)==0&&vaga_pcd[i].nota_pcd==vaga_pcd[i].nota_pcd&&vaga_pcd[i].nota_pcd!=0)
            {

                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_pcd[i].nome_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_pcd[i].cpf_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_pcd[i].nome_curso_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_pcd[i].turno_curso_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_pcd[i].tipo_vaga_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_pcd[i].nota_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");
                controle++;
            }

            i++;

        }
        while(controle<cad[y].pcd);
        controle=0;
        i=0;
    }

    printf("\n\t ____________________________________________");
    printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
    printf("\n\t|*************|*******************************");
    printf("\n\t|Digite ENTER!|-->  ");
    setbuf(stdin,NULL);
    char espera=getchar();


    printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n");

    //LISTA DE ESPERA
    visualizar_vaga_portipo(cad,totcursos);
    for(i=0; i<=totcursos; i++)
    {
        j=cad[i].pcd;
        do
        {
            j++;
            if(strcmp(cad[i].nome_curso,vaga_pcd[j].nome_curso_pcd)==0&&vaga_pcd[j].nota_pcd==vaga_pcd[j].nota_pcd&&vaga_pcd[j].nota_pcd!=0)
            {
                char comando[10]="color 01";
                system(comando);

                printf("\n\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_pcd[j].nome_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_pcd[j].cpf_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_pcd[j].nome_curso_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_pcd[j].turno_curso_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_pcd[j].tipo_vaga_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_pcd[j].nota_pcd);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }

        }
        while(j<quant_candidato);
        j=0;

    }
    printf("\n\t _____________________________________________________________");
    printf("\n\t|Não fui eu que ordenei a você?                               |");
    printf("\n\t|Seja forte e corajoso! Não se apavore nem desanime,          |\n");
    printf("\t|pois o Senhor,o seu Deus,estará com você por onde você andar.|");
    printf("\n\t|*********|*************************************************  |");
    printf("\n\t[Josué 1:9]                                                   |");
    printf("\n\t***************************************************************\n\n");

}

void classificacao_por_tipovaga_a(struct inscrever_candidato candidato[], struct tipo_vagaa vaga_a[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    int cont=0;
    int x=0;
    int i=0;
    int j=0;
    int l=0;
    float aux_nota=0;
    char aux_cpf[15];
    char aux_nome[50];

//STRUCT TIPO_VAGA_PCD RECEBE DADOS DO CANDIDATO CONFORME A SUA INSCRIÇÃO
    for(i=0; i<quant_candidato; i++)
    {
        if(strcmp(candidato[i].tipo_vaga,"A: Ampla concorrência")==0)
        {
            vaga_a[cont].nota_a=candidato[i].nota_enem;
            strcpy(vaga_a[cont].nome_a,candidato[i].nome);
            strcpy(vaga_a[cont].cpf_a,candidato[i].cpf);
            strcpy(vaga_a[cont].nome_curso_a,candidato[i].nome_curso);
            strcpy(vaga_a[cont].tipo_vaga_a,"A: Ampla concorrência");
            strcpy(vaga_a[x].turno_curso_a,candidato[i].inscricao_turno);
            x++;
            cont++;

        }

    }

    //FAZ A REORDENAÇÃO DE NOTA,NOME E CPF
    for(l=0; l<cont; l++)
    {
        for(j=l+1; j<cont; j++)
        {
            if(vaga_a[l].nota_a<vaga_a[j].nota_a)
            {
                aux_nota=vaga_a[l].nota_a;
                vaga_a[l].nota_a=vaga_a[j].nota_a;
                vaga_a[j].nota_a=aux_nota;

                strcpy(aux_nome,vaga_a[l].nome_a);
                strcpy(vaga_a[l].nome_a,vaga_a[j].nome_a);
                strcpy(vaga_a[j].nome_a,aux_nome);

                strcpy(aux_cpf,vaga_a[l].cpf_a);
                strcpy(vaga_a[l].cpf_a,vaga_a[j].cpf_a);
                strcpy(vaga_a[j].cpf_a,aux_cpf);
            }
        }
    }
}

void imprime_tipo_vaga_a_aprovados_e_lista_de_espera(struct cadastro_curso cad[],struct tipo_vagaa vaga_a[],int quant_candidato,int totcursos)
{
    int i=0;
    int j=0;
    int y=0;
    int controle=0;
    char comando[10]="color 01";
    system(comando);

    printf("\n\n\n|_________________________________________________________________|     LISTA DE APROVADOS     |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n\n\n");

    printf("\n\n\n|________________________________________________________________________|A: AMPLA CONCORRÊNCIA|______________________________________________________________________|\n");
    printf("|*********************************************************************************************************************************************************************|\n");


    for(y=0; y<=totcursos; y++)
    {
        do
        {
            if(strcmp(cad[y].nome_curso,vaga_a[i].nome_curso_a)==0&&vaga_a[i].nota_a==vaga_a[i].nota_a&&vaga_a[i].nota_a!=0)
            {

                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",i+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_a[i].nome_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_a[i].cpf_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_a[i].nome_curso_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_a[i].turno_curso_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_a[i].tipo_vaga_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_a[i].nota_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");
                controle++;
            }

            i++;

        }
        while(controle<cad[y].a);
        controle=0;
        i=0;
    }

    printf("\n\t ____________________________________________");
    printf("\n\t|Não encontrou seu nome na lista de aprovado?|");
    printf("\n\t|*************|*******************************");
    printf("\n\t|Digite ENTER!|-->  ");
    setbuf(stdin,NULL);
    char espera=getchar();

    printf("\n\n|_________________________________________________________________|      LISTA DE ESPERA       |______________________________________________________________________|\n");
    printf("|*****************************************************************|****************************|**********************************************************************|\n");
    int x=0;
    //LISTA DE ESPERA
    visualizar_vaga_portipo(cad,totcursos);
    j=cad[x].a+1;
    for(x=0; x<=totcursos; x++)
    {

        setbuf(stdin,NULL);
        do
        {
            j++;
            if(strcmp(cad[x].nome_curso,vaga_a[j].nome_curso_a)==0&&vaga_a[j].nota_a==vaga_a[j].nota_a&&vaga_a[j].nota_a!=0)
            {
                char comando[10]="color 01";
                system(comando);
                setbuf(stdin,NULL);
                printf("\n\t _______________________________________________________________________\n");
                printf("\t{***********************************************************************}\n");
                printf("\t{%d°<-COLOCADO(A){}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}}",j+1);
                printf("\n\t{_______________________________________________________________________}\n");
                printf("\t{***********************************************************************}");
                printf("\n\t{Nome: %s",vaga_a[j].nome_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{CPF: %s",vaga_a[j].cpf_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Curso: %s",vaga_a[j].nome_curso_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Turno: %s",vaga_a[j].turno_curso_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Tipo vaga: %s",vaga_a[j].tipo_vaga_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t{***********************************************************************}");
                printf("\n\t{Enem: %.2f",vaga_a[j].nota_a);
                printf("\n\t{_______________________________________________________________________}");
                printf("\n\t*************************************************************************\n");

            }

        }
        while(j<quant_candidato);
        setbuf(stdin,NULL);
        j=0;
        j=cad[x].a+1;
        j++;
    }
    printf("\n\t _____________________________________________________________");
    printf("\n\t|Não fui eu que ordenei a você?                               |");
    printf("\n\t|Seja forte e corajoso! Não se apavore nem desanime,          |\n");
    printf("\t|pois o Senhor,o seu Deus,estará com você por onde você andar.|");
    printf("\n\t|*********|*************************************************  |");
    printf("\n\t[Josué 1:9]                                                   |");
    printf("\n\t***************************************************************\n\n");


}

//GERA LISTA DE CLASSIFICADOS
void gerar_lista_de_classificacao(struct inscrever_candidato candidato[],struct cadastro_curso cad[],int quant_candidato,int totcursos)
{
    system("cls");
    bool continuar_classi=true;
    int opcao=0;
    int opcao_curso=0;
    int escolha_opcao=0;
    int continuar=0;
    int opcao_tipo_cota=0;
    int i=0,x=-1;
    char nome_curso[80];
    char comando[10];


    //SE NÃO OUVER CANDIDATO INSCRITO APARECE ESSA MENSAGEM
    if(quant_candidato<=0)
    {
        strcpy(comando,"color 4f");
        system(comando);
        printf("\n\n|\n__________________________________________________________________|NÃO EXISTE CANDIDATO INSCRITO!|__________________________________________________________________|\n");
        printf("|***************************************************************|************************************|***************************************************************|\n");
        continuar_classi=false;
    }

    //CANDIDATO ESCOLHE A OPÇAÕ DO CURSO, QUE ELE SE ESCREVEU.
    while(continuar_classi)
    {

        printf("\n\n\t{*************************************************}");
        printf("\n\t{1 - Gerar Classificação Por Curso e Tipo de Vaga }");
        printf("\n\t{2 - Gerar classificação por Tipo de Vaga         }");
        printf("\n\t{3 - Gerar Classificação geral                    }");
        printf("\n\t{4 - Sair                                         }");
        printf("\n\t|*******|*****************************************");
        printf("\n\t|ENTRADA|-->  ");
        setbuf(stdin,NULL);
        scanf("%d",&opcao);
        system("cls");

        if(opcao==1)
        {

            do
            {
                imprime_curso_com_turno(cad,totcursos);
                opcao_curso=0;

                printf("\n\t _____________________________________________");
                printf("\n\t{*********************************************}\n");
                printf("\t{   Qual desses CURSOS você esta concorrendo? } ");
                printf("\n\t{_____________________________________________} ");
                printf("\n\t|*******|*************************************");
                printf("\n\t|ENTRADA|-->  ");
                setbuf(stdin,NULL);
                scanf("%d",&opcao_curso);

                if(opcao_curso>totcursos+1||opcao_curso<=0)
                {
                    system("cls");
                    printf("\n\a _____________________________________________________________________________________________________________________________________________________________________");
                    printf(" \n|*********************************************************************************************************************************************************************|");
                    printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
                    printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                    printf("\n***********************************************************************************************************************************************************************\n\n");

                }

            }

            //CANDIDATO INFORMA O TIPO DE VAGA QUE ELE ESTA CONCORRENDO
            while(opcao_curso>totcursos+1||opcao_curso<1);
        }
        visualizar_vaga_portipo(cad,totcursos);
        classificacao_por_curso_e_tipovaga_c1(candidato,c1,cad,quant_candidato,opcao_curso);
        classificacao_por_curso_e_tipovaga_c2(candidato,c2,cad,quant_candidato,opcao_curso);
        classificacao_por_curso_e_tipovaga_pcd(candidato,pcd,cad,quant_candidato,opcao_curso);
        classificacao_por_curso_e_tipovaga_a(candidato,a,cad,quant_candidato,opcao_curso);
        classificacao_reordenada_por_curso_e_tipo_vaga_aprovado(candidato,tipo_aprovado,cad,quant_candidato,opcao_curso);
        classificacao_reordenar_por_curso_e_tipovaga_espera(candidato,c1,c2,pcd,a,lista_espera,cad,quant_candidato,opcao_curso);
        imprime_tipo_vaga_por_curso_aprovados_e_lista_de_espera(cad,tipo_aprovado,lista_espera,opcao_curso,quant_candidato,totcursos);


        /* system("cls");
         strcpy(comando,"color 0a");
         system(comando);
         printf("\n|______________________________________________________________________|INFORME O TIPO DE VAGA|_______________________________________________________________________|\n");
         printf("|**********************************************************************|**********************|***********************************************************************|\n");

         do
         {
             visualizar_vaga_portipo(cad,totcursos);

             printf("\n\n                             |*******%s*******|\n",cad[opcao_curso-1].nome_curso);
             printf("\n\t*************************************************************\n");
             printf("\t|Codigo do curso: %d",cad[opcao_curso-1].codigo_curso);
             printf("\n\t|Nome do curso: %s",cad[opcao_curso-1].nome_curso);
             printf("\n\t|Quantidade de vagas: %d",cad[opcao_curso-1].quant_vagas);
             printf("\n\t|Turno do curso: %s",cad[opcao_curso-1].turno_curso);
             printf("\n\t|____________________________________________________________\n");
             printf("\t|                                                            |\n");
             printf("\t**************************************************************\n");
             printf("\t|Conta escola pública: %.0f vagas                               |",cad[opcao_curso-1].c);
             printf("\n\t|                                                            |");
             printf("\n\t|1° - Renda maior ou igual a 1 salário minimo: C1 = %.0f vagas  |",cad[opcao_curso-1].c1);
             printf("\n\t|2° - Renda menor que 1 salário minimo: C2 = %.0f vagas         |",cad[opcao_curso-1].c2);
             printf("\n\t|____________________________________________________________|\n");
             printf("\t|************************************************************|\n");
             printf("\t|____________________________________________________________|");
             printf("\n\t**************************************************************\n");
             printf("\t|3° - Pessoas com deficiência: PCD = %.0f vagas                 |",cad[opcao_curso-1].pcd);
             printf("\n\t|____________________________________________________________|");
             printf("\n\t**************************************************************\n");
             printf("\t|4° - Ampla concorrência: A = %.0f vagas                        |",cad[opcao_curso-1].a);
             printf("\n\t|____________________________________________________________|");

             printf("\n\n|________________________________________________________________________|  TIPO DE VAGAS  |__________________________________________________________________________|\n");
             printf("|************************************************************************|*****************|**************************************************************************|\n");

             printf("\n\t _____________________________________________");
             printf("\n\t{*********************************************}\n");
             printf("\t{   Qual dessas COTAS você esta concorrendo?  } ");
             printf("\n\t{_____________________________________________} ");
             printf("\n\t|*******|*************************************");
             printf("\n\t|ENTRADA|-->  ");
             setbuf(stdin,NULL);
             scanf("%d",&opcao_tipo_cota);


             if(opcao_tipo_cota>4||opcao_tipo_cota<1)
             {
                 system("cls");
                 printf("\n \a_____________________________________________________________________________________________________________________________________________________________________");
                 printf(" \n|*********************************************************************************************************************************************************************|");
                 printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
                 printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
                 printf("\n***********************************************************************************************************************************************************************\n\n");

             }

         }
         while(opcao_tipo_cota>4||opcao_tipo_cota<1);

         system("cls");
         printf("\n\n|___________________________________________________________________| LISTA DE CLASSIFICAÇÃO |________________________________________________________________________|\n");
         printf("|*******************************************************************|************************|************************************************************************|\n\n\n");
         x=-1;
         //CONFERE SE EXISTE ALGUM USUÁRIO CONCORRENDO PARA ESSE TIPO DE COTA
         if(opcao_tipo_cota==1)
         {
             for(i=0; i<quant_candidato; i++)
             {
                 strcpy(nome_curso,candidato[i].tipo_vaga);
                 if(strcmp(nome_curso,"C1: Renda maior ou igual a R$ 1,5 salários")==0)
                 {
                     x=strcmp(nome_curso,"C1: Renda maior ou igual a R$ 1,5 salários");
                     break;
                 }
             }

             if(x==1||x==-1)
             {
                 printf("\n\t _____________________________________________________");
                 printf("\n\t|Não existe candidato inscrito para esse tipo de vaga!|");
                 printf("\n\t*******************|Fique esperto!|********************");
                 printf("\n\t                   ****************\n\n");

                 continuar_classi=false;
             }
             else
             {
                 continuar_classi=false;
                 classificacao_por_curso_e_tipovaga_c1(candidato,c1,cad,quant_candidato,opcao_curso);

                 visualizar_vaga_portipo(cad,totcursos);

                 imprime_tipo_vaga_c1_por_curso_aprovados_e_lista_de_espera(cad,c1,opcao_curso,quant_candidato,totcursos);
             }

         }
         else
         {
             //CONFERE SE EXISTE ALGUM USUÁRIO CONCORRENDO PARA ESSE TIPO DE COTA
             if(opcao_tipo_cota==2)
             {
                 for(i=0; i<quant_candidato; i++)
                 {
                     strcpy(nome_curso,candidato[i].tipo_vaga);
                     if(strcmp(nome_curso,"C2: Renda menor que R$ 1,5 salários")==0)
                     {
                         x=strcmp(nome_curso,"C2: Renda menor que R$ 1,5 salários");
                         break;
                     }
                 }

                 if(x==1||x==-1)
                 {
                     printf("\n\t _____________________________________________________");
                     printf("\n\t|Não existe candidato inscrito para esse tipo de vaga!|");
                     printf("\n\t*******************|Fique esperto!|********************");
                     printf("\n\t                   ****************\n\n");

                     continuar_classi=false;
                 }
                 else
                 {
                     continuar_classi=false;
                     classificacao_por_curso_e_tipovaga_c2(candidato,c2,cad,quant_candidato,opcao_curso);

                     visualizar_vaga_portipo(cad,totcursos);

                     imprime_tipo_vaga_c2_por_curso_aprovados_e_lista_de_espera(cad,c2,opcao_curso,quant_candidato,totcursos);
                 }

             }
             else
             {
                 //CONFERE SE EXISTE ALGUM USUÁRIO CONCORRENDO PARA ESSE TIPO DE COTA
                 if(opcao_tipo_cota==3)
                 {
                     for(i=0; i<quant_candidato; i++)
                     {
                         strcpy(nome_curso,candidato[i].tipo_vaga);
                         if(strcmp(nome_curso,"PCD: Pessoa com deficiencia")==0)
                         {
                             x=strcmp(nome_curso,"PCD: Pessoa com deficiencia");
                             break;
                         }
                     }

                     if(x==1||x==-1)
                     {
                         printf("\n\t _____________________________________________________");
                         printf("\n\t|Não existe candidato inscrito para esse tipo de vaga!|");
                         printf("\n\t*******************|Fique esperto!|********************");
                         printf("\n\t                   ****************\n\n");

                         continuar_classi=false;
                     }
                     else
                     {
                         continuar_classi=false;
                         classificacao_por_curso_e_tipovaga_pcd(candidato,pcd,cad,quant_candidato,opcao_curso);

                         visualizar_vaga_portipo(cad,totcursos);

                         imprime_tipo_vaga_pcd_por_curso_aprovados_e_lista_de_espera(cad,pcd,opcao_curso,quant_candidato,totcursos);
                     }
                 }
                 else
                 {
                     //CONFERE SE EXISTE ALGUM USUÁRIO CONCORRENDO PARA ESSE TIPO DE COTA
                     if(opcao_tipo_cota==4)
                     {
                         for(i=0; i<quant_candidato; i++)
                         {
                             strcpy(nome_curso,candidato[i].tipo_vaga);
                             if(strcmp(nome_curso,"A: Ampla concorrência")==0)
                             {
                                 x=strcmp(nome_curso,"A: Ampla concorrência");
                                 break;
                             }
                         }

                         if(x==1||x==-1)
                         {
                             printf("\n\t _____________________________________________________");
                             printf("\n\t|Não existe candidato inscrito para esse tipo de vaga!|");
                             printf("\n\t*******************|Fique esperto!|********************");
                             printf("\n\t                   ****************\n\n");

                             continuar_classi=false;
                         }
                         else
                         {
                             continuar_classi=false;
                             classificacao_por_curso_e_tipovaga_a(candidato,a,cad,quant_candidato,opcao_curso);

                             visualizar_vaga_portipo(cad,totcursos);

                             imprime_tipo_vaga_a_por_curso_aprovados_e_lista_de_espera(cad,a,opcao_curso,quant_candidato,totcursos);


                         }
                     }
                 }
             }
         }
        }
        else
        {
         if(opcao==2)
         {
             do
             {
                 printf("\n\t _____________________________________________________\n");
                 printf("\t{\t\tCOTA ESCOLA PÚBLICA                   }");
                 printf("\n\t|                                                     |");
                 printf("\n\t{_____________________________________________________}\n");
                 printf("\t|1 - C1: Renda maior ou igual a R$1,5 salários minimos|");
                 printf("\n\t{_____________________________________________________}\n");
                 printf("\t|2 - C2: Renda menor que R$1,5 salário minimo         |");
                 printf("\n\t{_____________________________________________________}\n");
                 printf("\t|_____________________________________________________|\n");
                 printf("\t{3 - PCD: Pessoa com deficiencia                      }");
                 printf("\n\t|_____________________________________________________|\n");
                 printf("\t{_____________________________________________________}\n");
                 printf("\t|4 - A: Ampla concorrência                            | ");
                 printf("\n\t{_____________________________________________________}");
                 printf("\n\t|*****************************************************|");
                 printf("\n\t|ENTRADA|-->  ");
                 scanf("%d",&escolha_opcao);
                 system("cls");

                 if(escolha_opcao>4||escolha_opcao<1)
                 {

                     strcpy(comando,"color 4f");
                     system(comando);
                     printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
                     printf(" |**********************************************************************************************************************************************************************|");
                     printf("|                                                                        ESCOLHA A OPÇÃO CORRETA!                                                                      |");
                     printf("|______________________________________________________________________________________________________________________________________________________________________|");
                     printf("|**********************************************************************************************************************************************************************|\n\n");

                 }

             }
             while(escolha_opcao>4||escolha_opcao<1);

             if(escolha_opcao==1)
             {
                 visualizar_vaga_portipo(cad,totcursos);
                 classificacao_por_tipovaga_c1(candidato,vaga_c1,cad,quant_candidato,totcursos);
                 imprime_tipo_vaga_c1_aprovados_e_lista_de_espera(cad,vaga_c1,quant_candidato,totcursos);
             }
             else
             {
                 if(escolha_opcao==2)
                 {
                     visualizar_vaga_portipo(cad,totcursos);
                     classificacao_por_tipovaga_c2(candidato,vaga_c2,cad,quant_candidato,totcursos);
                     imprime_tipo_vaga_c2_aprovados_e_lista_de_espera(cad,vaga_c2,quant_candidato,totcursos);
                 }
                 else
                 {
                     if(escolha_opcao==3)
                     {
                         visualizar_vaga_portipo(cad,totcursos);
                         classificacao_por_tipovaga_pcd(candidato,vaga_pcd,cad,quant_candidato,totcursos);
                         imprime_tipo_vaga_pcd_aprovados_e_lista_de_espera(cad,vaga_pcd,quant_candidato,totcursos);
                     }
                     else
                     {
                         if(escolha_opcao==4)
                         {
                             visualizar_vaga_portipo(cad,totcursos);
                             classificacao_por_tipovaga_a(candidato,vaga_a,cad,quant_candidato,totcursos);
                             imprime_tipo_vaga_a_aprovados_e_lista_de_espera(cad,vaga_a,quant_candidato,totcursos);
                         }
                     }
                 }
             }
         }
        }

        printf("\n\n\n|______________________________________________________________|  DESEJA CONTINUAR COM A PESQUISA?  |________________________________________________________________|\n");
        printf("|**************************************************************|************************************|****************************************************************|\n");

        do
        {
         printf("\n\n\t{**********}");
         printf("\n\t{1 - [SIM] }");
         printf("\n\t{2 - [NÃO] }");
         printf("\n\t|*******|***\n");
         printf("\t|ENTRADA|--> ");
         setbuf(stdin,NULL);
         scanf("%d",&continuar);

         if(continuar>2||continuar<1)
         {
             system("cls");
             strcpy(comando,"color 4f");
             system(comando);
             printf("\n\a _____________________________________________________________________________________________________________________________________________________________________");
             printf(" \n|*********************************************************************************************************************************************************************|");
             printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
             printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
             printf("\n***********************************************************************************************************************************************************************\n\n");

         }
         if(continuar==1)
         {
             system("cls");
             continuar_classi=true;
         }
         else
         {
             if(continuar==2)
             {
                 system("cls");
                 continuar_classi=false;
             }
         }

        }
        while(continuar>2||continuar<1);*/

    }
    while(continuar_classi);

};
