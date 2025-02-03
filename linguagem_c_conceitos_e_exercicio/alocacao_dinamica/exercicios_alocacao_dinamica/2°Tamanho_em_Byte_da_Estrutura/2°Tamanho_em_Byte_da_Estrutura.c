#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    int matricula;
    char nome[15];
    int notas [3];
};

void main()
{
    printf("Tamanho da Estrutura = %d\n",sizeof(struct aluno));
}

