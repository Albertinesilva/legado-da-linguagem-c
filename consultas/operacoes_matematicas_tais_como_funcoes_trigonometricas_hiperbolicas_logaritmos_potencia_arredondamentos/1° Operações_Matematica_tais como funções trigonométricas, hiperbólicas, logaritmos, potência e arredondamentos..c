#include <stdio.h>
#include <conio.h>
#include <math.h>//necess�ria para usar as fun��es matem�ticas


/*Fun��o	Descri��o do comando
floor( )	arredonda para baixo
ceil( )	    arredonda para cima
sqrt( )	    Calcula raiz quadrada
pow(vari�vel, expoente)	potencia��o
sin( )	    seno
cos( )	    cosseno
tan( )	    Tangente
log( )	    logaritmo natural
log10( )	logaritmo base 10
No programa abaixo, temos um resumo das fun��es mais utilizadas e os coment�rios.*/



int main (void)
{
    double x = 9.75;

    double arredonda_pbaixo = 0.0;
    double arredonda_pcima = 0.0;
    double raiz_quadrada = 0.0;
    double potencia = 0;

    double seno = 0;
    double cosseno = 0;
    double tangente = 0;

    double logaritmo_natural = 0;
    double logaritmo_xbase10 = 0;

    printf("\n********* Utilizando a biblioteca math.h ***********\n\n");

    printf("\nFuncoes de arredondamento\n\n");
    printf("Valor original de x = %f\n",x);

    arredonda_pbaixo = floor(x);
    printf("Valor aproximado para baixo %f \n", arredonda_pbaixo );

    arredonda_pcima = ceil(x);
    printf("Valor aproximado para cima %f \n", arredonda_pcima);

    printf("\n----------------------------------------------------\n\n");

    printf("\nFuncoes de raiz e potenciacao \n\n");
    printf("Valor original de x = %lf\n",x);
    raiz_quadrada = sqrt(x);
    printf("Valor da raiz quadrada %f \n",raiz_quadrada);

    x = ceil(x); //arredondando o x para cima, x passa a valer 10

    potencia = pow(x,2); //elevando o valor de x ao quadrado
    printf("Valor de %.2lf ao quadrado %.2f \n",x,potencia);

    printf("\n----------------------------------------------------\n\n");

    printf("\nFuncoes trigonometricas\n\n");

    x = 0; //atribuindo zero em x para fazer os c�lculos trigonom�tricos

    seno = sin(x);
    printf("Valor de seno de %.2f = %.2f \n",x,seno);

    cosseno = cos(x);
    printf("Valor de cosseno de %.2f = %.2f \n",x,cosseno);

    tangente = tan(x);
    printf("Valor de tangente de %.2f = %.2f \n\n",x,tangente);

    printf("\n----------------------------------------------------\n\n");

    printf("\nFuncoes logaritmicas\n\n");

    x = 2.718282;
    logaritmo_natural = log(x);
    printf("Logaritmo natural de x %.2f = %.2f \n",x,logaritmo_natural);

    x = 10;
    logaritmo_xbase10 = log10(x);
    printf("Logaritmo de x na base 10 %.2f = %.2f \n",x,logaritmo_xbase10);
    printf("\n----------------------------------------------------\n\n");

    getch();
    return(0);
}
