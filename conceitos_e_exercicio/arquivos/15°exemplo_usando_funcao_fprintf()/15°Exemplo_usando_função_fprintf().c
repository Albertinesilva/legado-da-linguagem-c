#include <stdlib.h>
#include <stdio.h>

/*A função fprintf() recebe três parâmetros de entrada:

•• fp: o ponteiro para o arquivo em que se deseja trabalhar.
•• tipos de saída: conjunto de caracteres que especifica o formato dos dados a
serem escritos e/ou o texto a ser escrito.
•• lista de variáveis: conjunto de nomes de variáveis, separados por vírgula, que
serão escritos.
E retorna:
•• Em caso de sucesso, o número total de caracteres escritos no arquivo é retornado.
•• Em caso de erro, um número negativo é retornado.

O exemplo da Figura 12.11 apresenta um exemplo de uso da função fprintf().
Perceba que a função fprintf() funciona de maneira semelhante à função printf(). A
diferença é que, em vez de escrever na tela, a função fprintf() direciona os dados para
o arquivo especificado.*/

int main()
{
    FILE *arq;
    char nome[20] = "Ricardo";
    int i = 30;
    float a = 1.74;
    int result;
    arq = fopen("ArqGrav.txt","w");
    if(arq == NULL)
    {
        printf("Problemas na ABERTURA do arquivo\n");
        system("pause");
        exit(1);
    }
    result = fprintf(arq,"Nome: %s\nIdade: %d\nAltura: %f\n",nome,i,a);
    if(result < 0)
        printf("Erro na escrita\n");

    fclose(arq);
    system("pause");
    return 0;
}
