#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void imprime_Matriz(int x[5][15],int a[15],int b[15],int c[15],int d[15],int e[15]);

void main()
{
    setlocale(LC_ALL,"portuguese");

    int mat[5][15];
    int turma1[15], turma2[15],turma3[15],turma4[15],turma5[15];
    int media1=0,media2=0,media3=0,media4=0,media5=0;

    srand(time(NULL));

    for(int l=0; l<5; l++)
    {
        for(int c=0; c<15; c++)
        {
            mat[l][c]=rand()%35+1;
            turma1[c]=mat[0][c];
            turma2[c]=mat[1][c];
            turma3[c]=mat[2][c];
            turma4[c]=mat[3][c];
            turma5[c]=mat[4][c];
        }
    }
    printf("\n\n");
    imprime_Matriz(mat,turma1,turma2,turma3,turma4,turma5);
    printf("\n\n");

    for(int i=0; i<15; i++)
    {
        printf("\nTurma1 %.2d | Turma2 %.2d | Turma3 %.2d | Turma4 %.2d | Turma5 %.2d",turma1[i],turma2[i],turma3[i],turma4[i],turma5[i]);
    }



}
void imprime_Matriz(int x[5][15],int a[15],int b[15],int c[15],int d[15],int e[15])
{
    float media1=0,media2=0,media3=0,media4=0,media5=0;
    int menor1=9999,menor2=9999,menor3=9999,menor4=9999,menor5=9999;

    for(int l=0; l<5; l++)
    {

        for(int c=0; c<15; c++)
        {

            printf("|%d|",x[l][c]);
        }
        printf("\n");
    }

    for(int i=0; i<15; i++)
    {

        media1=media1+a[i];
        media2=media2+b[i];
        media3=media3+c[i];
        media4=media4+d[i];
        media5=media5+e[i];
    }
    printf("\n1° Turma/Media = %.2f",media1/15);
    printf("\n2° Turma/Media = %.2f",media2/15);
    printf("\n3° Turma/Media = %.2f",media3/15);
    printf("\n4° Turma/Media = %.2f",media4/15);
    printf("\n5° Turma/Media = %.2f",media5/15);

    for(int x=0; x<15; x++)
    {

        if(a[x]<menor1)
        {
            menor1=a[x];
        }
        if(b[x]<menor2)
        {
            menor2=b[x];
        }
        if(c[x]<menor3)
        {
            menor3=c[x];
        }
        if(d[x]<menor4)
        {
            menor4=d[x];
        }
        if(e[x]<menor5)
        {
            menor5=e[x];
        }
    }
    printf("\n\n");
    printf("\n1° Turma/Menor Nota = %d",menor1);
    printf("\n2° Turma/Menor Nota = %d",menor2);
    printf("\n3° Turma/Menor Nota = %d",menor3);
    printf("\n4° Turma/Menor Nota = %d",menor4);
    printf("\n5° Turma/Menor Nota = %d",menor5);

}

