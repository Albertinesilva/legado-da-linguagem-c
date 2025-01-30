#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main(){

setlocale(LC_ALL,"portuguese");

srand (time (NULL)); //COMANDO NECESSARIO PARA GERAR UM NÚMERO ALEATORIO. OBS (-> TEM QUE SER MAIUSCULO (NULL))

// int n = rand() GERA NÚMEROS GRANDES ( QUALQUER VALOR!)
int palpite,n = rand() % 5 + 1; // VARIAVEL = RAND () % 5 + 1 GERA UM NÚMERO ALEATORIO ENTRE 1 E 5.



printf("***SERÁ QUE VOCÊ ACERTA?***\n");

printf("\n========== Vou pensar em um número entre 1 e 5. Tente advinha! ==========\n");

printf("\nQual é o seu palpite? ");
scanf("%d",&palpite);

printf("\nEu pensei no número %d e você pensou no %d.\n",n,palpite);



}
