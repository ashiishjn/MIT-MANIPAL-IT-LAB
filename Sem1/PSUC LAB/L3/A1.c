#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,d,c,f=1,s=0,i;
    printf("Enter any number\n");
    scanf("%d",&n);
    c=n;
    while(c>0)
    {
        d=c%10;
        i=1;
        while(i<=d)
        {
            f=f*i;
            i++;
        }
        s=s+f;
        f=1;
        c=c/10;
    }
    if(s==n)
        printf("%d is a strong number",n);
    else
        printf("%d is not a strong number",n);
    return 0;
}
