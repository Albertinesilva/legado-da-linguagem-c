#include <stdio.h>
#include <stdlib.h>

///Passagem de uma estrutura por refer�ncia
//Vimos anteriormente que, para passar um par�metro por refer�ncia, usa-se o operador
//�*� na frente do nome do par�metro durante a declara��o da fun��o.
//Isso tamb�m� v�lido para uma estrutura, mas alguns cuidados devem ser tomados ao acessar seus
//campos dentro da fun��o. Para acessar o valor de um campo de uma estrutura passada

//por refer�ncia, devemos seguir este conjunto de passos:
//1. Utilizar o operador �*� na frente do nome da vari�vel que representa a estrutura.
//2. Colocar o operador �*� e o nome da vari�vel entre par�nteses ().
//3. Por fim, acessar o campo da estrutura utilizando o operador ponto �.�.


//O operador seta �->� tamb�m pode ser usado para acessar o valor do campo de uma
//uni�o ou uma enumera��o passada por refer�ncia para a fun��o.
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
