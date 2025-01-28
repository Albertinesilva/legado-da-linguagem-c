#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main ()
{
    setlocale(LC_ALL,"portuguese");

    char string[50];
    int a=0,b=0,c=0,d=0,e=0;
    int tam=0, i=0;

    printf("\n\n\t--------------------OCORRÊNCIAS DAS 5 PRIMEIRAS LETRAS DO ALFABETO--------------------\n\n");
    printf("\n\tInforme uma string: ");
    fflush(stdin);
    gets(string);

    tam=strlen(string);

    for(i=0; i<tam; i++)
    {
        if(string[i]=='A'||string[i]=='a')
        {
           a++;
        }
        else
        {
            if(string[i]=='B'|| string[i]=='b')
            {
                b++;
            }
            else
            {
                if(string[i]=='C'||string[i]=='c')
                {
                    c++;
                }
                else
                {
                    if(string[i]=='D'||string[i]=='d')
                    {
                        d++;
                    }
                    else
                    {
                        if(string[i]=='E'||string[i]=='e')
                        {
                            e++;
                        }
                    }
                }
            }
        }
    }
    printf("\n\n\t--------------------NÚMERO DE OCORRÊNCIAS DAS LETRAS(A,B,C,D,E)-------------------------\n\n");
    printf("\n\n\tLetra (A,a): %d\n\tLetra (B,b): %d\n\tLetra (C,c): %d\n\tLetra (D,d): %d\n\tLetra (E,e): %d\n\n",a,b,c,d,e);
}
