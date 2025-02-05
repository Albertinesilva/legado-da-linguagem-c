#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    int *A,y=0,num=0,verificador=0;

    A = (int *)malloc(10 * sizeof(int));
    if(A == NULL)
    {
        printf("\nErro: Memória Insuficiente!");
        system("pause");
        exit(1);
    }

    while(y!=10)
    {
        printf("\nDigite um número: ");
        fflush(stdin);
        scanf("%d",&num);
        system("cls");

        for(int i=0; i<10; i++)
        {
            if(A[i] == num)
            {
                verificador++;
            }
        }
        if(verificador >= 1)
        {
            printf("\nExiste o Número %d no vetor!\n",num);
            verificador=0;
        }
        else
        {
            A[y]=num;
            y++;
        }
    }
    printf("\n");

    for(int i=0; i<10; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n\n");

}
