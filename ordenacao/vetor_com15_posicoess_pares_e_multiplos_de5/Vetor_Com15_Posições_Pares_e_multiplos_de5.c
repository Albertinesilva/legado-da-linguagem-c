#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main()
{
    srand(time(NULL));

    int vetor[50];

    printf("\n");
    for(int i=0; i<50; i++){

        vetor[i]=rand()%50+1;
    }

    for(int y=0; y<50; y++){

        printf("%d,",vetor[y]);
    }

    printf("\n\n");
    for(int x=0; x<50; x++){

        if(vetor[x]%2==0){
            printf("%d - ",vetor[x]);
        }
    }

    printf("\n\n");
    for(int a=0; a<50; a++){

        if(vetor[a]%5==0){
            printf("%d - ",vetor[a]);
        }
    }
}
