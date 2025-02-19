#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Basicamente, a função fflush() recebe como parâmetro o ponteiro fp, que determina
o arquivo a ser manipulado. Como resultado, a função fflush() retorna:
•• O valor 0, se a operação foi realizada com sucesso.
•• A constante EOF (em geral, −1), se houver algum erro.
O comportamento da função fflush() depende do modo como o arquivo foi aberto.
•• Se o arquivo apontado por fp foi aberto para escrita, os dados contidos no “buffer
de saída” são gravados no arquivo.
•• Se o arquivo apontado por fp foi aberto para leitura, o comportamento depende
da implementação da biblioteca. Em algumas implementações, os dados
contidos no “buffer de entrada” são apagados, mas esse não é um comportamento-
padrão.
•• Se fp for um ponteiro nulo (fp = NULL), todos os arquivos abertos são liberados.*/

int main()
{
    FILE *arq;
    char string[100];
    int i;
    arq = fopen("arquivo.txt","w");
    if(arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    printf("Entre com a string a ser gravada no arquivo: ");
    gets(string);
    for(i = 0; i < strlen(string); i++)
    {
        fputc(string[i], arq);
    }

    fflush(arq);
    fclose(arq);

    system("pause");
    return 0;
}
