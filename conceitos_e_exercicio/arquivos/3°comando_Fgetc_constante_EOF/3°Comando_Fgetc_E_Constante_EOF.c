#include <stdio.h>
#include <stdlib.h>

//Nesse caso, precisamos que a função retorne algo indicando que o arquivo acabou.
//Porém, todos os 256 caracteres da tabela ASCII são “válidos” em um arquivo. Para
//evitar esse tipo de situação, a função fgetc() não devolve um valor do tipo char, mas
//do tipo int. O conjunto de valores do tipo char está contido dentro do conjunto de
//valores do tipo int. Se o arquivo tiver acabado, a função fgetc() devolve um valor inteiro
//que não possa ser confundido com um valor do tipo char.

//Quando atinge o final de um arquivo, a função fgetc() devolve a constante EOF (End Of
//File), que está definida na biblioteca stdio.h. Em muitos computadores, o valor de EOF
//é definido como −1.

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
    while((c = fgetc(arq)) != EOF)
    {
        printf("%c",c);
    }

    fclose(arq);

    printf("\n");
    system("pause");
    return 0;

//Nesse exemplo, a função fgetc() é utilizada juntamente com a constante EOF para
//ler não apenas alguns caracteres, mas para continuar lendo caracteres enquanto não
//chegamos ao final do arquivo.
}
