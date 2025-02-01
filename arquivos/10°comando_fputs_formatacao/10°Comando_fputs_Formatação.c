#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *f,*f1;

    f = fopen("arquivo3.txt","w");
    f1 = fopen("arquivo4.txt","w");

    if(f == NULL || f1 == NULL)
    {
        printf("Erro de abertura\n");
        system("pause");
        exit(1);
    }

    fputs("Hello ",f);
    fputs("World",f);
    fclose(f);

    fputs("Hello\n",f1);
    fputs("World\n",f1);
    //OU
    fputs("Hello",f1);
    fputc('\n',f1);
    fputs("World",f1);
    fclose(f1);
}
