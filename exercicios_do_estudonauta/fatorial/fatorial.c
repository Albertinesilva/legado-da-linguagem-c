#include <stdio.h>
#include <stdlib.h>

int fatorial (int n){

int i,f = 1;
for(i=1; i<=n;i++)
f=f*i;
return f;
}

int main(){
    int x,y;
    printf("Digite um valor inteiro:");
    scanf("%d",&x);

    if(x>0){
     printf("x eh positivo\n");
     y=fatorial(x);
     printf("fatorial de x eh %d\n",y);

    }else{
    if(x<0)
    printf("x eh negativo \n");

    else
    printf("x � zero \n");
    }
    printf("Fim do programa!\n");
    //system (pause);
    return 0;
}
