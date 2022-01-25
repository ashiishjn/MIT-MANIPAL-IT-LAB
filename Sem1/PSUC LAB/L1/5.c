#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int p,r,n;
    float ci,si,a,b;
    printf("Enter the values of principle amount, interest and time\n");
    scanf("%d%d%d",&p,&r,&n);
    si=p*n*r/100;
    a=1+(r/100.0);
    b=pow(a,n);
    ci=(p*b)-p;
    printf("\nThe simple interest is %f",si);
    printf("\nThe compound interest is %f",ci);
    return 0;
}
