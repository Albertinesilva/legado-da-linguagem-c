#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Outra operação bastante comum é saber onde estamos dentro de um arquivo. Para
realizar essa tarefa, usamos a função ftell(), cujo protótipo é:
long int ftell(FILE *fp)
Basicamente, a função ftell() recebe como parâmetro o ponteiro fp, que determina
o arquivo a ser manipulado. Como resultado, a função ftell() retorna a posição atual
dentro do fluxo de dados do arquivo:
•• Para arquivos binários, o valor retornado indica o número de bytes lidos a partir
do início do arquivo.
•• Para arquivos texto, não existe garantia de que o valor retornado seja o número
exato de bytes lidos a partir do início do arquivo.
•• Se ocorrer um erro, o valor −1 no formato long é retornado.*/

int main()
{
    FILE *arq;
    arq = fopen("arquivo.bin","rb");
    if(arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    int tamanho;
    fseek(arq,0,SEEK_END);
    tamanho = ftell(arq);
    fclose(arq);

    printf("\n");
    printf("Tamanho do arquivo em bytes: %d:",tamanho);

    system("pause");
    return 0;
}
