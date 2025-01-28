#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>//Para usar a funão (ISDIGIT)

void main()
{
    setlocale(LC_ALL,"portuguese");

    int i=0;
    char cpf[20];
    char candidato[20];
    char comando[20];
    bool digitou_cpf_com_numero=true;


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

        if(isdigit(cpf[i])!=0)
        {
            i++;
            digitou_cpf_com_numero=false;
            strcpy(candidato,cpf);
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

    printf("\n\tCPF: %s\n",candidato);


}
