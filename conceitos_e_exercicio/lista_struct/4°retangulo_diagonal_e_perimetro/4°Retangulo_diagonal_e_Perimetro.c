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

    float area=0,diagonal=0,perimetro=0;
    struct retangulo calcula_retan;

    printf("\nDigite o ponto superior esquerdo: ");
    fflush(stdin);
    scanf("%f%f",&calcula_retan.ponto1.x,&calcula_retan.ponto1.y);

    printf("\nDigite o ponto inferior direito: ");
    fflush(stdin);
    scanf("%f%f",&calcula_retan.ponto2.x,&calcula_retan.ponto2.y);

    area = (calcula_retan.ponto1.y - calcula_retan.ponto2.y) * (calcula_retan.ponto2.x - calcula_retan.ponto1.x);
    diagonal = sqrt((pow(calcula_retan.ponto2.x - calcula_retan.ponto1.x, 2) + pow(calcula_retan.ponto2.y - calcula_retan.ponto1.y, 2)));
    perimetro = ((calcula_retan.ponto1.y - calcula_retan.ponto2.y) + (calcula_retan.ponto2.x - calcula_retan.ponto1.x)) * 2;

    printf("Área = %.2f\nComprimento da Diagonal = %.2f\nPerimetro = %.2f\n",area,diagonal,perimetro);

    system("pause");
    return 0;
}
