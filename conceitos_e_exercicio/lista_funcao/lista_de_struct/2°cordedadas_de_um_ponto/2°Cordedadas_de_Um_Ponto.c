#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct
{
    int y;
    int x;
} carteziano;

int main()
{
    carteziano ponto;
    int distancia_ate_Origem=0;

    printf("Digite a coordenada X: ");
    scanf("%d",&ponto.x);

    printf("Digite a coordenada Y: ");
    scanf("%d",&ponto.y);

    distancia_ate_Origem = sqrt(pow((ponto.x - 0), 2) + pow((ponto.y - 0), 2));

    printf("A distancia ate a origem = %d\n",distancia_ate_Origem);

    system("pause");
    return 0;
}
