#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main (){

setlocale(LC_ALL,"portuguese");

//Lendo números inteiros e imprimindo na tela
int num;
float m;

printf("Digite um número inteiro: ");
scanf("%i",&num);

printf("Digite um número real: ");
scanf("%f",&m);

printf("Você acabou de digitar os valores %d e %.1f. Obrigado!\n",num,m);

//*****************************************************************************************************

//Lendo e imprimindo caractere de uma letra.
char letra;

printf("Digite uma letra:");
//Tem que colocar um espaço no parametro de formatação EX: ("_%C",&LETRA); para poder ler.
scanf(" %c",&letra);

printf("Você digitou a letra \"%c\"\n",letra);

//********************************************************************************************************

//Sempre utilizar o comando FFLUSH (STDIN);
char a;
char b;

printf("Digite uma letra: ");
fflush(stdin);
scanf("%c",&a);

printf("Digite outra letra: ");
fflush(stdin);
scanf("%c",&b);

printf("Você digitou as letras \"%c\" é \"%c\"\n",a,b);
//****************************************************************************************************


//Para usar caractere o correto e utilizar: FFLUSH(STDIN) EM SEGUIDA VARIAVEL = GETCHAR();
char l;
char s;

printf("Digite so uma letra: ");
fflush(stdin);
l = getchar();

printf("Digite mais outra letra: ");
fflush(stdin);
s = getchar();

printf("Você digitou as letras \"%c\" é \"%c\"\n",l,s);


//Para usar caractere de cadeia o correto e utilizar: FFLUSH(STDIN) EM SEGUIDA GETS(VARIAVEL);
char nome [30];
char ender[40];

printf("Digite seu nome: ");
fflush(stdin);
gets(nome);

printf("Digite seu endereço: ");
fflush(stdin);
gets(ender);

printf("Meu nome é \"%s\" eu moro no endereço \"%s\"",nome,ender);

system("pause");

}



