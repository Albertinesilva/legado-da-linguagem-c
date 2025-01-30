#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){

char produto[20];
float valor_total,preco,desconto;

setlocale(LC_ALL,"portuguese");

printf("Produto: ");
fflush(stdin);
gets(produto);

system("pause");
printf("Preço do %s R$: ",produto);
scanf("%f",&preco);
printf("Desconto: (%%) ");
scanf("%f",&desconto);

valor_total = preco - (preco * desconto)/100;
valor_total*= 2;

printf("\nO produto %s custava R$%.2f ",produto,preco);
printf("Porém, com %.2f%% de desconto, passa a custar R$: %.2f. ",desconto,valor_total);

}
