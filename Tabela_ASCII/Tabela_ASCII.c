#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



void main()
{
    setlocale(LC_ALL,"portuguese");

    int i=0;
    char c;

    printf("\n\tAperte uma tecla em seu teclado: ");
    c=getchar();

    printf("\n\tA tecla pressionada: %c\n",c);
    printf("\n\tO codigo da tecla: %d\n\n",c);


    //imprime a tabela ASCII
    for(i=31; i<255; i++)
    {
        printf("\n");
        printf("%d = %c\t\t",i,i);
    }



     //imprime a tabela ASCII
    /*int a = 0;

     printf("IMPRIMINDO TABELA ASCII");

     for ( a = 1; a < 255; a++ )
     {
         printf("Decimal: %i\tOctal: %o\tHexadecimal: %x\t\t", a, a, a);

         if (a > 32)
             printf("Caractere: %c",a);

         printf("\n");
     }

     //Obs: %i imprime iteiro, %o imprime octal, %x imprime Hexadecimal, %c imprime caractere char*/

    system("pause");
}
