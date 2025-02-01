#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>


int main(void)
{

    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int x =10;
    double y =20.50;
    char z='a';

    int *ponteiro_x=&x;
    double *ponteiro_y=&y;
    char *ponteiro_z=&z;

    //Acessa o endereço e o valor de cada Ponteiro.
    printf("\nEndereço X = %d - Valor X = %d",ponteiro_x,*ponteiro_x);
    printf("\nEndereço y = %d - Valor y = %.2f",ponteiro_y,*ponteiro_y);
    printf("\nEndereço Z = %d - Valor Z = %c\n",ponteiro_z,*ponteiro_z);

    //Soma entre dois ponteiros: O ponteiro_x está com o endereço da variável (X),cujo o valor é 10.
    //O ponteiro_y está com o endereço da variavel (y),cujo o valor é 20.50;
    double soma = *ponteiro_x + *ponteiro_y;
    printf("\n\nResultado da soma entre dois ponteiros = %.2f\n",soma);

    //Esta apontando para o endereço da variavel (J).

    int j=25;
    int *resultado;

    printf("\nEndereço da memória de J = %d",&j);

    //Informando manualmente o endereço de memória da variavel (J).
    resultado = 6356688;
    printf("\nValor do ponteiro RESULTADO = %d\n",*resultado);

    return 0;
}
