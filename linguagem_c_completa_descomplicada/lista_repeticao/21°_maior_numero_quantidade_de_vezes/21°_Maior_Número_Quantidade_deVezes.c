#include <stdio.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    int num=0,maior=0;
    int quant=0,quant_vezes=0;

    printf("\nInforme a quantidade de vezes: ");
    fflush(stdin);
    scanf("%d",&quant);

    for(int i=0; i<quant; i++)
    {
      printf("\nInforme o %d número: ",i+1);
      fflush(stdin);
      scanf("%d",&num);

      if(num>=maior)
      {
          maior=num;
          quant_vezes++;
      }

    }
    printf("\nMaior = %d\nQuantidade de vezes que foi lido = %d\n",maior,quant_vezes);


}
