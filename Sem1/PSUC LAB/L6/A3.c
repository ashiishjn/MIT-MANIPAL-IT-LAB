#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,f=0;
    printf("Enter the dimension of square matrix\n");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                f=1;
                break;
            }
        }
    }
    if(f==0)
        printf("It is a lower traingular matrix");
    else
        printf("It is not a lower traingular matrix");
    return 0;
}
