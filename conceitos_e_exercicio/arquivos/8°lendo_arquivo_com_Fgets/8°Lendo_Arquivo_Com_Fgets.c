#include <stdio.h>
#include <stdlib.h>

/*Da mesma maneira como é possível gravar uma string em um arquivo, também é
possível fazer a sua leitura. A função utilizada para realizar essa tarefa é a função fgets(),
cujo protótipo é:

char *fgets(char *str, int tamanho, FILE *fp);

A função fgets() recebe três parâmetros de entrada:
•• str: a string onde os caracteres lidos serão armazenados.
•• tamanho: o limite máximo de caracteres a serem lidos.
•• fp: a variável que está associada ao arquivo de onde a string será lida.
E retorna:
•• NULL: no caso de erro ou fim do arquivo.
•• o ponteiro para o primeiro caractere da string recuperada em str.*/

int main()
{

    char str[20];
    char *result;
    FILE *arq;

    arq = fopen("ArqGrav.txt","r");
    if(arq == NULL)
    {
        printf("Problemas na ABERTURA do arquivo\n");
        system("pause");
        exit(1);
    }
    result = fgets(str,13,arq);
    if(result == NULL)
    {
        printf("Erro na leitura\n");
    }
    else
    {
        printf("%s",str);
    }
    fclose(arq);
    printf("\n");

    system("pause");
    return 0;
}
