#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void main ()
{
    setlocale(LC_ALL,"portuguese");

    char string[50],copia[50];
    char asterisco='*';
    int tam=0, i=0;

printf("\n\t***********************************SUBSTITUINDO VOGAIS POR SIMBOLOS*************************\n");
    printf("\n\tInforme uma palavra ou frase: ");
    fflush(stdin);
    gets(string);

    strcpy(copia,string);
    tam=strlen(string);

    for(i=0; i<tam; i++)
    {
        if(string[i]=='a'||string[i]=='e'||string[i]=='i'||string[i]=='o'||string[i]=='u')
        {
            string[i]=asterisco;
        }
    }
    printf("\n\tAs vogais da string: %s, foi subistituida por [*]: %s\n\n",copia,string);


    char nome[30];
    int total=0;

    printf("\n\t**************************************CONTAGEM DE VOGAIS************************************\n");

    printf("\n\tDigite uma palavra ou frase para contar quantas vogais contem: ");
    fflush(stdin);
    gets(nome);

    int tamanho_string=strlen(nome);

    for(i=0; i<tamanho_string; i++)
    {
        if(nome[i]=='a'||nome[i]=='e'||nome[i]=='i'||nome[i]=='o'||nome[i]=='u')
        {
            total++;
        }
    }
    printf("\n\tTotal de vogais da (palavra ou frase) %s é: %i\n",nome,total);



    printf("\n\n\t*******************OUTRA FOMA DE CONTAR VOGAIS: UTILIZANDO A FUNÇÃO (BREAK)******************\n");

    char nome1[30];
    char vogais[11]="aeiouAEIOU";
    int j=0,tot=0;
    int tam2=strlen(vogais);

    printf("\n\n\tInforme uma palavra ou frase para contar as vogais contidas nela: ");
    fflush(stdin);
    gets(nome1);

    int tam1=strlen(nome1);


    for(i=0; i<tam1; i++)
    {
        for(j=0; j<tam2; j++)
        {
            if(nome1[i]==vogais[j])
            {
                tot++;
                break;
            }
        }
    }

    printf("\n\tNúmero de vogais encontrados na palavra %s é: %i\n\n",nome1,tot);
}
