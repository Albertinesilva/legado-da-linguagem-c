#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int hora;
    int minutos;
    int segundos;
} horario;

int main()
{
    setlocale(LC_ALL,"portuguese");

    horario horas[5];
    int h=0,m=0,s=0;

    for(int i=0; i<5; i++)
    {
        printf("\n%d° Horario",i+1);
        printf("\nDigite a hora: ",i+1);
        fflush(stdin);
        scanf("%d",&horas[i].hora);

        printf("\nDigite a Minuto: ");
        fflush(stdin);
        scanf("%d",&horas[i].minutos);

        printf("\nDigite os Segundos: ");
        fflush(stdin);
        scanf("%d",&horas[i].segundos);

        h = horas[0].hora;
        m = horas[0].minutos;
        s = horas[0].segundos;
    }

    for(int i=0; i<5; i++)
    {
        if(horas[i].hora >= h)
        {
            if(horas[i].minutos >= m)
            {

                if(horas[i].segundos >= s)
                {
                    h = horas[i].hora;
                    m = horas[i].minutos;
                    s = horas[i].segundos;
                }

            }
        }
    }

    printf("\nHorário = %d:%d:%d\n",h,m,s);
    system("pause");
    return 0;
}


