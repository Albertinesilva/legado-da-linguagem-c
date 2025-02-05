#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>


//ESTRUTURA PARA CADASTRO DE MORADORERS DE CADA APARTAMENTO DO CONDOMÍNIO:
struct condominio
{
    char nome_morador[10];
    int num_apart;
    float area;
    int num_moradores;
} vetor[3];

//FUNÇÃO: MENU DE CADASTRO DOS APARTAMENTOS
int menu(void);

//FUNÇÃO: CÁLCULO DA ÁREA COMUM (CONDOMINIO), E CÁLCULO DE  ÁREA DO EDIFÍCIO
//ONDE É FEITO O CÁLCULO PARA TRANSFORMAR AS ÁREAS EM PORCENTAGEM
float calculo_area(float area_cond,float area_edf);

/*ESTRUTURA QUE PASSA E RECEBE INFORMAÇÕES:
  ÁREA(EM M2)DO APARTAMENTO, ÁREA (EM M2) COMUM DO CONDOMÍNIO
  ÁREA(EM M2) DO EDIFÍCIO E DESPESAS DO CONDOMINIO. ONDE É FEITO O CALCULO DO PAGAMENTO DO INQUILINO
  CÁLCULO CHAMADO DE (FRAÇÃO IDEAL) */
struct condominio despesas(struct condominio tam_area[],int x,float  valor_pago_mes[],int y,float m2_condominio,float m2_edificio,float despesa_cond);

//ESTRUTURA QUE PASSA E RECEBE INSTRUÇÕES:
//QUAL APARTAMENTO TEM O MAIOR NÚMERO DE MORADORES, E IMPRIME OS DADOS DESSE APARTAMENTO.
struct condominio moradores(struct condominio maior_moradores[],int y,int quat_moradores,float valor[],int x);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int cadastro=0,i=0;
    int vet_moradores[3];
    float valorpago[3];
    bool sair=true;

    //CADASTRO RECEBE DA FUNÇÃO A OPÇÃO DO USUÁRIO
    cadastro=menu();


    while(sair)
    {

        switch(cadastro)
        {
        case 1:
            for(i=0; i<3; i++)
            {
                printf("\n\n------------------------------CADASTRO DO %d° APARTAMENTO------------------------------\n",i+1);
                printf("\nInforme o nome do responsável do apartamento: ");
                setbuf(stdin,NULL);
                fflush(stdin);
                gets(vetor[i].nome_morador);

                printf("\nInforme o número do apartamento: ");
                setbuf(stdin,NULL);
                scanf("%i",&vetor[i].num_apart);

                printf("\nInforme a área em m2 do apartamento: ");
                setbuf(stdin,NULL);
                scanf("%f",&vetor[i].area);

                printf("\nInforme o número de moradores do apartamento: ");
                setbuf(stdin,NULL);
                scanf("%i",&vetor[i].num_moradores);

                //VETOR RECEBE DO VETOR DE ESTRUTURA OS DADOS DOS DO NÚMERO DE MORADORES DE CADA
                //APARTAMENTO, PARA SER REORDENADO LOGO ABAIXO NA OPÇÃO 4
                vet_moradores[i]=vetor[i].num_moradores;

            }

            printf("\n\n---------------------------------------------------------------------------------------\n\n");

            //CADASTRO RECEBE DA FUNÇÃO A OPÇÃO DO USUÁRIO
            cadastro=menu();
            break;

        case 2:

            printf("\n\n--------------------INFORMAÇÕES DA ÁREA(EM M2) DO CONDOMÍNIO E EDIFÍCIO-----------------\n");

            float area_comum=0;
            float area_totcondominio=0;
            float area_totedificio=0;

            printf("\nInforme a área de uso comum do condomínio em M2: ");
            setbuf(stdin,NULL);
            scanf("%f",&area_totcondominio);

            printf("\nInforme a área total do edifício em M2: ");
            setbuf(stdin,NULL);
            scanf("%f",&area_totedificio);

            //VARIAVEL (ÁREA_COMUM)RECEBE DA FUNÇÃO O CALCULO DA ÁREA DO CONDOMINIO E ÁREA
            //DO EDIFÍCIO EM PORCENTAGEM DE ÁREA
            area_comum=calculo_area(area_totcondominio,area_totedificio);

            printf("\n%.1f%%: DE ÁREA COMUM DO CONDOMINIO",area_comum);

            printf("\n\n-----------------------------------------------------------------------------------------\n\n");

            //CADASTRO RECEBE DA FUNÇÃO A OPÇÃO DO USUÁRIO
            cadastro=menu();

            break;

        case 3:

            printf("\n\n----------------------INFORMAÇÕES DAS DESPESAS DE CADA APARTAMENTO-----------------------\n");

            float tot_despesa=0;

            printf("\nInforme o valor total das despesas do condomínio: ");
            setbuf(stdin,NULL);
            scanf("%f",&tot_despesa);

            //FUNÇÃO QUE PASSA OS DADOS DAS DESPESAS DE CADA APARTAMENTO
            despesas(vetor,i,valorpago,i,area_totcondominio,area_totedificio,tot_despesa);

            printf("\n\n----------------------------------------------------------------------------------------\n\n");

            //CADASTRO RECEBE DA FUNÇÃO A OPÇÃO DO USUÁRIO
            cadastro=menu();

            break;

        case 4:
            printf("\n--------------------DADOS DO APARTAMENTO COM MAIOR NÚMERO DE MORADORES--------------------\n");

            int aux=0,x=0;
            int maior=0;

            //REORDENANDO VETORES PARA DESCOBRIR O MAIOR NÚMERO DE MORADORES
            for(i=0; i<3; i++)
            {
                for(x=i+1; x<3; x++)
                {
                    if( vet_moradores[i]< vet_moradores[x])
                    {
                        aux= vet_moradores[i];
                        vet_moradores[i]= vet_moradores[x];
                        vet_moradores[x]=aux;
                    }
                }

            }

            //VARIAVEL MAIOR RECEBE DO VETOR O MAIOR NÚMERO DE MORADORES DE UM APARTAMENTO
            maior= vet_moradores[0];

            //FUNÇÃO QUE IMPRIME OS DADOS DO APARTAMENTO COM MAIOR NÚMERO DE MORADORES
            moradores(vetor,i,maior,valorpago,i);

            printf("\n\n----------------------------------------------------------------------------------------\n\n");

            //CADASTRO RECEBE DA FUNÇÃO A OPÇÃO DO USUÁRIO
            cadastro=menu();

            break;

        //OPÇÃO 5: SAI DO PROGRAMA
        case 5:
            sair=false;
            break;

        default:

            printf("\nDigite a opção correta: 1, 2, 3, 4 ou 5 para sair!\n");

            break;
        }
    }

}
//MENU
int menu(void)
{
    int opcao=0;

    while(opcao<1||opcao>5)
    {
        printf("\n\n\t1°- OPÇÃO: CADASTRO ");
        printf("\n\t2°- OPÇÃO: ÁREA TOTAL DO CONDOMÍNIO ");
        printf("\n\t3°- OPÇÃO: DESPESAS DO CONDOMÍNIO ");
        printf("\n\t4°- OPÇÃO: MAIOR NÚMERO DE MORADORES ");
        printf("\n\t5°- OPÇÃO: SAIR DO PROGRAMA ");

        printf("\n\n\tEscolha a opção desejada: ");
        setbuf(stdin,NULL);
        scanf("%i",&opcao);

        system("cls");

        if(opcao<1||opcao>5)
        {
            printf("\n\tDIGITE A OPÇÃO CORRETA: 1, 2, 3, 4 OU 5 PARA SAIR!\n");
        }

    }
    return opcao;
};
//CALCULO DA ÁREA DO CONDOMINIO: TRANSFORMANDO EM PORCENTAGEM
float calculo_area(float area_cond,float area_edf)
{
    float fi=0;

    fi=(area_cond/area_edf)*10;

    return fi;
};
//CALCULO DAS DESPESAS DO CONDOMINIO E O VALOR A SER PAGO POR CADA APARTAMENTO
struct condominio despesas(struct condominio tam_area[],int x,float  valor_pago_mes[],int y, float m2_condominio,float m2_edificio,float despesa_cond)
{
    int i=0;
    float fi = calculo_area(m2_condominio,m2_edificio);

    for(i=0; i<3; i++)
    {
        valor_pago_mes[i]= (tam_area[i].area * fi) + despesa_cond;

        printf("\nDespesa do %i° apartamento R$:%.2f ",i+1,valor_pago_mes[i]);
    }
};

//APARTAMENTO COM O MAIOR NÚMERO DE MORADORES E IMPRIME OS DADOS DO APARTAMENTO
struct condominio moradores(struct condominio maior_moradores[],int y,int quant_moradores,float valor[],int x)
{

    for(y=0; y<3; y++)
    {
        if(maior_moradores[y].num_moradores==quant_moradores)
        {
            printf("\nNome do responsavel: %s\nNúmero do apartamento: %i\nÁrea (em m2): %.0f M2\nNúmero de moradores: %i\nValor pago no Mês R$%.2f\n"
                   ,maior_moradores[y].nome_morador,maior_moradores[y].num_apart,maior_moradores[y].area,maior_moradores[y].num_moradores,valor[y]);
        }
    }

};

