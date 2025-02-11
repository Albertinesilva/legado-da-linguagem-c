#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    char nome[20];
    char esporte[15];
    int altura,idade;

} dados;


int main()
{
    setlocale(LC_ALL,"portuguese");

   dados atleta[5];
   int alto=0,velho=0;
   int indice_velho=0,indice_altura=0;

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

       alto=atleta[0].altura;
       velho=atleta[0].idade;
   }

   for(int y=0; y<5; y++)
   {
       if(atleta[y].altura > alto)
       {
           indice_altura=y;
           alto=atleta[y].altura;
       }
       if(atleta[y].idade > velho)
       {
           indice_velho=y;
           velho=atleta[y].idade;
       }
   }

   printf("\nNome do atleta mais alto: %s\nNome do atleta mais velho: %s\n",atleta[indice_altura].nome,atleta[indice_velho].nome);
    system("pause");
    return 0;
}
