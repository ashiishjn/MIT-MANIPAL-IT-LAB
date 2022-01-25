#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a,n,k;
    printf("Enter the value of n and k\n");
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            a=i*j;
            printf("%d ",a);
        }
        printf("\n");
    }
    return 0;
}
