#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,c,arm=0,d;
    printf("Enter any number \n");
    scanf("%d",&n);
    c=n;
    while(c>0)
    {
        d=c%10;
        arm=arm+d*d*d;
        c=c/10;
    }
    if(arm==n)
        printf("%d is an armstrong no.",n);
    else
        printf("%d is not an armstrong no.",n);
    return 0;
}
