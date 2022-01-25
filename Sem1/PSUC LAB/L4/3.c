#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n,i;
    float x,term,sum,no,pi=3.141592;
    printf("Enter the value of n and x\n");
    scanf("%d%f",&n,&x);
    no=x;
    x=x*pi/180.0;
    term=x;
    sum=x;

    for(i=1;i<n;i++)
    {
        term=term*(((-1)*x*x)/(2*i*(2*i+1)));
        sum+=term;
    }
    printf("\nSin(%.2f)=%.2f",no,sum);
    return 0;
}
