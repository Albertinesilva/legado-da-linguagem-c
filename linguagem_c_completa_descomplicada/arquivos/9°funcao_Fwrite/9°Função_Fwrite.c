#include <stdio.h>
#include <stdlib.h>

/*Iniciemos pela etapa de grava��o. Para escrever em um arquivo um blocos de bytes
usa-se a fun��o fwrite(), cujo prot�tipo �:

int fwrite(void *buffer, int nro_de_bytes, int count, FILE *fp)

A fun��o fwrite() recebe quatro par�metros de entrada:

�� buffer: um ponteiro gen�rico para a regi�o de mem�ria que cont�m os dados
que ser�o gravados no arquivo.
�� nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser gravada.
�� count: total de unidades de dados que devem ser gravadas.
�� fp: o ponteiro para o arquivo em que se deseja trabalhar.

Note que temos dois valores inteiros: nro_de_bytes e count. Isso significa que o
n�mero total de bytes gravados no arquivo ser�: nro_de_bytes * count.

Como resultado, a fun��o fwrite() retorna um valor inteiro que representa o n�mero
total de unidades de dados gravadas com sucesso. Esse n�mero pode ser menor do
que o n�mero de itens esperado (count), indicando que houve erro parcial de escrita.

O valor do retorno da fun��o fwrite() ser� igual ao valor de count, a menos que ocorra
algum erro na grava��o dos dados.*/

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

    //grava todo o array no arquivo (5 posi��es)
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
