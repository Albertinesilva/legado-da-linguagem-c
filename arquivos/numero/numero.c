#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *file;
    file = fopen("numero.txt","w");
    fprintf(file,"1 2 3");
    fclose(file);

}
