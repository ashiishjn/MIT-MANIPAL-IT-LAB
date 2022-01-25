#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,a=1;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",a);
            a++;
        }
        printf("\n");
    }
    return 0;
}
