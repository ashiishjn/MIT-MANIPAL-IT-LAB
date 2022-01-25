#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Enter any number\n");
    scanf("%d",&x);
    if(x>0)
        y=1;
    else if(x==0)
        y=0;
    else if(x<0)
        y=-1;
    printf("The value of Y is %d",y);
    return 0;
}
