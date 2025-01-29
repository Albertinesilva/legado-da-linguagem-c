#include <stdio.h>

void main(){


int num,min,seg;

printf("Informe:");
scanf("%i",&num);

min = (num%3600)/60;
seg =(num%3600)%60;
printf("minuto %i \n",min);
printf("\nsecundo %i\n ",seg);

}
