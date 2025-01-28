#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void qualmes(int mes);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int num=0;

    printf("\n\tInforme o número corresponde ao mês do ano: ");
    scanf("%i",&num);

    qualmes(num);

}
void qualmes(int mes)
{
    if(mes==1)
    {
        printf("\n\tJANEIRO\n");
    }
    else
    {
        if(mes==2)
        {
            printf("\n\tFEVERREIRO\n");
        }
        else
        {
            if(mes==3)
            {
                printf("\n\tMARÇO\n");
            }
            else
            {
                if(mes==4)
                {
                    printf("\n\tABRIL\n");
                }
                else
                {
                    if(mes==5)
                    {
                        printf("\n\tMAIO\n");
                    }
                    else
                    {
                        if(mes==6)
                        {
                            printf("\n\tJUNHO\n");
                        }
                        else
                        {
                            if(mes==7)
                            {
                                printf("\n\tJULHO\n");
                            }
                            else
                            {
                                if(mes==8)
                                {
                                    printf("\n\tAGOSTO\n");
                                }
                                else
                                {
                                    if(mes==9)
                                    {
                                        printf("\n\tSETEMBRO\n");
                                    }
                                    else
                                    {
                                        if(mes==10)
                                        {
                                            printf("\n\tOUTUBRO\n");
                                        }
                                        else
                                        {
                                            if(mes==11)
                                            {
                                                printf("\n\tNOVEMBRO\n");
                                            }
                                            else
                                            {
                                                if(mes==12)
                                                {
                                                    printf("\n\tDEZEMBRO\n");
                                                }
                                                else
                                                {
                                                    printf("\n\tNÚMERO INVALIDO\n");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
