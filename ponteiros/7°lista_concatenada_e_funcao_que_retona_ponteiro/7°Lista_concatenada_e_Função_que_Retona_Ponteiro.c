#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct lista {
    int valor;
    struct lista *proximo;
};

struct lista *procurar_Valor(struct lista *plista, int valor){

    while(plista != (struct lista *)0){

        if(plista->valor == valor){

            return(plista);
        }
        else{

            plista = plista->proximo;
        }

    }
     return NULL;

};

void main(){

    setlocale(LC_ALL,"portuguese");

    struct lista *procurar_Valor(struct lista *plista, int valor);

    struct lista m1,m2,m3;
    struct lista *resultado, *gancho = &m1;

    m1.valor = 5;
    m2.valor = 10;
    m3.valor = 20;

    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = NULL;

    int num;
    int x;
    printf("\nDigite valor da pesquisa: ");
    scanf("%d",&num);

    resultado = procurar_Valor(gancho, num);

    if(resultado == NULL){

        printf("\nValor não encontrado!\n");
    }
    else{

        printf("\nValor %i encontrado!\n",resultado->valor);
    }

}
