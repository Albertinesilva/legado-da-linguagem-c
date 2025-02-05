#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void main()
{
    setlocale(LC_ALL,"portuguese");

    float media,nota,soma;
    int nota_acima5,contador,quant_alunos;
    bool b=true;
    char continuar;

    media=0;
    nota=0;
    soma=0;
    nota_acima5=0;
    contador=0;
    quant_alunos=0;

    printf("\nQuantidade de alunos: ");
    scanf("%d",&quant_alunos);

    while (contador!=quant_alunos)
    {
        contador+=1;
        printf("\ninforme a nota do aluno: ");
        scanf("%f",&nota);

        soma = soma + nota;

        if(nota > 5.0)
        {
            nota_acima5 +=1;

        }

    }

    media = soma/quant_alunos;

    if(nota_acima5>0)
    {
        printf("\n%d alunos estão com a nota acima de 5,0 \n",nota_acima5);
        printf("\nMédia aritmética das notas: %.1f\n",media);
    }
    else
    {
        printf("\nNão há nenhum aluno com nota acima de 5.\n");
        printf("\nMédia aritmética das notas: %.1f\n",media);
    }

}
