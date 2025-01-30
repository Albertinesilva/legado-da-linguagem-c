#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    int num;

    printf("Digite um número que você quer que escreva por extenso: ");
    fflush(stdin);
    scanf("%d",&num);

//COMEÇA COM O COMANDO (SWITCH + VARIAVEL)
    switch (num)
    {

//TODOS OS (CASE) É ACOMPANHADO DA OPÇÃO E DOIS PONTOS. OBS: NÃO E PONTO E VIRGULA
    case 1:
        printf("UM\n");
        break;

    case 2:
        printf("DOIS\n");
        break;

    case 3:
        printf("TRÊS\n");
        break;

    case 4:
        printf("QUATRO\n");
        break;

//NÃO E OBRIGATORIO USAR O (BREAK) NO COMANDO (DEFAULT).
    default:
        printf("ERRO!\n");
        break;

    }
    printf("\nAcabou!\n");
}
