#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=10,n,d,c;
    printf("Enter any number\n");
    scanf("%d",&n);
    c=n;
    for( ;sum>9;)
    {
        sum=0;
        for(;c>0;c/=10)
        {
            d=c%10;
            sum+=d;
        }
        c=sum;
    }
    printf("Generic root of %d is %d",n,sum);
    return 0;
}
