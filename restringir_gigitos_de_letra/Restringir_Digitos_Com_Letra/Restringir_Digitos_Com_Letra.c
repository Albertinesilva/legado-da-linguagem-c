
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

    char digitado[50];//armazena o que foi digitado pelo usuário
    char c;//armazena cada caractere digitado pelo usuário
    int i=0;//variável para controlar o índice do vetor de caracteres
    float numero=0;//variável para armazenar a conversão do que foi digitado pelo usuário
    bool correto=true;



    while(correto)
    {
        printf ("\nInforme um numero: ");
        do
        {
            c=getch();//captura o caractere digitado pelo usuário
            if (isdigit(c)!=0||c==',')//se for um número
            {
                digitado[i] = c;//armazena no vetor de caracteres
                i++;//incrementa o índice do vetor de caracteres
                printf ("%c", c);//exibe o caractere digitado
            }
            else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
            {
                digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
                i--;//o índice do vetor de caracteres é decrementado
                printf("\b \b");//o caractere digitado é apagado da tela
            }
            numero = strtof(digitado,NULL);//a variável numero recebe o valor do vetor de caracteres convertido para float
        }
        while(c!=13); //o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

        if(numero>0)
        {
            correto=false;
        }
    }


    printf ("\n\nO numero digitado foi %f\n\n", numero);

}
