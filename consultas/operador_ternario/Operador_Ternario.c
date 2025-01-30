#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main (){
// OPERADOR TERNARIO

setlocale(LC_ALL,"portuguese");

//A LETRA (a e menor que b) ENTÃO (c) VAI RECEBER 2:
    int a = 4, b = 8;
    int c = (a > b) ? 1 : 2;
    printf("O resultado é %i \n",c);

//A LETRA (a1 e maior que b1) ENTÃO (c1) VAI RECEBER 14:
    int a1 = 14, b1 = 8;
    int c1 = (a1 > b1) ? 1 : 2;
    printf("\nO resultado é %d \n",c1);

//A LETRA (a2 e maior que b2) ENTÃO (c2) VAI RECEBER b2 * 2 = 16:
    int a2 = 14, b2 = 8;
    int c2 = (a2 > b2) ? b2 * 2 : a + 5;
    printf("\nO resultado é %i \n",c2);

//MOSTRA A ESTRIG "APROVADO" OU "REPROVADO" SE (media > 7);
    float media = 5.5;
    printf("\nSua situação é %s \n",(media >= 7) ? "Aprovado" : "Reprovado");

//EXEMPLO CLASSICO DE MAIOR OU MENOR NÚMERO:
    int n1,n2;

    printf("\nDigite um número: ");
    scanf("%d",&n1);
    printf("\nDigite outro número: ");
    scanf("%i",&n2);

    int maior = (n1 > n2) ? n1 : n2;
    printf("\nEntre %d é %d, o maior foi %i\n",n1,n2,maior);
}
