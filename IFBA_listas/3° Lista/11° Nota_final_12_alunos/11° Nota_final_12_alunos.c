#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int contador,aprovado,reprovado;
    int nota;
    char nome[20];

    contador=0;
    nota=0;
    aprovado=0;
    reprovado=0;

    do
    {
        printf("\nQual o seu NOME? ");
        fflush(stdin);
        gets(nome);

        printf("\nIforme sua nota, %s! ",nome);
        scanf("%d",&nota);

        if(nota >= 7)
        {
            aprovado+=1;
        }
        else
        {
            if(nota < 7)
            {
                reprovado+=1;
            }
        }

        contador+=1;
    }
    while(contador!=12);

    printf("\n\n%d ALUNOS FORAM APROVADOS!\n",aprovado);
    printf("\n%d ALUNOS FORAM REPROVADOS!\n",reprovado);
}
