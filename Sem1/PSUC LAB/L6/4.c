#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,temp;
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
    {
        temp=a[i][i];
        a[i][i]=a[i][n-1-i];
        a[i][n-1-i]=temp;
    }
    printf("The new matrix is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    return 0;
}
