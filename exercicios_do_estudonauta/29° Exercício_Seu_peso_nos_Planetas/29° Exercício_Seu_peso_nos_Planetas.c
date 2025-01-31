#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>


void main(){
setlocale(LC_ALL,"portuguese");

float peso;
int opcao;

printf("Seu peso na Terra (Kg) = ");
fflush(stdin);
scanf("%f",&peso);

printf("\n\tESCOLHA UM PLANETA\n");
printf("    =========================\n");
printf("    1°      Mercúrio\n");
printf("    2°      Vênus\n");
printf("    3°      Marte\n");
printf("    4°      Júpiter\n");
printf("    5°      Saturno\n");
printf("    6°      Urano\n");
printf("    =========================\n");

printf("    Digite uma opção => ");
fflush(stdin);
scanf("%d",&opcao);

switch (opcao){

case 1:
    printf("\n--------------------------------------------\n");
    printf("No planeta MERCÚRIO, seu peso seria %.2f Kg\n",peso*0.37);
    printf("--------------------------------------------\n");
    break;

case 2:
    printf("\n--------------------------------------------\n");
    printf("No planeta VÊNUS, seu peso seria %.2f Kg\n",peso*0.88);
    printf("--------------------------------------------\n");
    break;

case 3:
    printf("\n--------------------------------------------\n");
    printf("No planeta MARTE, seu peso seria %.2f Kg\n",peso*0.38);
    printf("--------------------------------------------\n");
    break;

case 4:
    printf("\n--------------------------------------------\n");
    printf("No planeta JÚPITER, seu peso seria %.2f Kg\n",peso*2.64);
    printf("--------------------------------------------\n");
    break;

case 5:
    printf("\n--------------------------------------------\n");
    printf("No planeta SATURNO, seu peso seria %.2f Kg\n",peso*1.15);
    printf("--------------------------------------------\n");
    break;

case 6:
    printf("\n---------------------------------------------\n");
    printf("No planeta URANO, seu peso seria %.2f Kg\n",peso*1.17);
    printf("--------------------------------------------\n");
    break;

default:
    printf("\n----------------------------------------------------------------------\n");
    printf("Seu peso não pode ser calculado para outros planetas. Tente novamente.\n");
    printf("----------------------------------------------------------------------\n");
    break;




}

printf("\nVOLTE SEMPRE!\n");
}
