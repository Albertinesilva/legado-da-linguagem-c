#include <stdio.h>
#include <locale.h>

void copiarString(char *copiarDaqui,char *colarAqui)
{
    while(*copiarDaqui != '\0')
    {
        *colarAqui = *copiarDaqui;
        ++copiarDaqui;
        ++colarAqui;
    }
    *colarAqui = '\0';
}
void main()
{
    setlocale(LC_ALL,"portuguese");

    void copiarString(char *copiarDaqui,char *colarAqui);

    char string1[]="Pão com Mortadela";
    char string2[20];

    copiarString(string1,string2);
    printf("\nString2 = %s\n",string2);

}
