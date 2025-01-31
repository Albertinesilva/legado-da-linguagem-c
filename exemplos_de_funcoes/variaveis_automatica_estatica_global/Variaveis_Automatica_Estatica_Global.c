#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void Local_automatica();
void Local_estatica();
void Global();

int gvariavel_global=2;

void main()
{
    setlocale(LC_ALL,"portuguese");

    printf("\n\tVariavel Global: %d",gvariavel_global);

    printf("\n\t************************************Local Automatica*********************************\n");
    Local_automatica();
    Local_automatica();
    Local_automatica();

    printf("\n\n\t************************************Local Estatica************************************\n");
    Local_estatica();
    Local_estatica();
    Local_estatica();


    printf("\n\n\t**************************************Global*******************************************\n");
    Global();
    //gvariavel_global*=2;
    Global();
    Global();



}

void Local_automatica()
{
    int local_automatica=2;
    local_automatica*=2;

    printf("\n\tLocal Automatica: %d",local_automatica);
}

void Local_estatica()
{
    static int local_estatica=2;
    local_estatica*=2;

    printf("\n\tLocal estatica: %d",local_estatica);
}

void Global()
{
    gvariavel_global*=2;

    printf("\n\tVariavel Global: %d",gvariavel_global);
}

