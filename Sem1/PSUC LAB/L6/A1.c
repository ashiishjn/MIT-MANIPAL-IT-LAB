#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m;
    printf("Enter the dimension of matrix\n");
    scanf("%d%d",&n,&m);
    int a[n][m],c[m],r[n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        r[i]=0;
        for(j=0;j<m;j++)
            r[i]=r[i]+a[i][j];
    }
    for(i=0;i<m;i++)
    {
        c[i]=0;
        for(j=0;j<n;j++)
            c[i]=c[i]+a[j][i];
    }
    printf("The row and column sum is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d\t",a[i][j]);
        printf("= %d\n",r[i]);
    }
    printf("\n");
    for(j=0;j<m;j++)
        printf("%d\t",c[j]);
    return 0;
}
