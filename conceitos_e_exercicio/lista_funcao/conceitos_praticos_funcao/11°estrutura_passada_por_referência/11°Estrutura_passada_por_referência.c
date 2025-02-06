#include <stdio.h>
#include <stdlib.h>

///Passagem de uma estrutura por referência
//Vimos anteriormente que, para passar um parâmetro por referência, usa-se o operador
//“*” na frente do nome do parâmetro durante a declaração da função.
//Isso tambémé válido para uma estrutura, mas alguns cuidados devem ser tomados ao acessar seus
//campos dentro da função. Para acessar o valor de um campo de uma estrutura passada

//por referência, devemos seguir este conjunto de passos:
//1. Utilizar o operador “*” na frente do nome da variável que representa a estrutura.
//2. Colocar o operador “*” e o nome da variável entre parênteses ().
//3. Por fim, acessar o campo da estrutura utilizando o operador ponto “.”.


//O operador seta “->” também pode ser usado para acessar o valor do campo de uma
//união ou uma enumeração passada por referência para a função.
///void atribui(struct ponto *p){
///p->x = 10; O operador seta  pode subistituir (*p).x
///p->y = 20;
///}


struct ponto {
int x, y;
};

void atribui(struct ponto *p){
(*p).x = 10;
(*p).y = 20;
}
int main(){

struct ponto p1;
atribui(&p1);

printf("x = %d\n",p1.x);
printf("y = %d\n",p1.y);

system("pause");
return 0;
}
