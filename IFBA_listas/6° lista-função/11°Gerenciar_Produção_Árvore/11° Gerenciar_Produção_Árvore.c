#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>

float altura_ideal_paravenda(int quant,float milimetro, float centimetro, float metros);



void main()
{
    setlocale(LC_ALL,"portuguese");

    int quant_arvores=0,i=0,num_identi=0;
    float ideal_milime=0,ideal_centime=0, ideal_metros=0;


    printf("\n\tInforme a quantidade de árvores frutiferas: ");
    scanf("%d",&quant_arvores);

    printf("\n\t-------------------------INFORME A ALTURA IDEAL DA ÁRVORE-------------------------\n");
    printf("\n\tMILÍMETRO: ");
    scanf("%f",&ideal_milime);

    printf("\n\tCENTÍMETRO: ");
    scanf("%f",&ideal_centime);

    printf("\n\tMETROS: ");
    scanf("%f",&ideal_metros);

    altura_ideal_paravenda(quant_arvores,ideal_milime,ideal_centime, ideal_metros);

}

float altura_ideal_paravenda(int quant,float milimetros, float centimetros, float metros)
{
    int i=0,num_identi=0;
    float m=0,c=0,met=0;
    int altura_ideal=0;


    for(i=0; i<quant; i++)
    {

        printf("\n\tInforme o número de identificação da %d° árvore: ",i+1);
        scanf("%d",&num_identi);

        printf("\n\tInforme a altura atual da %d° árvore\n",i+1);
        printf("\n\tMILÍMETRO: ");
        scanf("%f",&m);

        printf("\n\tCENTÍMETRO: ");
        scanf("%f",&c);

        printf("\n\tMETROS: ");
        scanf("%f",&met);

        if(m!=milimetros && c!=centimetros && metros!=met)
        {
            altura_ideal=0;
        }
        else
        {
            if(m==milimetros && c==centimetros && metros==met)
            {
                altura_ideal=1;
            }
            else
            {
                if(m==milimetros && c==centimetros)
                {
                    altura_ideal=2;
                }
                else
                {
                    if(m==milimetros && metros==met)
                    {
                        altura_ideal=3;
                    }
                    else
                    {
                        if((metros==met) && (c==centimetros))
                        {
                            altura_ideal=4;
                        }
                        else
                        {
                            if(m==milimetros)
                            {
                                altura_ideal=5;
                            }
                            else
                            {
                                if(c==centimetros)
                                {
                                    altura_ideal=6;
                                }
                                else
                                {
                                    if(met==metros)
                                    {
                                        altura_ideal=7;
                                    }

                                }

                            }
                        }
                    }
                }
            }
        }

        if(altura_ideal==1)
        {
            printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  MÍLIMETROS, na altura ideal para venda!",i+1,num_identi,m);
            printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  CENTIMETROS, na altura ideal para venda!",i+1,num_identi,c);
            printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  METROS, na altura ideal para venda!\n",i+1,num_identi,met);
        }
        else
        {
            if(altura_ideal==2)
            {
                printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  MÍLIMETROS, na altura ideal para venda!",i+1,num_identi,m);
                printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  CENTIMETROS, na altura ideal para venda!\n",i+1,num_identi,c);
            }
            else
            {
                if(altura_ideal==3)
                {
                    printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  MÍLIMETROS, na altura ideal para venda!",i+1,num_identi,m);
                    printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  METROS, na altura ideal para venda!\n",i+1,num_identi,met);
                }
                else
                {
                    if(altura_ideal==4)
                    {
                        printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  CENTIMETROS, na altura ideal para venda!",i+1,num_identi,c);
                        printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  METROS, na altura ideal para venda!\n",i+1,num_identi,met);
                    }
                    else
                    {
                        if(altura_ideal==5)
                        {
                            printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  MÍLIMETROS, na altura ideal para venda!\n",i+1,num_identi,m);

                        }
                        else
                        {
                            if(altura_ideal==6)
                            {

                                printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  CENTIMETROS, na altura ideal para venda!\n",i+1,num_identi,c);
                            }
                            else
                            {
                                if(altura_ideal==7)
                                {
                                    printf("\n\tA %d° árvore com a identificação: %d esta com %.2f  METROS, na altura ideal para venda!\n",i+1,num_identi,met);
                                }

                                else
                                {
                                    if(altura_ideal==0)
                                    {
                                        printf("\n\tA altura da árvore frutifera não esta na altura para venda\n\n\tMILIMETROS %.2f\n\tCENTIMETROS %.2f\n\tMETROS %.2f\n",m,c,met);
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









