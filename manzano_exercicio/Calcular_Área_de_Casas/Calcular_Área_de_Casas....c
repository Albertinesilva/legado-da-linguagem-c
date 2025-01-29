
//k) Elaborar um programa que possibilite calcular a área total de uma residência (sala, cozinha,
//banheiro, quartos, área de serviço, quintal, garagem, etc.). O programa deve solicitar a entrada do
//nome, a largura e o comprimento de um determinado cômodo. Em seguida, deve apresentar a área
//do cômodo lido e também uma mensagem solicitando do usuário a confirmação de continuar
//calculando novos cômodos. Caso o usuário responda “NAO”, o programa deve apresentar o valor
//total acumulado da área residencial.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include  <stdbool.h>
#include <ctype.h>
#include <conio.h>

int menu();

float sala();

void main()
{
    setlocale(LC_ALL,"portuguese");

    int opcao=0;
    float x[10];
    float comodo_sala[10];
    float cozinha[10];
    char continuar;
    int y=0,i=0,j=0;
    float total=0;

    while(continuar!='n')
    {
        opcao=menu();


        if(opcao==1)
        {
            comodo_sala[i]=sala();
            printf("\n\tComodo da Sala(Área) %.2f",comodo_sala[i]);
            total=total+comodo_sala[i];
            i++;
        }
        else
        {
            if(opcao==2)
            {
                cozinha[y]=sala();
                printf("Comodo da cozinha(Área) %.2f",cozinha[y]);
                total=total+cozinha[y];
                y++;

            }
        }

        printf("\n\nPara continuar digite [S],para encerrar digite [N] ");
        fflush(stdin);
        continuar=getchar();
    }

    printf("Total: %f",total);

}

int menu()
{
    printf("\n********************************Escolha o comodo para calcular a área*****************************\n");
    int opcao=0;

    do

    {
        printf("\n\t1° Sala\n");
        printf("\t2° Cozinha\n");
        printf("\t3° Banheiro\n");
        printf("\t4° Quartos\n");
        printf("\t5° Área de Serviço\n");
        printf("\t6° Quintal\n");
        printf("\t7° Garagem\n");
        printf("\t8° Outros\n");
        printf("\t9° Sair\n");
        printf("\tEntrada: ");
        scanf("%d",&opcao);
        setbuf(stdin,NULL);

    }
    while(opcao>9||opcao<1);

}

float sala()
{
    char lado[10];
    char frente[10];
    float x=0;
    float y=0;
    bool correto=true,frent=true;
    int i=0,c=0;

    do
    {
        printf("\nInforme quantos metros tem o lado da casa: ");
        fflush(stdin);
        gets(lado);

        if(isdigit(lado[i])!=0)
        {
            i++;
            correto=false;
        }
    }
    while(correto);
    correto=true;

    x=strtof(lado,NULL);

    do
    {
        printf("Informe quantos metros tem a frente da casa: ");
        fflush(stdin);
        gets(frente);

        if(isdigit(frente[c])!=0)
        {
            c++;
            correto=false;
        }
    }
    while(correto);

    y=strtof(frente,NULL);

    float area_sala=y*x;

    return area_sala;

}



