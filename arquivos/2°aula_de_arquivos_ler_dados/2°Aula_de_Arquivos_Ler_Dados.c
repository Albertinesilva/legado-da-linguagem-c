#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *file;
    file = fopen("numero.txt","r");

    int x,y,z;

    fscanf(file, "%d %d %d",&x,&y,&z);
    printf("%d %d %d\n",x,y,z);

    fclose(file);
}
