#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
int compara_datas(int dia,int mes,int ano,int dia2,int mes2,int ano2);

void main()
{
    setlocale(LC_ALL,"portuguese");

    /* char x[10];
     float y=0;
     int cont=0;
     bool correto=true;



    while(correto)
    {

       printf("digite: ");
       setbuf(stdin,NULL);
       gets(x);


       if(strcmp(x,",")!=0)
       {
            y=strtof(x,NULL);
       }
      if(y>0)
      {
          correto=false;
      }

    }
    printf("%s",x);
    float a[10]= {5,4},b[10]= {10},t[2];
    int i=0,y=0,l=0;
    float total=0,z=0;


    for(i=0; i<2; i++)
    {
        t[i]=a[i]+b[i];
        total=total+t[i];
        printf("\nVetor A %.1f\nVetor B %.1f",a[i],b[i]);
    }
    printf("\n\n");
    printf("\n\nTotal: %.1f",total);

    srand(time(NULL));

    int *p;
    int valor1,valor2;

    valor1=5;
    p=&valor1;
    valor2=*p;

    printf("P aponta para %p\n",p);
    printf("P contem o valor %d\n",*p);
    printf("O endereço de P %p\n",&p);*/


    /*int tam=0,i;
    char nome3;
    char nome4[50];

    printf("\n\n\tInforme outro nome: ");
    gets(nome4);

    tam=strlen(nome4);

    printf("\n\tQuantidade de caractere da string %s é: %d\n",nome4,tam);


    for(i=0; i<tam/2; i++)
    {
        nome3=nome4[i];
        nome4[i]=nome4[tam-1-i];
        nome4[tam-1-i]=nome3;
    }
    tam=0;
    printf("\n\n\tO nome invertido é: %s\n\n",nome4);


    char letra;
    char minuscula[2];
    bool verdadeiro=true;

    while(verdadeiro)
    {
        printf("\nInforme uma letra MAIUSCULA: ");
        fflush(stdin);
        letra=getchar();
        getchar();

        if(letra < 'A' || letra > 'Z')
        {
            printf("\nLetra informada é Minuscula\n");
        }
        else
        {
            verdadeiro=false;
            minuscula[0]=letra;
        }

    }
    strlwr(minuscula);
    printf("\nLetra MINUSCULA %s",minuscula);*/




        setlocale(LC_ALL,"portuguese");

        printf("Este programa foi criado com o objetivo de calcular a determinante de uma matriz em\n Ordem 2x2\n Ordem 3x3\n Ordem 4x4\n\n");
        printf("--Para calcular a determinante de uma matriz-- \n--O numero de linhas da da matriz 1 \ndeve ser igual ao numero de colunas da matriz 2--\n\n");


        int n = 0;
        double **a = 0;
        int i = 0, j = 0, k = 0;
        double factor = 0;
        double temp = 0;
        int count = 0;

        printf("Qual a ordem da matriz que deseja calcular? => ");
        scanf("%d", &n);

        a = (double **) calloc(n, sizeof(double *));
        for(i = 0; i < n; i++)
        {
            a[i] = (double *) calloc(n, sizeof(double));
        }

        printf("\n\nEntre com o conteudo da matriz\n\n");
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("A[%d ; %d] => ", i+1, j+1);
                scanf("%lf", &a[i][j]);
            }
        }


        printf("\nMatriz digitada:\n");
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("%8.3f ", a[i][j]);
            }
            printf("\n");
        }

        // faz a transformação em um triangulo...
        for(i = 0; i < n - 1; i++)
        {
            if(a[i][i] == 0)
            {
                for(k = i; k < n; k++)
                {
                    if(a[k][i] != 0)
                    {
                        for(j = 0; j < n; j++)
                        {
                            temp = a[i][j];
                            a[i][j] = a[k][j];
                            a[k][j] = temp;
                        }
                        k = n;
                    }
                }
                count++;
            }

            if(a[i][i] != 0)
            {
                for(k = i + 1; k < n; k++)
                {
                    factor = -1.0 * a[k][i] /  a[i][i];
                    for(j = i; j < n; j++)
                    {
                        a[k][j] = a[k][j] + (factor * a[i][j]);
                    }
                }
            }
        }

        temp = 1.0;
        // Calcula o determinante
        for(i = 0; i < n; i++)
            temp *= a[i][i];

        printf("\nDeterminante:\n");
        if(count % 2 == 0)
            printf("%8.3f \n", temp);
        else
            printf("%8.3f \n", -1.0 * temp);



}























