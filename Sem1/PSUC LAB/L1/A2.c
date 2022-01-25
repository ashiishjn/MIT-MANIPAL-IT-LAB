#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,h,a,m,sec;
    printf("Enter the time in seconds\n");
    scanf("%d",&s);
    h=s/3600;
    a=s%3600;
    m=a/60;
    sec=a%60;
    printf("\nThere are %d hour, %d minute, and %d seconds",h,m,sec);
    return 0;
}
