#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

//STRUCT CRIADA PARA VERIFICAR EM QUAL LINHA,COLUNA E DIAGONAIS O JOGADOR GANHOU.
struct verificadores
{
    int linha1_x,linha1_0;
    int linha2_x,linha2_0;
    int linha3_x,linha3_0;
    int coluna1_x,coluna1_0;
    int coluna2_x,coluna2_0;
    int coluna3_x,coluna3_0;
    int diagonal_principal_x;
    int diagonal_principal_0;
    int diagonal_secundaria_x;
    int diagonal_secundaria_0;
} Ganhou_na;

//FUNÇÃO RESPONSAVEL EM LER A LETRA INICIAL DO JOGADOR 1 E DO JOGADOR 2 E SALVAR NOS ARQUIVOS
//CORRESPONDENTES. TAMBÉM É RESPONSAVEL EM LER A VARIAVEL GLOBAL PROXIMO_JOGADOR QUE ESTAR GRAVADA NO ARQUIVO.
void Jogador_Informa_Inicial(char *nome1,char *nome2);

//IMPRIME A MATRIZ,GRAVA E LÊ OS AQUIVOS DO JOGO DA VELHA (TABULEIRO).
void imprimir_Matriz(char mat[3][3],FILE *arq);

//AQUI É AONDE O JOGO ACONTECE: O USUÁRIO ESCOLHE A OPÇÃO NO TABULEIRO, GRAVA OS AQUIVOS DO JOGO,
//GRAVA OS AQUIVOS DO PROXIMO JOGADOR E REMOVE OS ARQUIVOS QUANDO OCORRE GANHADOR OU QUANDO NÃO A GANHADOR.
void jogo_da_velha(char mat[3][3],struct verificadores *Ganhou_na,FILE *arq,char *nome1,char *nome2);

//VERIFICA QUEM VAI SER O PROXIMO JOGADOR A JOGAR, LE O ARQUIVO E ARMAZENA NA VARIAVEL RESPONSAVEL
//EM RETORNAR PARA A FUNÇÃO JOGO_DA_VELHA.
char Verificar_dequem_ea_vez(bool ganhador,char Jogador_x_ou_0);

//VERIFICA EM QUAL POSIÇÃO DA MATRIZ O JOGADOR GANHOU.
bool Verificar_campeao(bool vitorioso,char mat[3][3], struct verificadores *Ganhou_na,char *nome1,char *nome2);

//VARIAVEL GLOBAL, SERVE PARA SABER QUEM VAI SER O PROXIMO JOGADOR A JOGAR (DE QUEM E A VEZ DE JOGAR)
int proximo_jogador=0;

int main()
{
    //FUNÇÃO QUE GARANTE A  EXIBIÇÃO NORMALMENTE DA ACENTUAÇÃO
    setlocale(LC_ALL,"portuguese");

    //FUNÇÃO UTILIZADA PARA ALTERAR AS CORES DO PROGRAMA
    SetConsoleTitle("Cores com system");

    //GRAVA O JOGO DA VELHA
    FILE *arq;

    //TABULEIRO DO JOGO DA VELHA.
    char tabuleiro[3][3]= {'1','2','3','4','5','6','7','8','9'};

    //VARIAVEIS DO TIPO PRIMITIVO CHAR DE CARACTERE: UTILIZADAS PARA ARMAZENAR A LETRA INICIAL
    //DO NOME DE CADA JOGADOR
    char jogador1,jogador2;

    ///STRUCT E FUNÇÕES: JÁ FORAM INFORMADAS AS FUNCIONALIDADES NO INÍCIO DO CODIGO.
    struct verificadores;
    Jogador_Informa_Inicial(&jogador1,&jogador2);
    imprimir_Matriz(tabuleiro,arq);
    jogo_da_velha(tabuleiro, &Ganhou_na,arq,&jogador1,&jogador2);

    system("pause");
    return 0;
}
void Jogador_Informa_Inicial(char *nome1,char *nome2)
{
    //GRAVA O ARQUIVO DO PROXIMO JOGADOR A JOGAR
    FILE *salva_proximo_jogador;
    int guardar_proximo_jogador;

    //LÊ O ARQUIVO DO PROXIMO JOGADOR A JOGAR.
    FILE *abrir_proximo_jogador;
    int abrir_jogador;

    //LÊ O ARQUIVO DO PROXIMO JOGADOR QUE VAI JOGAR E ARMAZENA NA VARIAVEL(PROXIMO_JOGADOR)
    //abrir_proximo_jogador = fopen("Proximo_Jogador.txt","r");
    abrir_proximo_jogador = fopen("Proximo_Jogador.txt","r");
    if(abrir_proximo_jogador == NULL)
    {
        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
        if(salva_proximo_jogador == NULL)
        {
            printf("Problemas na ABERTURA do arquivo\n");
            system("pause");
            exit(1);
        }
        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);

    }
    else
    {
        abrir_proximo_jogador = fopen("Proximo_Jogador.txt","r");
        fscanf(abrir_proximo_jogador,"%d",&abrir_jogador);
        proximo_jogador=abrir_jogador;
        fclose(abrir_proximo_jogador);
    }

    //ARQUIVOS RESPONSAVEIS EM GRAVAR A LETRA INICIAL DO NOME DE CADA JOGADOR
    FILE *salvar_jogador1;
    FILE *salvar_jogador2;

    //VARIAVEL (Usuario1 E Usuario2) É DO TIPO PRIMITIVO CHAR DE STRING:
    //NELA E GRAVADA (ARMAZENADA) A LETRA INICIAL DO NOME DE CADA JOGADOR
    char Usuario1[5];
    char Usuario2[5];

    if(proximo_jogador == 0)
    {
        ///JOGADOR 1 INFORMA A INICIAL
        printf("\n\t1° Jogador:");
        printf("\nInforme a letra inicial do seu NOME: ");
        fflush(stdin);
        *nome1=getchar();

        //ARQUIVO RESPONSAVEL EM GRAVAR A LETRA INICIAL DO NOME DO JOGADOR 1:
        salvar_jogador1 = fopen("Jogador1.txt","w");
        if(salvar_jogador1 == NULL)
        {
            printf("Erro na abertura do arquivo");
            system("pause");
            exit(1);
        }
        int j=0;
        for(j=0; j<1; j++)
        {
            Usuario1[j]=*nome1;
        }
        Usuario1[j]='\0';
        //GRAVA A STRING, CARACTERE A CARACTERE
        for(int i = 0; i < strlen(Usuario1); i++)
        {
            fputc(Usuario1[i],salvar_jogador1);
        }
        fclose(salvar_jogador1);

        ///JOGADOR 2 INFORMA A INICIAL
        printf("\n\t2° Jogador:");
        printf("\nInforme a letra inicial do seu NOME: ");
        fflush(stdin);
        *nome2=getchar();

        //ARQUIVO RESPONSAVEL EM GRAVAR A LETRA INICIAL DO NOME DO JOGADOR 2:
        salvar_jogador2 = fopen("Jogador2.txt","w");
        if(salvar_jogador2 == NULL)
        {
            printf("Erro na abertura do arquivo");
            system("pause");
            exit(1);
        }
        for(j=0; j<1; j++)
        {
            Usuario2[j]=*nome2;
        }
        Usuario2[j]='\0';
        //GRAVA A STRING, CARACTERE A CARACTERE
        for(int i = 0; i < strlen(Usuario2); i++)
        {
            fputc(Usuario2[i],salvar_jogador2);
        }
        fclose(salvar_jogador2);
    }
}
void imprimir_Matriz(char mat[3][3],FILE *arq)
{
    //ARQUIVO QUE LÊ O JOGO DA VELHA
    FILE *abrir_jogo;
    //COMANDO UTILIZADO PARA MODIFICAR A COR DO PROGRAMA
    char comando[9]="color";

    printf("\n\a ______________________________________________________________________________________________________________________________________________________________________");
    printf(" |**********************************************************************************************************************************************************************|");
    printf("|                                                                            JOGO  DA  VELHA                                                                           |");
    printf("|______________________________________________________________________________________________________________________________________________________________________|");
    printf("|**********************************************************************************************************************************************************************|\n\n");

    //SO VAI GRAVAR O JOGO, SE A VARIAVEL GLOBAL -> PROXIMO_JOGADOR FOR IGUAL A ZERO
    if(proximo_jogador == 0)
    {
        strcpy(comando,"color 09");
        system(comando);
        arq = fopen("jogo.txt","w");
        if(arq == NULL)
        {
            printf("Erro\n");
            system("pause");
            exit(1);
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                fprintf(arq,"%c",mat[i][j]);
            }
            fprintf(arq,"\n");

        }
        printf("\t  +----------------+\n");
        for(int l=0; l<3; l++)
        {
            printf("\t  ");
            for(int c=0; c<3; c++)
            {
                printf("|  %c ",mat[l][c]);

            }
            printf("  | ");
            printf("\n\t  +----------------+\n");
        }
        fclose(arq);
    }
    else
    {
        //SO VAI LER O ARQUIVO DO JOGO SE A VARIAVEL GLOBAL -> PROXIMO_JOGADOR FOR > QUE ZERO
        if(proximo_jogador > 0)
        {
            abrir_jogo=fopen("jogo.txt","r");
            if(abrir_jogo == NULL)
            {
                printf("Erro\n");
                system("pause");
                exit(1);

            }
            while(!feof(abrir_jogo))
            {
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        fscanf(abrir_jogo,"%c",&mat[i][j]);

                    }
                    fscanf(abrir_jogo,"\n");

                }
            }
            printf("\t  +----------------+\n");
            for(int l=0; l<3; l++)
            {
                printf("\t  ");
                for(int c=0; c<3; c++)
                {
                    printf("|  %c ",mat[l][c]);

                }
                printf("  | ");
                printf("\n\t  +----------------+\n");
            }
            fclose(abrir_jogo);
        }
    }
}
//AQUI É AONDE O JOGO ACONTECE:
void jogo_da_velha(char mat[3][3],struct verificadores *Ganhou_na,FILE *arq,char *nome1,char *nome2)
{
    //VARIAVEL X: DO TIPO PRIMITIVO CHAR DE CARACTERE: INICIA O JOGO COM A LETRA DO 1° JOGADOR.
    char x=*nome1;

    //VARIAVEL VERIFICAR_OPCAO: DO TIPO PRIMITIVO CHAR DE STRING: UTILIZADA PARA ARMAZENAR A OPÇÃO DO JOGADOR.
    char verificar_opcao[5];

    //VARIAVEL OPCAO: DO TIPO PRIMITIVO CHAR DE CARACTERE: UTILIZADA PARA RECEBER A OPÇÃO DO JOGADOR DA
    //VARIAVEL VERIFICAR_OPCAO.
    char opcao;

    //VARIAVEL CAMPEAO: DO TIPO PRIMITIVO BOLEANA, UTILIZADA PARA PARA DAR INICIO E ENCERRAR O JOGO.
    bool campeao=true;

    //ARQUIVO QUE LER O PROXIMO JOGADOR.
    FILE *proximo;

    //ARQUIVO QUE GRAVA PROXIMO JOGADOR.
    FILE *salva_proximo_jogador;

    //VARIAVEIS QUE SÃO UTILIZADAS PARA REMOVER E GRAVAR ARQUIVOS.
    int status_tabuleiro;
    int status_proximo_Jogador;
    int guardar_proximo_jogador;
    int status_Jogador1;
    int status_Jogador2;

    //FUNÇÃO UTILIZADA PARA MODIFICAR A COR DO JOGO.
    char comando[9]="color";

    //SO ENCERRRA O JOGO QUANDO A VARIAVEL CAMPEAO FOR IGUAL A FALSE.
    while(campeao)
    {
        if(proximo_jogador!=0)
        {
            // x=Verificar_dequem_ea_vez(campeao,x);
        }
        printf("\n           ___________________________");
        printf("\n          {***************************}\n");
        printf("          { Digite um número para (%c) } ",x);
        printf("\n          {___________________________} ");
        printf("\n           |*******|*******************");
        printf("\n           |ENTRADA|-->  ");
        //O JOGADOR ESCOLHE A OPÇÃO NO TABULEIRO E ARMAZENA NA VARIAVEL: VERIFICAR_OPCAO.
        fflush(stdin);
        gets(verificar_opcao);
        int tamanho = strlen(verificar_opcao);
        system("cls");

        for(int i=0; i<tamanho; i++)
        {
            //VERIFICA SE A OPÇÃO DO JAGADOR E VALIDA (SE CONSTA A OPÇÃO NO TABULEIRO)
            if(strcmp(verificar_opcao,"1")==0 || strcmp(verificar_opcao,"2")==0 || strcmp(verificar_opcao,"3")==0 || strcmp(verificar_opcao,"4")==0 || strcmp(verificar_opcao,"5")==0 || strcmp(verificar_opcao,"6")==0 || strcmp(verificar_opcao,"7")==0 || strcmp(verificar_opcao,"8")==0 || strcmp(verificar_opcao,"9")==0)
            {
                opcao=verificar_opcao[i];
            }
            //SE A OPÇÃO ESCOLHIDA PELO USUÁRIO NÃO FOR VALIDA, A VARIAVEL OPCAO RECEBE ZERO.
            else
            {
                opcao='0';
            }

        }
        if(opcao == '0')
        {
            printf("\n\a _____________________________________________________________________________________________________________________________________________________________________");
            printf(" \n|*********************************************************************************************************************************************************************|");
            printf("\n|                                                                        OPÇÃO INVALIDA!                                                                              |");
            printf("\n|_____________________________________________________________________________________________________________________________________________________________________|");
            printf("\n***********************************************************************************************************************************************************************\n\n");
            strcpy(comando,"color 4f");
            system (comando);
        }
        //SE A VARIAVEL OPCAO ESTIVER ENTRE 1 E 9, SEGUE O FLUXO
        if(opcao<='9' && opcao>='1')
        {
             strcpy(comando,"color 1f");
            system(comando);
            for(int l=0; l<3; l++)
            {
                for(int c=0; c<3; c++)
                {
                    //SE NO TABULEIRO EXISTIR O NÚMERO 1 E A OPCAO ESCOLHIDA PELO JOGADOR E 1, SEGUE O FLUXO
                    if(mat[l][c] == '1' && opcao == '1')
                    {
                        //VARIAVEL X QUE INICIA O JOGO COM A (LETRA INICIAL DO NOME DO JOGADOR1) É ADICIONADA NA MATRIZ
                        mat[l][c]=x;

                        //ESSA FUNÇÃO: VERIFICA O GANHADOR E RETORNA UM VALOR BOLEANO
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);

                        //VARIAVEL GLOBAL,PROXIMO_JOGADOR: INCREMENTA MAIS UM, PARA O PROXIMO JOGADOR JOGAR
                        proximo_jogador++;

                        //GRAVA A VARIAVEL GLOBAL PROXIMO_JOGADOR NO ARQUIVO.
                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        //GRAVA O JOGO DA VELHA
                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '2' && opcao == '2')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '3' && opcao == '3')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '4' && opcao == '4')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '5' && opcao == '5')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '6' && opcao == '6')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '7' && opcao == '7')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '8' && opcao == '8')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                    if(mat[l][c] == '9' && opcao == '9')
                    {
                        mat[l][c]=x;
                        campeao=Verificar_campeao(campeao,mat,Ganhou_na,nome1,nome2);
                        proximo_jogador++;

                        salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                        if(salva_proximo_jogador == NULL)
                        {
                            printf("Problemas na ABERTURA do arquivo\n");
                            system("pause");
                            exit(1);
                        }
                        guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                        if(guardar_proximo_jogador < 0)
                            printf("Erro na escrita\n");

                        fclose(salva_proximo_jogador);

                        arq = fopen("jogo.txt","w");
                        if(arq == NULL)
                        {
                            printf("Erro\n");
                            system("pause");
                            exit(1);
                        }
                        for(int i = 0; i < 3; i++)
                        {
                            for(int j = 0; j < 3; j++)
                            {
                                fprintf(arq,"%c",mat[i][j]);
                            }
                            fprintf(arq,"\n");

                        }
                        fclose(arq);
                    }
                }
            }
        }
        //IMPRIME A MATRIZ COM O JOGO SALVO NO ARQUIVO
        imprimir_Matriz(mat,arq);
        //FUNÇÃO QUE FICA RESPONSAVEL DE CONTROLAR DE QUEM É A VEZ (JOGADOR1 OU JOGADOR2)
        x=Verificar_dequem_ea_vez(campeao,x);

        ///CONDICIONAL RESPONSAVEL DE CONTROLAR QUEM VENCEU E CONSEQUENTEMENTE REMOVER OS ARQUIVOS DO JOGO
        ///E O ARQUIVO GRAVA O JOGO DA VELHA E A VARIAVEL PROXIMO_JOGADOR PARA QUANDO INICIAR O JOGO NÃO HAVER
        ///PRIBLEMAS NA LEITURA DO ARQUIVO.
        if(campeao==false)
        {
            printf("\n\t\aO JOGADOR [%c] É O VENCEDOR!\n\n",x);
            campeao=false;

            //REMOVE O ARQUIVO DA VARIAVEL JOGADOR1: QUE CONTROLA A LETRA INICIAL DO JOGADOR1
            status_Jogador1 = remove("Jogador1.txt");
            if(status_Jogador1 != 0)
            {
                printf("Erro na remocao do arquivo.\n");
                system("pause");
                exit(1);
            }
            else
                printf("Arquivo removido com sucesso.\n");

            //REMOVE O ARQUIVO DA VARIAVEL JOGADOR2: QUE CONTROLA A LETRA INICIAL DO JOGADOR2
            status_Jogador2 = remove("Jogador2.txt");
            if(status_Jogador2 != 0)
            {
                printf("Erro na remocao do arquivo.\n");
                system("pause");
                exit(1);
            }
            else
                printf("Arquivo removido com sucesso.\n");

            //GRAVA O ARQUIVO DA VARIAVERL GLOBAL PROXIMO_JOGADOR
            proximo_jogador=0;
            salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
            if(salva_proximo_jogador == NULL)
            {
                printf("Problemas na ABERTURA do arquivo\n");
                system("pause");
                exit(1);
            }
            guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
            if(guardar_proximo_jogador < 0)
                printf("Erro na escrita\n");

            fclose(salva_proximo_jogador);

            //GRAVA O JOGO DA VELHA
            arq = fopen("jogo.txt","w");
            if(arq == NULL)
            {
                printf("Erro\n");
                system("pause");
                exit(1);
            }
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    fprintf(arq,"%c",mat[i][j]);
                }
                fprintf(arq,"\n");

            }
            fclose(arq);

        }
        else
        {
            ///CONDICIONAL RESPONSAVEL DE CONTROLAR, QUANDO NÃO A VENCEDOR (DEU VELHA) E CONSEQUENTEMENTE REMOVER OS ARQUIVOS DO JOGO
            ///E GRAVAR O ARQUIVO DO JOGO DA VELHA E GRAVAR O ARQUIVO DA VARIAVEL PROXIMO_JOGADOR
            ///PARA QUANDO INICIAR O JOGO NÃO HAVER PROBLEMAS NA LEITURA DO ARQUIVO.
            if(proximo_jogador==9)
            {
                strcpy(comando,"color 2e");
                system (comando);
                printf("\n\t\t\aDEU VELHA!\n\n");
                campeao=false;


                //REMOVE O ARQUIVO DA VARIAVEL JOGADOR1: QUE CONTROLA A LETRA INICIAL DO JOGADOR1
                status_Jogador1 = remove("Jogador1.txt");
                if(status_Jogador1 != 0)
                {
                    printf("Erro na remocao do arquivo.\n");
                    system("pause");
                    exit(1);
                }
                else
                    printf("Arquivo removido com sucesso.\n");

                //REMOVE O ARQUIVO DA VARIAVEL JOGADOR2: QUE CONTROLA A LETRA INICIAL DO JOGADOR2
                status_Jogador2 = remove("Jogador2.txt");
                if(status_Jogador2 != 0)
                {
                    printf("Erro na remocao do arquivo.\n");
                    system("pause");
                    exit(1);
                }
                else
                    printf("Arquivo removido com sucesso.\n");

                //GRAVA O ARQUIVO DA VARIAVERL GLOBAL PROXIMO_JOGADOR
                proximo_jogador=0;
                salva_proximo_jogador = fopen("Proximo_Jogador.txt","w");
                if(salva_proximo_jogador == NULL)
                {
                    printf("Problemas na ABERTURA do arquivo\n");
                    system("pause");
                    exit(1);
                }
                guardar_proximo_jogador = fprintf(salva_proximo_jogador,"%d\n",proximo_jogador);
                if(guardar_proximo_jogador < 0)
                    printf("Erro na escrita\n");

                fclose(salva_proximo_jogador);

                //GRAVA O ARQUIVO DO JOGO DA VELHA.
                arq = fopen("jogo.txt","w");
                if(arq == NULL)
                {
                    printf("Erro\n");
                    system("pause");
                    exit(1);
                }
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        fprintf(arq,"%c",mat[i][j]);
                    }
                    fprintf(arq,"\n");

                }
                fclose(arq);

            }

        }

    }
}
//VERIFICA SE VAI JOGAR COM A LETRA INICIAL DO JOGADOR1 OU JOGADOR2
char Verificar_dequem_ea_vez(bool ganhador,char Jogador_x_ou_0)
{
    //ARQUIVOS RESPONSAVEIS EM LER A LETRA INICIAL DO NOME DOS JOGADORES
    FILE *Jogador1;
    FILE *Jogador2;

    //A VARIAVEL GANHADOR DO TIPO PRIMITIVO BOLEANO RECEBE COMO PARAMETRO A VARIAVEL (CAMPEAO) QUE É
    //TAMBEM DO TIPO PRIMITIVO BOLEANO, QUANDO A (VARIAVEL CAMPEAO) RECEBE FALSE
    //A VARIAVEL GANHADOR NÃO VAI CONTROLAR A ALTERNÂNCIA ENTRE A LETRA INICIAL DO JOGADOR1 E JOGADOR2,
    //PORQUE HOUVE UM GANHADOR
    if(ganhador==true)
    {
        //VARIAVEL GLOBAL PROXIMO_JOGADOR SE FOR PAR: A LETRA DO JOGADOR1 RETORNA PARA A FUNÇÃO...
        if(proximo_jogador%2==0)
        {
            //ARQUIVO RESPONSAVEL EM LER A LETRA INICIAL DO NOME DO JOGADOR1
            Jogador1 = fopen("Jogador1.txt","r");
            if(Jogador1 == NULL)
            {
                printf("Erro na abertura do arquivo");
                system("pause");
                exit(1);
            }
            for(int i = 0; i < 1; i++)
            {
                Jogador_x_ou_0 = fgetc(Jogador1);
            }
            fclose(Jogador1);
            //VARIAVEL DO TIPO PRIMITIVO CHAR DE CARACTERE: RETORNA COM A LETRA INICIAL
            //DO NOME DO JOGADOR1
            return Jogador_x_ou_0;
        }
        else
        {
            //VARIAVEL GLOBAL PROXIMO_JOGADOR SE FOR IMPAR: A LETRA DO JOGADOR2 RETORNA PARA A FUNÇÃO...
            if(proximo_jogador%2==1)
            {
                //ARQUIVO RESPONSAVEL EM LER A LETRA INICIAL DO NOME DO JOGADOR2
                Jogador2 = fopen("Jogador2.txt","r");
                if(Jogador2 == NULL)
                {
                    printf("Erro na abertura do arquivo");
                    system("pause");
                    exit(1);
                }
                for(int i = 0; i < 1; i++)
                {
                    Jogador_x_ou_0 = fgetc(Jogador2);
                }
                fclose(Jogador2);
                //VARIAVEL DO TIPO PRIMITIVO CHAR DE CARACTERE: RETORNA COM A LETRA INICIAL
                //DO NOME DO JOGADOR2
                return Jogador_x_ou_0;
            }
        }
    }
}
//FUNÇÃO RESPONSAVEL DE VERIFICAR O GANHADOR
bool Verificar_campeao(bool vitorioso,char mat[3][3],struct verificadores *Ganhou_na,char *nome1,char *nome2)
{
    ///VARIAVEL DO TIPO PRIMITIVO BOLEANO (VITORIOSO): QUANDO RECEBE FALSE É PORQUE HOUVE GANHADOR.
    ///ENTÃO ELA RETORNA PARA A FUNÇÃO JOGO DA VELHA INFORMANDO QUEM FOI O GANHADOR
    vitorioso=true;

    //ARQUIVOS ULILIZADOR PARA LER A LETRA INICIAL DE CADA JOGADOR
    FILE *Jogador1;
    FILE *Jogador2;

    //FUNÇÃO UTILIZADA PARA MUNDAR A COR DE TELA DE FUNDO: A CADA POSIÇÃO DA MATRIZ QUE O
    //JOGADOR GANHAR VAI MOSTRAR UMA COR DIFERENTE.
    char comando[9]="color";

    //O ARQUIVO JOGADOR1 LÊ E ARMAZENA NA VARIAVEL NOME1 A LETRA INICIAL DO JOGADOR CORRESPONDENTE.
    Jogador1 = fopen("Jogador1.txt","r");
    if(Jogador1 == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    for(int i = 0; i < 1; i++)
    {
        *nome1 = fgetc(Jogador1);
    }
    fclose(Jogador1);

    //O ARQUIVO JOGADOR2 LÊ E ARMAZENA NA VARIAVEL NOME2 A LETRA INICIAL DO JOGADOR CORRESPONDENTE.
    Jogador2 = fopen("Jogador2.txt","r");
    if(Jogador2 == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    for(int i = 0; i < 1; i++)
    {
        *nome2 = fgetc(Jogador2);
    }
    fclose(Jogador2);

    //STRUCT: INCREMENTA MAIS 1, QUANDO A LETRA E ENCONTRADA NA (1° LINHA)
    //CADA VARIAVEL DA STRUCT, FICA RESPONSAVEL EM INCREMENTA, DE ACORDO A
    //LETRA INICIAL DO JOGADOR CORRESPONDENTE
    Ganhou_na->linha1_x=0;
    Ganhou_na->linha1_0=0;
    //VERIFICA SE O JOGADOR GANHOU NA HORIZONTAL (1° LINHA):
    for(int l=0; l<1; l++)
    {
        for(int c=0; c<3; c++)
        {
            //VERIFICA SE GANHOU COM A LETRA INICIAL DO NOME DO JOGADOR1
            if(mat[l][c] == *nome1)
            {
                //A STRUCT GANHOU_NA, INCREMENTA MAIS 1 NA VARIAVEL LINHA_X
                Ganhou_na->linha1_x++;
            }
            //VERIFICA SE GANHOU COM A LETRA INICIAL DO NOME DO JOGADOR2
            if(mat[l][c] == *nome2)
            {
                // A STRUCT GANHOU_NA, INCREMENTA MAIS 1 NA VARIAVEL LINHA_0
                Ganhou_na->linha1_0++;
            }
            //VERIFICA SE NA HORIZONTAL POSSUI 3 X OU 3 ZEROS
            if(Ganhou_na->linha1_x == 3 || Ganhou_na->linha1_0 == 3)
            {
                //RETORNA FALSE PARA A VARIAVEL CAMPEAO.
                vitorioso = false;
                strcpy(comando,"color 1f");
                system (comando);
            }
        }
    }
    Ganhou_na->linha2_x=0;
    Ganhou_na->linha2_0=0;
    //VERIFICA SE O JOGADOR GANHOU NA HORIZONTAL (2° LINHA):
    for(int l=1; l<2; l++)
    {
        for(int c=0; c<3; c++)
        {
            if(mat[l][c] == *nome1)
            {
                Ganhou_na->linha2_x++;
            }
            if(mat[l][c] == *nome2)
            {
                Ganhou_na->linha2_0++;
            }
            if(Ganhou_na->linha2_x == 3 || Ganhou_na->linha2_0 == 3)
            {
                vitorioso = false;
                strcpy(comando,"color 0d");
                system (comando);
            }
        }
    }
    Ganhou_na->linha3_x=0;
    Ganhou_na->linha3_0=0;
    //VERIFICA SE O JOGADOR GANHOU NA HORIZONTAL (3° LINHA):
    for(int l=2; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            if(mat[l][c] == *nome1)
            {
                Ganhou_na->linha3_x++;
            }
            if(mat[l][c] == *nome2)
            {
                Ganhou_na->linha3_0++;
            }
            if(Ganhou_na->linha3_x == 3 || Ganhou_na->linha3_0 == 3)
            {
                vitorioso = false;
                strcpy(comando,"color 49");
                system (comando);
            }
        }
    }
    Ganhou_na->coluna1_x=0;
    Ganhou_na->coluna1_0=0;
    //VERIFICA SE O JOGADOR GANHOU NA VERTICAL (1° COLUNA):
    for(int l=0; l<3; l++)
    {
        for(int c=0; c<1; c++)
        {
            if(mat[l][c] == *nome1)
            {
                Ganhou_na->coluna1_x++;
            }
            if(mat[l][c] == *nome2)
            {
                Ganhou_na->coluna1_0++;
            }
            if(Ganhou_na->coluna1_x == 3 || Ganhou_na->coluna1_0 == 3)
            {
                vitorioso = false;
                strcpy(comando,"color 7d");
                system (comando);
            }
        }
    }
    Ganhou_na->coluna2_x=0;
    Ganhou_na->coluna2_0=0;
    //VERIFICA SE O JOGADOR GANHOU NA VERTICAL (2° COLUNA):
    for(int l=0; l<3; l++)
    {
        for(int c=1; c<2; c++)
        {
            if(mat[l][c] == *nome1)
            {
                Ganhou_na->coluna2_x++;
            }
            if(mat[l][c] == *nome2)
            {
                Ganhou_na->coluna2_0++;
            }
            if(Ganhou_na->coluna2_x == 3 || Ganhou_na->coluna2_0 == 3)
            {
                vitorioso = false;
                strcpy(comando,"color 6D");
                system (comando);
            }
        }
    }
    Ganhou_na->coluna3_x=0;
    Ganhou_na->coluna3_0=0;
    //VERIFICA SE O JOGADOR GANHOU NA VERTICAL (3° COLUNA):
    for(int l=0; l<3; l++)
    {
        for(int c=2; c<3; c++)
        {
            if(mat[l][c] == *nome1)
            {
                Ganhou_na->coluna3_x++;
            }
            if(mat[l][c] == *nome2)
            {
                Ganhou_na->coluna3_0++;
            }
            if(Ganhou_na->coluna3_x == 3 || Ganhou_na->coluna3_0 == 3)
            {
                vitorioso = false;
                strcpy(comando,"color 2f");
                system (comando);
            }
        }
    }
    Ganhou_na->diagonal_principal_x=0;
    Ganhou_na->diagonal_principal_0=0;
    //VERIFICA SE O JOGADOR VENCEU NA DIAGONAL PRINCIPAL:
    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            if(l==c)
            {
                if(mat[l][c] == *nome1)
                {
                    Ganhou_na->diagonal_principal_x++;
                }
                if(mat[l][c] == *nome2)
                {
                    Ganhou_na->diagonal_principal_0++;
                }
                if(Ganhou_na->diagonal_principal_x == 3 || Ganhou_na->diagonal_principal_0 == 3)
                {
                    vitorioso=false;
                    strcpy(comando,"color 3f");
                    system (comando);
                }
            }
        }
    }
    Ganhou_na->diagonal_secundaria_x=0;
    Ganhou_na->diagonal_secundaria_0=0;
    //VERIFICA SE O JOGADOR VENCEU NA DIAGONAL SECUNDARIA:
    for(int l=0; l<3; l++)
    {
        for(int c=0; c<3; c++)
        {
            if(l+c==2)
            {
                if(mat[l][c] == *nome1)
                {
                    Ganhou_na->diagonal_secundaria_x++;
                }
                if(mat[l][c] == *nome2)
                {
                    Ganhou_na->diagonal_secundaria_0++;
                }
                if(Ganhou_na->diagonal_secundaria_x  == 3 || Ganhou_na->diagonal_secundaria_0 == 3 )
                {
                    vitorioso=false;
                    strcpy(comando,"color 0c");
                    system (comando);
                }
            }
        }
    }
    //SE NÃO HOUVER GANHADOR, A VARIAVEL VITORIOSO: DO TIPO PRIMITIVO BOLEANO RETORNA (TRUE) PARA A
    //VARIAVEL CAMPEAO DO TIPO PRIMITIVO BOLEANO.
    return vitorioso;
}
