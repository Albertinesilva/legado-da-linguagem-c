#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main()
{
    setlocale(LC_ALL,"portuguese");

    char a[22];
    char b[22];
    char a1[22],b1[22];
    int x=0,y=0;

    printf("\nInforme o Vetor A caractere: ");
    fflush(stdin);
    gets(a);
    printf("\nInforme o Vetor B caractere: ");
    fflush(stdin);
    gets(b);

      printf("\nVetor A: %s",a);
    printf("\nVetor B: %s",b);

    printf("\n---------------------------------------------------Vetor A-----------------------------------------------\n\n");

    int tam =strlen(b);

    for(int i=strlen(b); i>=0; i--)
    {
        a1[x]=b[i];
        x++;
    }
    a1[x]='\0';

    for(int i=0; i<=x; i++)
    {
        printf("%c",a1[i]);
    }
    printf("\n-----------------------------------------------------Vetor B------------------------------------------\n\n");

    for(int i=strlen(a); i>=0; i--)
    {
        b1[y]=a[i];
        y++;
    }
    b1[y]='\0';

    for(int i=0; i<=y; i++)
    {
        printf("%c",b1[i]);
    }
    printf("\n\n");

    printf("\n\n-----------------------------------VETOR A E B INVERTIDO COM A FUNÇÃO------------------------------\n\n");


    strcpy(a,b);
    strrev(a);

    strcpy(b,a);
    strrev(b);


    printf("Vetor A = %s",a);
    printf("\nVetor B = %s",b);


    return 0;
}
