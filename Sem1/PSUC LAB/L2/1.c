#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter any number\n");
    scanf("%d",&n);
    if(n%2==0)
        printf("The number is even");
    else
        printf("The number is odd");
    return 0;
}
