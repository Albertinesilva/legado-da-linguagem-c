#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void main(){
setlocale(LC_ALL,"portuguese");

float distancia_percorrida, combustivel_gasto,consumo_medio;

printf("Informe a distancia total percorrida, pelo automóvel! ");
fflush(stdin);
scanf("%f",&distancia_percorrida);

printf("Informe o total de combustível gasto! ");
fflush(stdin);
scanf("%f",&combustivel_gasto);


consumo_medio = distancia_percorrida / combustivel_gasto;

printf("\nO consumo médio do automovel foi: %.2f\n",consumo_medio);

}
