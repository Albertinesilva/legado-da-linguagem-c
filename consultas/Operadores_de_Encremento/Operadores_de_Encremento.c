#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main (){
setlocale(LC_ALL,"portuguese");

//FAZENDO O INCREMENTO: 8 + 1 = 9
int n = 8;
n ++;
printf("Resultado do incremento é %i: \n",n);

//FAZENDO O DECREMENTO: 8 - 1 = 7
int m =8;
m --;
printf("\nResultado do decremento é %i: \n",m);


//A DEPENDER DA POSIÇÃO DO SINAL O RESULTADO SO VAI SE EXIBIDO NA PROXIMA LINHA:
int z = 1;
printf("\nEssa linha não faz o incremento de Z por conta do sinal Z++: %i",z++);
printf("\nSo faz o incremento de Z nessa linha %i \n",z);


//A POSIÇÃO DO SIMBOLO DE (+,-,*,/,%) FAZ TODA DIFERENÇA DENTRO DA OPERAÇÃO
int b = 10;
printf("\nO resultado do incremento de b é %i: \n",++ b);


//DESSA FORMA O X INCREMENTA 6 E O Y INCREMENTA 5 + 3 = 8: POR CONTA DO SINAL DE X ( X++ )
int x = 5;
int y = 3 + x++;
printf("\nOs valores de x e y são %i é %i \n",x,y);

//DESSA FORMA O X1 INCREMENTA 6 E O Y INCREMENTA 6 + 3 = 9 POR CONTA DO SINAL DE X ( ++X )
int A = 5;
int D = 3 + ++A;
printf("\n O valor de (A) é %i o valor de (D) é %i\n",A,D);







}
