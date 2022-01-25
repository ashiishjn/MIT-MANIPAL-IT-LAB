#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,sum,diff,quo,pro;
    printf("Enter any two numbers\n");
    scanf("%d%d",&a,&b);
    sum=a+b;
    diff=a-b;
    pro=a*b;
    quo=a/b;
    printf("The sum of two numbers is %d",sum );
    printf("\nThe difference of the two numbers is %d",diff);
    printf("\nThe product of the two numbers is %d",pro);
    printf("\nthe quotient of the two numbers is %d", quo);
    return 0;
}
