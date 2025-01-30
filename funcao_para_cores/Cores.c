#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>



int main()
{
    int c;
    char comando[9]="color ";
    char cores[9];

    setlocale(LC_ALL,"portuguese");

    SetConsoleTitle("Cores com system");



    do
    {
        printf("\nAlbert: ");
        scanf("%d",&c);


        switch(c)
        {
        case 1:
            strcat(comando,"fc");
            system (comando);
            strcpy(comando,"color ");
            printf("\nAlbert");


            break;

        case 2:
            strcat(comando, "2d");
            system (comando);
            strcpy(comando,"color ");
            printf("\nAlbert");

            break;
        }

    }
    while(c<3);

    //system (comando);


}
