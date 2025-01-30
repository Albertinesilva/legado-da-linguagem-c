#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/**************************************
*   Programa criado por Albert para   *
*o curso de Linguagem C do estudonauta*
*                                     *
***************************************/

void main (){

setlocale(LC_ALL,"portuguese"); // Muda a zona codificação de caractere printf

printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\\a\t=\tBeep\n");
printf("\\n\t=\tNova linha\n");
printf("\\t\t=\tTabulação\n");
printf("\\\t=\tBarra\n");
printf("%%\t=\tPorcetagem\n");
printf("\?\t=\tInterrogação\n");
}
