#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale(LC_ALL,"portuguese");
float valor_total,distancia;

printf("\n======== TABELA DE PREÇOS =========\n");
printf(" Viagens até 200km\tR$0.50/km\n");
printf(" Viagem acima de 200km\tR$0.35/km\n");
printf("-----------------------------------\n");

printf("Distância total da viagem, em Km: ");
fflush(stdin);
scanf("%f",&distancia);

if(distancia <= 200){
    valor_total = distancia*0.50;
    printf("Uma viagem de %.1f Km vai custar R$0,50/Km\n",distancia);
    printf("Valor Total: R$%.2f\n",valor_total);
}
else{
    printf("Uma viagem de %i Km vai custar R$0,35/Km\n",distancia);
    printf("Valor Total: R$%.2f\n",distancia*0.35);
}

}
