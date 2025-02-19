#include <stdio.h>
#include <stdlib.h>

/*Iniciemos pela etapa de gravação. Para escrever em um arquivo um blocos de bytes
usa-se a função fwrite(), cujo protótipo é:

int fwrite(void *buffer, int nro_de_bytes, int count, FILE *fp)

A função fwrite() recebe quatro parâmetros de entrada:

•• buffer: um ponteiro genérico para a região de memória que contém os dados
que serão gravados no arquivo.
•• nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser gravada.
•• count: total de unidades de dados que devem ser gravadas.
•• fp: o ponteiro para o arquivo em que se deseja trabalhar.

Note que temos dois valores inteiros: nro_de_bytes e count. Isso significa que o
número total de bytes gravados no arquivo será: nro_de_bytes * count.

Como resultado, a função fwrite() retorna um valor inteiro que representa o número
total de unidades de dados gravadas com sucesso. Esse número pode ser menor do
que o número de itens esperado (count), indicando que houve erro parcial de escrita.

O valor do retorno da função fwrite() será igual ao valor de count, a menos que ocorra
algum erro na gravação dos dados.*/

int main()
{
    FILE *arq;
    arq = fopen("ArqGrav.txt","wb");
    if(arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        system("pause");
        exit(1);
    }
    int total_gravado, v[5] = {1,2,3,4,5};

    //grava todo o array no arquivo (5 posições)
    total_gravado = fwrite(v,sizeof(int),5,arq);
    if(total_gravado != 5)
    {
        printf("Erro na escrita do arquivo!");
        system("pause");
        exit(1);
    }
    fclose(arq);
    system("pause");
    return 0;
}
