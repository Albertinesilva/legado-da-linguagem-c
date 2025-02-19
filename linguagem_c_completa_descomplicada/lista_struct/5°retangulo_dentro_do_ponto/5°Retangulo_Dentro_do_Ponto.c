#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

struct ponto
{
    float x;
    float y;
};

struct retangulo
{
    struct ponto ponto1,ponto2;
};

int main()
{
    setlocale(LC_ALL,"portuguese");

    int area=0,diagonal=0,perimetro=0;
    struct retangulo calcula_retan;
    struct ponto coordenadas;

    printf("\nDigite o ponto superior esquerdo: ");
    fflush(stdin);
    scanf("%f%f",&calcula_retan.ponto1.x,&calcula_retan.ponto1.y);

    printf("\nDigite o ponto inferior direito: ");
    fflush(stdin);
    scanf("%f%f",&calcula_retan.ponto2.x,&calcula_retan.ponto2.y);

    printf("\nDigite a coordenada 1: ");
    fflush(stdin);
    scanf("%f",&coordenadas.x);

    printf("\nDigite a coordenada 2: ");
    fflush(stdin);
    scanf("%f",&coordenadas.y);


   if(coordenadas.x < calcula_retan.ponto1.x || coordenadas.x > calcula_retan.ponto2.x)
   {
     printf("\nPonto fora do Retangulo\n");
   }
   else
   {
       if(coordenadas.y < calcula_retan.ponto1.y || coordenadas.y > calcula_retan.ponto2.y)
       {
           printf("\nPonto fora do Retangulo\n");
       }
       else
       {
           printf("\nO ponto esta dentro do Retangulo\n");
       }
   }

    system("pause");
    return 0;
}
