#include <stdio.h>
#include <stdlib.h>

void main()
{
   FILE *f = fopen("arquivo5.txt","r");
   if(f == NULL)
   {
       printf("Erro na abertura!\n");
       system("pause");
       exit(1);
   }

   char texto[20],nome[20];
   int idade;
   float alt;

   fscanf(f,"%s %s",texto,nome);
   printf("%s %s\n",texto,nome);
   fscanf(f,"%s %d",texto,&idade);
   printf("%s %d\n",texto,idade);
   fscanf(f,"%s %f",texto,&alt);
   printf("%s %f",texto,alt);
   fclose(f);


}
