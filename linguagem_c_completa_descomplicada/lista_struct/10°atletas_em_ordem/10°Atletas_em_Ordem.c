#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char esporte[50];
    int altura,idade;

} dados;


int main()
{
    setlocale(LC_ALL,"portuguese");

   dados atleta[5];
   dados aux;


   for(int i=0; i<5; i++)
   {
       printf("\n%d° Atleta",i+1);
       printf("\nDigite o seu nome: ");
       fflush(stdin);
       gets(atleta[i].nome);

       printf("\nQual o seu esporte? ");
       fflush(stdin);
       gets(atleta[i].esporte);

       printf("\nDigite a sua altura: ");
       fflush(stdin);
       scanf("%d",&atleta[i].altura);

       printf("\nDigite a sua idade: ");
       fflush(stdin);
       scanf("%d",&atleta[i].idade);

       aux=atleta[0];
   }

   for(int i=0; i<5; i++)
   {
     for(int y=i+1; y<5; y++)
     {
       if(atleta[i].idade < atleta[y].idade)
       {
           aux.idade=atleta[i].idade;
           atleta[i].idade=atleta[y].idade;
           atleta[y].idade=aux.idade;

           aux.altura=atleta[i].altura;
           atleta[i].altura=atleta[y].altura;
           atleta[y].altura=aux.altura;

           strcpy(aux.nome,atleta[i].nome);
           strcpy(atleta[i].nome,atleta[y].nome);
           strcpy(atleta[y].nome,aux.nome);

           strcpy(aux.esporte,atleta[i].esporte);
           strcpy(atleta[i].esporte,atleta[y].esporte);
           strcpy(atleta[y].esporte,aux.esporte);
       }
     }
   }

    for(int i=0; i<5; i++)
   {
       printf("\n%d° Atleta",i+1);
       printf("\nNome: %s",atleta[i].nome);
       printf("\nEsporte %s ",atleta[i].esporte);
       printf("\nAltura: %d",atleta[i].altura);
       printf("\nIdade: %d\n",atleta[i].idade);

   }

    system("pause");
    return 0;
}
