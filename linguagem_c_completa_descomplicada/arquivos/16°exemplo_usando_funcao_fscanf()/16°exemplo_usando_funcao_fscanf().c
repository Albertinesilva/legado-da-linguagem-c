#include <stdio.h>
#include <stdlib.h>

/*Uma vez escritos os dados, é necessário lê-los do arquivo. Para ler um conjunto de
dados formatados de um arquivo usa-se a função fscanf(), cujo protótipo é:

int fscanf(FILE *fp, “tipos de entrada”, lista de variáveis)

A função fscanf() recebe três parâmetros de entrada:

•• fp: o ponteiro para o arquivo em que se deseja trabalhar.
•• “tipos de entrada”: conjunto de caracteres que especifica o formato dos dados
a serem lidos.
•• lista de variáveis: conjunto de nomes de variáveis separados por vírgula, em que
cada nome de variável é precedido pelo operador &.
E retorna:

•• Em caso de sucesso, a função retorna o número de itens lidos com sucesso. Esse
número pode ser menor do que o número de itens esperado, indicando que
houve erro parcial de leitura.
•• A constante EOF, indicando que nenhum item foi lido com sucesso.


Perceba que a função fscanf() funciona de maneira semelhante à função scanf(). A
diferença é que, em vez de ler os dados do teclado, a função fscanf() direciona a leitura
dos dados para o arquivo especificado.*/

//Se a intenção do programador é velocidade ou tamanho do arquivo, deve-se utilizar as
//funções fwrite() e fread() em vez de fprintf() e fscanf(), respectivamente.

int main()
{
    FILE *arq;
    char texto[20], nome[20];
    int i;
    float a;
    int result;
    arq = fopen("ArqGrav.txt","r");
    if(arq == NULL)
    {
        printf("Problemas na ABERTURA do arquivo\n");
        system("pause");
        exit(1);
    }
    fscanf(arq,"%s%s",texto,nome);
    printf("%s %s\n",texto,nome);
    fscanf(arq,"%s %d",texto,&i);
    printf("%s %d\n",texto,i);
    fscanf(arq,"%s%f",texto,&a);
    printf("%s %f\n",texto,a);
    fclose(arq);

    system("pause");
    return 0;
}
