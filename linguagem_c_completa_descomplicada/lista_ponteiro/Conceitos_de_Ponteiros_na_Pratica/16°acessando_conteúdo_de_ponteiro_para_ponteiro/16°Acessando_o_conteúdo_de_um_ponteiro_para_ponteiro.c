#include <stdio.h>
#include <stdlib.h>

/*A linguagem C permite que se crie um ponteiro com um n�mero infinito de n�veis
de apontamento. Por�m, na pr�tica, deve-se evitar trabalhar com muitos n�veis de
apontamento. Isso ocorre porque cada novo n�vel de apontamento adicionado aumenta
a complexidade em lidar com aquele ponteiro e, consequentemente, dificulta a
compreens�o dos programas, causando confus�o e facilitando o surgimento de erros.*/

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
