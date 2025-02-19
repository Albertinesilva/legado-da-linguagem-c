
//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//para utilizar o getch()
#include <ctype.h>//para utilizar o isdigit()
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void main()
{
    setlocale(LC_ALL,"portuguese");

    char digitado[50];//armazena o que foi digitado pelo usu�rio
    char c;//armazena cada caractere digitado pelo usu�rio
    int i=0;//vari�vel para controlar o �ndice do vetor de caracteres
    float numero=0;//vari�vel para armazenar a convers�o do que foi digitado pelo usu�rio
    bool correto=true;



    while(correto)
    {
        printf ("\nInforme um numero: ");
        do
        {
            c=getch();//captura o caractere digitado pelo usu�rio
            if (isdigit(c)!=0||c==',')//se for um n�mero
            {
                digitado[i] = c;//armazena no vetor de caracteres
                i++;//incrementa o �ndice do vetor de caracteres
                printf ("%c", c);//exibe o caractere digitado
            }
            else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres j� digitados
            {
                digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
                i--;//o �ndice do vetor de caracteres � decrementado
                printf("\b \b");//o caractere digitado � apagado da tela
            }
            numero = strtof(digitado,NULL);//a vari�vel numero recebe o valor do vetor de caracteres convertido para float
        }
        while(c!=13); //o loop vai ser executado at� que a tecla pressionada seja o ENTER (c�digo 13 na tabela ASCII)

        if(numero>0)
        {
            correto=false;
        }
    }


    printf ("\n\nO numero digitado foi %f\n\n", numero);

}
