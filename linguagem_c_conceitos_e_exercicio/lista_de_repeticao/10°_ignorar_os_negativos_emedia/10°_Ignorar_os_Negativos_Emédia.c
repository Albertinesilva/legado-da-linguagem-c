#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    int positivo=0,i=0;
    float media=0;

    while(i!=10)
    {
        printf("\nInforme o %d° número: ",i+1);
        fflush(stdin);
        scanf("%d",&positivo);

        if(positivo>0)
        {
            i++;
            media+=positivo;
        }
    }
    media=media/10;
    printf("\nMédia = %f\n",media);
}
