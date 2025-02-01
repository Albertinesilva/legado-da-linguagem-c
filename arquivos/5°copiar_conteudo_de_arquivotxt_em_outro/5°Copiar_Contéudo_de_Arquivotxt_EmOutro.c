#include <stdio.h>
#include <stdlib.h>

void copiarConteudo(FILE *file1, FILE *file2);

void main()
{
    FILE *file1;
    file1 = fopen("string.txt", "r");

    if(file1 == NULL)
    {
        printf("Não foi possivel abrir o arquivo!");
        exit(0);
    }

    FILE *file2 = fopen("teste.txt", "w");

    copiarConteudo(file1,file2);

    fclose(file1);
    fclose(file2);
}
void copiarConteudo(FILE *file1, FILE *file2)
{
   char leitor[1000];

   while(fgets(leitor,1000,file1) != NULL)
   {
       fputs(leitor,file2);
   }
}
