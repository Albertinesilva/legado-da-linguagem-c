#include <stdio.h>
#include <stdlib.h>

/*Da mesma maneira como � poss�vel gravar uma string em um arquivo, tamb�m �
poss�vel fazer a sua leitura. A fun��o utilizada para realizar essa tarefa � a fun��o fgets(),
cujo prot�tipo �:

char *fgets(char *str, int tamanho, FILE *fp);

A fun��o fgets() recebe tr�s par�metros de entrada:
�� str: a string onde os caracteres lidos ser�o armazenados.
�� tamanho: o limite m�ximo de caracteres a serem lidos.
�� fp: a vari�vel que est� associada ao arquivo de onde a string ser� lida.
E retorna:
�� NULL: no caso de erro ou fim do arquivo.
�� o ponteiro para o primeiro caractere da string recuperada em str.*/

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
