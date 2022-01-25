#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,trace=0,norm=0;
    printf("Enter the dimension of square matrix\n");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
        trace=trace+a[i][i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            norm=norm+a[i][j]*a[i][j];
    }
    printf("The trace of the matrix is %d\n",trace);
    printf("The norm of the matrix is %d",norm);
    return 0;
}
