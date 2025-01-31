#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int idade;
    char nome[20];

}aluno;

aluno retorno();

void main()
{
    setlocale(LC_ALL,"portuguese");

    aluno x=retorno();

    printf("\n\t%s tem %d anos\n",x.nome,x.idade);

}
aluno retorno()
{
    aluno a;

    printf("\n\tNome: ");
    setbuf(stdin,NULL);
    gets(a.nome);

    printf("\n\tIdade: ");
    setbuf(stdin,NULL);
    scanf("%d",&a.idade);

    return a;
}
