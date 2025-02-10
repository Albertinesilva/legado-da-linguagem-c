#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{

    char nome[20];
    int idade;
    char endereco[30];
} dados;

int main()
{
    setlocale(LC_ALL,"portuguese");

    dados pessoa;

    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(pessoa.nome,20,stdin);

    printf("\nDigite o endereço: ");
    fflush(stdin);
    fgets(pessoa.endereco,30,stdin);

    printf("\nDigite a idade: ");
    fflush(stdin);
    scanf("%d",&pessoa.idade);

    printf("\nNome: %sIdade: %d\nEndereço: %s\n",pessoa.nome,pessoa.idade,pessoa.endereco);

    system("pause");
    return 0;
}
