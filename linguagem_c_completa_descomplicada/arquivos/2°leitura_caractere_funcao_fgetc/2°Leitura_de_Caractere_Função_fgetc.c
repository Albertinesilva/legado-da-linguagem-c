#include <stdio.h>
#include <stdlib.h>

//Da mesma maneira que é possível gravar um único caractere em um arquivo, também
//é possível fazer a sua leitura. A função que corresponde à leitura de caracteres é a
//função fgetc(), cujo protótipo é:

//int fgetc(FILE *fp);

//A função fgetc() recebe como parâmetro de entrada apenas a variável que está associada
//ao arquivo de onde o caractere será lido. Essa função retorna:
//•• A constante EOF (em geral, −1), se houver erro na leitura.
//•• O caractere lido do arquivo, na forma de seu valor inteiro, se ele foi lido com sucesso.

//Cada chamada da função fgetc() lê um único caractere do arquivo especificado.


int main()
{
    FILE *arq;
    char c;
    arq = fopen("arquivo.txt","r");
    if(arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }
    int i;
    for(i = 0; i < 5; i++)
    {
        c = fgetc(arq);
        printf("%c",c);
    }
    fclose(arq);
    printf("\n");

    system("pause");
    return 0;

/*No exemplo anterior, a função fgetc() é utilizada para ler cinco caracteres de um
arquivo. Note que a função fgetc() sempre retorna o caractere atualmente apontado
pelo indicador de posição interna do arquivo especificado.
A cada operação de leitura, o indicador de posição interna do arquivo é avançado em
um caractere para apontar para o próximo caractere a ser lido.*/
}
