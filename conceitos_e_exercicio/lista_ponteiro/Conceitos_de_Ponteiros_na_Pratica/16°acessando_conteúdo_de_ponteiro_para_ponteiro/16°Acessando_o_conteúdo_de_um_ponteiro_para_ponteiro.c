#include <stdio.h>
#include <stdlib.h>

/*A linguagem C permite que se crie um ponteiro com um número infinito de níveis
de apontamento. Porém, na prática, deve-se evitar trabalhar com muitos níveis de
apontamento. Isso ocorre porque cada novo nível de apontamento adicionado aumenta
a complexidade em lidar com aquele ponteiro e, consequentemente, dificulta a
compreensão dos programas, causando confusão e facilitando o surgimento de erros.*/

int main()
{
    char letra='a';
    char *ptrChar = &letra;
    char **ptrPtrChar = &ptrChar;
    char ***ptrPtr = &ptrPtrChar;
    printf("Conteudo em *ptrChar: %c\n",*ptrChar);
    printf("Conteudo em **ptrPtrChar: %c\n",**ptrPtrChar);
    printf("Conteudo em ***ptrPtr: %c\n",***ptrPtr);

    system("pause");
    return 0;
}
