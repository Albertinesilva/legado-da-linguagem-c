#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct
{
    float y1,y2;
    float x1,x2;
} carteziano;

int main()
{
    carteziano ponto;
    float distancia_ate_Origem=0;

    printf("Digite a coordenada X1: ");
    scanf("%f",&ponto.x1);

    printf("Digite a coordenada Y1: ");
    scanf("%f",&ponto.y1);

    printf("Digite a coordenada X2: ");
    scanf("%f",&ponto.x2);

    printf("Digite a coordenada Y2: ");
    scanf("%f",&ponto.y2);

    distancia_ate_Origem = sqrt(pow((ponto.x1 - ponto.x2), 2) + pow((ponto.y1 - ponto.y2), 2));

    printf("A distancia entre os dois pontos = %.2f\n",distancia_ate_Origem);

    system("pause");
    return 0;
}
