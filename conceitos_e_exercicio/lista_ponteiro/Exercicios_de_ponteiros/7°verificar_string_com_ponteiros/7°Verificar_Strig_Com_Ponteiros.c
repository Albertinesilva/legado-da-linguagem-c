#include <stdio.h>
#include <stdlib.h>

void Comparar_String(char *string1,char *string2);

void main()
{
    char a[10]="Albert";
    char b[10]="Rosa";

    Comparar_String(a,b);

}
void Comparar_String(char *string1,char *string2)
{

    if(string1 == string2)
    {
        printf("\nVerdadeira\n");
    }
    else
    {
        printf("\nFalsa\n");
    }

}
