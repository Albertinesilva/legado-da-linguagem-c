#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    char string1[]="não";
    char string2[10];
    int p1=0,p2=0;

    printf("\n\tstring2 : ");
    fflush(stdin);
    gets(string2);

    int c=strcmp(string1,"não");
    printf("\n\tString1 comparando NÃO com %s = %d\n",string1,c);

    int x=strcmp(string2,"sim");
    printf("\n\tString2 comparando SIM com %s = %d\n",string2,x);


    if(strcmp(string2,"sim")==0||(string2,"SIM")==0||(string2,"Sim")==0)
    {
        p2=1;
        printf("\n\tstring2: %s\n",string2);
        printf("\n\tTeste P2: %d\n\n",p2);
    }
    else
    {
        if(strcmp(string1,"não")==0||(string1,"NÃO")==0||(string1,"Não")==0)
        {
            p1=2;
            printf("\n\tstring1: %s\n",string1);
            printf("\n\tTeste P1: %d\n\n",p1);

        }

        else
        {
            printf("\n\tErrado!");
        }
    }


}
