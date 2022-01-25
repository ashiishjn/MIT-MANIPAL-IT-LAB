#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e1,e2,e3,e4;
    a=30;
    b=10;
    c=5;
    d=15;
    e1=(a+b)*c/d;
    e2=((a+b)*c)/d;
    e3=a+(b*c)/d;
    e4=(a+b)*(c/d);
    printf("The evaluation for the first expression is %d",e1);
    printf("\nThe evaluation for the second expression is %d",e2);
    printf("\nThe evaluation for the third expression is %d",e3);
    printf("\nThe evaluation for tyhe fourth expression is %d",e4);
    return 0;
}
