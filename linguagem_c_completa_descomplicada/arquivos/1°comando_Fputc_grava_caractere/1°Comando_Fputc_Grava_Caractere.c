#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//As funções mais básicas e fáceis de se trabalhar em um arquivo são as responsáveis
//pela escrita e leitura de um único caractere. Para se escrever um caractere em um arquivo
//usamos a função fputc(), cujo protótipo é:

//int fputc(int c,FILE *fp);

//A função fputc() recebe dois parâmetros de entrada:

//•• c: o caractere a ser escrito no arquivo. Note que o caractere é passado como seu valor inteiro.
//•• fp: a variável que está associada ao arquivo onde o caractere será escrito.
//E-book gerado especialmente para warlles carlos costa machado - wccmachado@gmail.com Arquivos 249

//E retorna:
//•• A constante EOF (em geral, −1), se houver erro na escrita.
//•• O próprio caractere, se ele foi escrito com sucesso.

//Cada chamada da função fputc() grava um único caractere c no arquivo especificado.


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
    fflush(stdin);
    gets(string);

    //Grava a string, caractere a caractere
    for(i = 0; i < strlen(string); i++)
    {
        fputc(string[i], arq);
    }
    fclose(arq);

    system("pause");

    return 0;

    /*No exemplo anterior, a função fputc() é utilizada para escrever um caractere na posição
    atual do arquivo, como assinalado pelo indicador de posição interna do arquivo.
    Em seguida, esse indicador de posição interna é avançado em um caractere de modo a
    ficar pronto para a escrita do próximo caractere.*/
}
