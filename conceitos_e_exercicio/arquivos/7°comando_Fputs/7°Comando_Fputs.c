#include <stdio.h>
#include <stdlib.h>

/*A função fputs() recebe dois parâmetros de entrada:
•• str: a string (array de caracteres) a ser escrita no arquivo.
•• fp: a variável que está associada ao arquivo onde a string será escrita.
E retorna:
•• A constante EOF (em geral, −1), se houver erro na escrita.
•• Um valor diferente de ZERO, se o texto for escrito com sucesso.*/

int main()
{
    char str[20] = "Hello World!";
    int result;
    FILE *arq;
    arq = fopen("ArqGrav.txt","w");
    if(arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        system("pause");
        exit(1);
    }
    result = fputs(str,arq);
    if(result == EOF)
    {
        printf("Erro na Gravacao\n");
    }

    fclose(arq);

    system("pause");
    return 0;
}
