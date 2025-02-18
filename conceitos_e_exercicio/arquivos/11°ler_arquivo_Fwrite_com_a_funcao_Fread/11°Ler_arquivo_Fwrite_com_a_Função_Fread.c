#include <stdio.h>
#include <stdlib.h>

/*Uma vez conclu�da a etapa de grava��o de dados com a fun��o fwrite(), � necess�rio
agora l�-los do arquivo. Para ler de um arquivo um blocos de bytes usa-se a fun��o
fread(), cujo prot�tipo �:

int fread(void *buffer, int nro_de_bytes, int count, FILE *fp)

A fun��o fread() recebe quatro par�metros de entrada:

�� buffer: um ponteiro gen�rico para a regi�o de mem�ria que armazenar� os dados
que ser�o lidos do arquivo.
�� nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser lida.
�� count: total de unidades de dados que devem ser lidas.
�� fp: o ponteiro para o arquivo que se deseja trabalhar.

Note que, como na fun��o fwrite(), temos dois valores inteiros: nro_de_bytes e count.
Isso significa que o n�mero total de bytes lidos do arquivo ser�: nro_de_bytes * count.

Como resultado, a fun��o fread() retorna um valor inteiro que representa o n�mero
total de unidades de dados efetivamente lidas com sucesso. Esse n�mero pode ser
menor do que o n�mero de itens esperado (count), indicando que houve erro parcial
de leitura.

O valor do retorno da fun��o fread() ser� igual ao valor de count, a menos que ocorra
algum erro na leitura dos dados.*/

int main()
{
    FILE *arq;
    arq = fopen("ArqGrav.txt","rb");
    if(arq == NULL)
    {
        printf("Problemas na ABERTURA do arquivo\n");
        system("pause");
        exit(1);
    }
    int i,total_lido, v[5];

    //l� 5 posi��es inteiras do arquivos
    total_lido = fread(v,sizeof(int),5,arq);
    if(total_lido != 5)
    {
        printf("Erro na leitura do arquivo!");
        system("pause");
        exit(1);
    }
    else
    {
        for(i = 0; i < 5; i++)
            printf("v[%d] = %d\n",i,v[i]);
    }
    fclose(arq);
    system("pause");
    return 0;
}
