#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

//g) Escreva um programa que apresente a série de Fibonacci até o décimo quinto termo. A série de
//Fibonacci é formada pela seqüência: 1, 1, 2, 3, 5, 8, 13, 21, 34, ..., etc. Esta série se caracteriza
//pela soma de um termo atual com o seu anterior subseqüente, para que seja formado o próximo
//valor da seqüência. Portanto começando com os números 1, 1 o próximo termo é 1+1=2, o próximo
//é 1+2=3, o próximo é 2+3=5, o próximo 3+5=8, etc.

void main()
{
    setlocale(LC_ALL,"portuguese");

    int anterior=0,i=0;
    int proximo=1;
    int fibonacci=0;

    for(i=1; i<15; i++)
    {
        fibonacci=anterior+proximo;
        proximo=anterior;
        anterior=fibonacci;

        printf("\n\t%d",fibonacci);
    }

    int primo=11;
    int divisivel=0;


        for(int l=0; l<=primo; l++)
        {
            if(l%primo==0&&l!=0||l==1)
            {
                printf("\n\n%d é divisivel por %d\n",primo,l);
            }
        }


}
