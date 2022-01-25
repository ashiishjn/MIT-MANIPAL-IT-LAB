#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,y,a,w,dy;
    printf("Enter the number of days\n");
    scanf("%d",&d);
    y=d/365;
    a=d%365;
    w=a/7;
    dy=a%7;
    printf("\nThere are %d year, %d week, and %d days",y,w,dy);
    return 0;
}
