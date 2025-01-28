#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    char nome1[15],nome2[15];
    int i=0,x=0,tam=0;

    printf("\n\tInforme um nome: ");
    fflush(stdin);
    gets(nome1);

    //Quantidade de caractere
    tam=strlen(nome1);
    printf("\n\tQuantidade de caractere da string %s é: %d\n\n",nome1,tam);

    //Invertendo a string (nome-> "Linguagem C" para C megaugniL)
    for(i=strlen(nome1); i>=0; i--)
    {
        nome2[x]=nome1[i];
        x++;
    }
    nome2[x]='\0';

    printf("\t");
    for(i=0; i<=x; i++)
    {
        printf("%c",nome2[i]);
    }

    printf("\n\n\t------------------------------OUTRA FORMA DE INVERTER STRING------------------------------\n");
    tam=0;
    char nome3;
    char nome4[50];

    printf("\n\n\tInforme outro nome: ");
    gets(nome4);

    tam=strlen(nome4);

    printf("\n\tQuantidade de caractere da string %s é: %d\n",nome4,tam);


    for(i=0; i<tam/2; i++)
    {
        nome3=nome4[i];
        nome4[i]=nome4[tam-1-i];
        nome4[tam-1-i]=nome3;

    }
    tam=0;
    printf("\n\n\tO nome invertido é: %s\n\n",nome4);

    printf("\n\n\t-------------------OUTRA FORMA DE INVERTER STRING COM A FUNÇÃO (STRREV)-------------------\n");

    char nome5[5];

    printf("\n\n\tInforme um nome qualquer para inverter: ");
    fflush(stdin);
    gets(nome5);

    //FUNÇÃO PARA SABER QUANTIDADE DE CARACTERE DA STRING
    tam=strlen(nome5);
    printf("\n\tQuantidade de caractere da string %s é: %d\n",nome5,tam);


    //FUNÇÃO QUE INVERTE STRING
    strrev(nome5);

    printf("\n\n\tNome invetido: %s \n\n",nome5);


printf("\n\n\t*************************OUTRA FORMA DE INVERTER (SO IMPRIME NA TELA)************************\n\n");

char inverter_string[20]="linguagem c";

printf("\t");
for(i=strlen(inverter_string)-1; i>=0; i--)
{
    printf("%c",inverter_string[i]);
}

printf("\n\n\t****************************FORA DO LAÇO DE REPETIÇÃO VOLTA AO NORMAL************************\n\n");
printf("\t%s\n",inverter_string);




}
