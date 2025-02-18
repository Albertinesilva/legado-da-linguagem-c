#include <stdio.h>
#include <stdlib.h>

/*Uma vez concluída a etapa de gravação de dados com a função fwrite(), é necessário
agora lê-los do arquivo. Para ler de um arquivo um blocos de bytes usa-se a função
fread(), cujo protótipo é:

int fread(void *buffer, int nro_de_bytes, int count, FILE *fp)

A função fread() recebe quatro parâmetros de entrada:

•• buffer: um ponteiro genérico para a região de memória que armazenará os dados
que serão lidos do arquivo.
•• nro_de_bytes: tamanho, em bytes, de cada unidade de dado a ser lida.
•• count: total de unidades de dados que devem ser lidas.
•• fp: o ponteiro para o arquivo que se deseja trabalhar.

Note que, como na função fwrite(), temos dois valores inteiros: nro_de_bytes e count.
Isso significa que o número total de bytes lidos do arquivo será: nro_de_bytes * count.

Como resultado, a função fread() retorna um valor inteiro que representa o número
total de unidades de dados efetivamente lidas com sucesso. Esse número pode ser
menor do que o número de itens esperado (count), indicando que houve erro parcial
de leitura.

O valor do retorno da função fread() será igual ao valor de count, a menos que ocorra
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

    //lê 5 posições inteiras do arquivos
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
