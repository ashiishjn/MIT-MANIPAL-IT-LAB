#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,o,r,p,k;
    printf("Enter the dimensions of matrix 1\n");
    scanf("%d%d",&m,&n);
    int a[m][n];
    printf("Enter the elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter the dimensions of matrix 2\n");
    scanf("%d%d",&o,&p);
    int b[o][p];
    printf("Enter the elements\n");
    for(i=0;i<o;i++)
    {
        for(j=0;j<p;j++)
            scanf("%d",&b[i][j]);
    }
    if(n!=o)
    {
        printf("Multiplication not possible");
        exit(0);
    }
    int c[m][p];
    for(i=0;i<m;i++)
    {
        int r=0;
        for(j=0;j<p;j++)
        {
              c[i][r]=0;
           for(k=0;k<n;k++)
                c[i][r]=c[i][r]+a[i][k]*b[k][j];
                r++;
        }
    }
    printf("The multiplication of the two matrices is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }
    return 0;
}
