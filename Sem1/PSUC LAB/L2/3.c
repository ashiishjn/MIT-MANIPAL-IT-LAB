#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Enter any two number\n");
    scanf("%d%d",&a,&b);
     a=a-b;
     b=a+b;
     a=b-a;
    printf("The swapped numbers are %d and %d",a,b);
    return 0;
}
