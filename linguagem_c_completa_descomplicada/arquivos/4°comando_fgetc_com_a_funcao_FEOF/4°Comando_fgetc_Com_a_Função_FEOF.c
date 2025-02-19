#include <stdio.h>
#include <stdlib.h>

/*Como visto anteriormente, a constante EOF (�End Of File�) indica o fim de um
arquivo. Por�m, quando manipulando dados bin�rios, um valor inteiro igual ao valor
da constante EOF pode ser lido. Nesse caso, se utilizarmos a constante EOF para
verificar se chegamos ao final do arquivo, vamos receber a confirma��o quando, na
verdade, isso ainda n�o aconteceu. Para evitar esse tipo de situa��o, a linguagem C
inclui a fun��o feof(), que determina quando o final de um arquivo foi atingido*/

//Basicamente, a fun��o feof() recebe como par�metro o ponteiro fp, que determina
//o arquivo a ser verificado. Como resultado, a fun��o retorna um valor inteiro igual a
//ZERO se ainda n�o tiver atingido o final do arquivo. Um valor de retorno diferente de
//zero significa que o final do arquivo j� foi atingido.

//Basicamente, a fun��o feof() retorna um valor inteiro diferente de zero se o arquivo
//chegou ao fim; caso contr�rio, retorna ZERO.

int main()
{
    FILE *fp;
    char c;
    fp = fopen("arquivo.txt","r");
    if(fp==NULL)
    {
        printf("Erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }
    while(!feof(fp))
    {
        c = fgetc(fp);
        printf("%c",c);
    }
    fclose(fp);
    printf("\n");

    system("pause");
    return 0;
}
