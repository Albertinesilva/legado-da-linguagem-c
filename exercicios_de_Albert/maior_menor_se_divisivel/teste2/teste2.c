#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>



void main()
{
    setlocale(LC_ALL,"portuguese");

    int num1=0,num2=0,num3=0,num4=0,num5=0;
    int aux=0;

    printf("\n\t1° número: ");
    scanf("%d",&num1);

    printf("\n\t2° número: ");
    scanf("%d",&num2);

    printf("\n\t3° número: ");
    scanf("%d",&num3);

    printf("\n\t4° número: ");
    scanf("%d",&num4);

    printf("\n\t5° número: ");
    scanf("%d",&num5);



    if(num1>num2&&num1>num3&&num1>num4&&num1>num5)
    {
        printf("\n\t%d é maior",num1);
    }
    else
    {
        if(num1<num2&&num1<num3&&num1<num4&&num1<num5)
        {
            printf("\n\t%d é menor",num1);
        }

    }
    if(num2>num1&&num2>num3&&num2>num4&&num2>num5)
    {
        printf("\n\t%d é maior",num2);
    }
    else
    {
        if(num2<num1&&num2<num3&&num2<num4&&num2<num5)
        {
            printf("\n\t%d é menor",num2);
        }

    }
    if(num3>num1&&num3>num2&&num3>num4&&num3>num5)
    {
        printf("\n\t%d é maior",num3);
    }
    else
    {
        if(num3<num1&&num3<num2&&num3<num4&&num3<num5)
        {
            printf("\n\t%d é menor",num3);
        }

    }
    if(num4>num1&&num4>num2&&num4>num3&&num4>num5)
    {
        printf("\n\t%d é maior",num4);
    }
    else
    {
        if(num4<num1&&num4<num2&&num4<num3&&num4<num5)
        {
            printf("\n\t%d é menor",num4);
        }

    }
    if(num5>num1&&num5>num2&&num5>num3&&num5>num4)
    {
        printf("\n\t%d é maior",num5);
    }
    else
    {
        printf("\n\t%d é menor",num5);

    }






    if(num1%2==0&&num1%3==0)
    {
        printf("\n\t%d é divisivel por 2 e 3\n",num1);
    }

    if(num2%2==0&&num2%3==0)
    {
        printf("\n\t%d é divisivel por 2 e 3\n",num2);
    }

    if(num3%2==0&&num3%3==0)
    {
        printf("\n\t%d é divisivel por 2 e 3\n",num3);
    }

    if(num4%2==0&&num4%3==0)
    {
        printf("\n\t%d é divisivel por 2 e 3\n",num4);
    }



    if(num1<num2 && num1<num3 && num2<=num3)
    {
        printf("\n\t%d,%d,%d",num1,num2,num3);
    }
    else
    {
        if(num2<num1 && num2<num3 && num1<=num3)
        {
            printf("\n\t%d,%d,%d",num2,num1,num3);
        }
        else
        {
            if(num3<num2 && num3<num2 && num2<=num1)
            {
                printf("\n\t%d,%d,%d",num3,num2,num1);
            }
        }
    }

}


