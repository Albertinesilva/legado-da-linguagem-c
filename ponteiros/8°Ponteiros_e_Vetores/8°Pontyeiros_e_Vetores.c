#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



void main()
{
    setlocale(LC_ALL,"portuguese");


    int vetor[3] = {1,2,3};

    //Dessa forma o ponteiro está acessando o 1° índice (Membro) do vetor.
    int *ponteiro = vetor;
    printf("\n%d\n",*ponteiro);

    //Forma correta de acessar o endereço de memória.
    ponteiro=&vetor[0];
    printf("\n%p",ponteiro);

    ponteiro=&vetor[1];
    printf("\n%p",ponteiro);

    ponteiro=&vetor[2];
    printf("\n%p\n\n",ponteiro);

    //Para acessar todos os valores do vetor com ponteiro.
    ponteiro=vetor;
    for(int i=0; i<3; i++)
    {
        printf("%d,",*ponteiro);
        ponteiro++;
    }

    //Alterar um valor do vetor com ponteiro
    ponteiro=vetor;
    *(ponteiro + 1) =10;
    printf("\n\nVetor no índice 2, foi alterado para %d\n",vetor[1]);

}
