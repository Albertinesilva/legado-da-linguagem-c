#include <stdio.h>
#include <stdlib.h>

/*Uma vez escritos os dados, � necess�rio l�-los do arquivo. Para ler um conjunto de
dados formatados de um arquivo usa-se a fun��o fscanf(), cujo prot�tipo �:

int fscanf(FILE *fp, �tipos de entrada�, lista de vari�veis)

A fun��o fscanf() recebe tr�s par�metros de entrada:

�� fp: o ponteiro para o arquivo em que se deseja trabalhar.
�� �tipos de entrada�: conjunto de caracteres que especifica o formato dos dados
a serem lidos.
�� lista de vari�veis: conjunto de nomes de vari�veis separados por v�rgula, em que
cada nome de vari�vel � precedido pelo operador &.
E retorna:

�� Em caso de sucesso, a fun��o retorna o n�mero de itens lidos com sucesso. Esse
n�mero pode ser menor do que o n�mero de itens esperado, indicando que
houve erro parcial de leitura.
�� A constante EOF, indicando que nenhum item foi lido com sucesso.


Perceba que a fun��o fscanf() funciona de maneira semelhante � fun��o scanf(). A
diferen�a � que, em vez de ler os dados do teclado, a fun��o fscanf() direciona a leitura
dos dados para o arquivo especificado.*/

//Se a inten��o do programador � velocidade ou tamanho do arquivo, deve-se utilizar as
//fun��es fwrite() e fread() em vez de fprintf() e fscanf(), respectivamente.

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
