#include <stdio.h>
#include <stdlib.h>

int main(){
int *p, *p1, x = 10;
float y = 20.0;
p = &x;
printf("Conteudo apontado por p: %d \n",*p);
p1 = p;
printf("Conteudo apontado por p1: %d \n",*p1);
p = &y;
printf("Conteudo apontado por p: %d \n",*p);
printf("Conteudo apontado por p: %f \n",*p);
printf("Conteudo apontado por p: %f \n",*((float*)p));
system("pause");

/*Conteudo apontado por p: 10
Conteudo apontado por p1: 10
Conteudo apontado por p: 1101004800
Conteudo apontado por p: 0.000000
Conteudo apontado por p: 20.000000*/

return 0;
}
