#include <stdlib.h>
#include <stdio.h>

/*A fun��o fprintf() recebe tr�s par�metros de entrada:

�� fp: o ponteiro para o arquivo em que se deseja trabalhar.
�� tipos de sa�da: conjunto de caracteres que especifica o formato dos dados a
serem escritos e/ou o texto a ser escrito.
�� lista de vari�veis: conjunto de nomes de vari�veis, separados por v�rgula, que
ser�o escritos.
E retorna:
�� Em caso de sucesso, o n�mero total de caracteres escritos no arquivo � retornado.
�� Em caso de erro, um n�mero negativo � retornado.

O exemplo da Figura 12.11 apresenta um exemplo de uso da fun��o fprintf().
Perceba que a fun��o fprintf() funciona de maneira semelhante � fun��o printf(). A
diferen�a � que, em vez de escrever na tela, a fun��o fprintf() direciona os dados para
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
