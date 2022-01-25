#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m,temp,d,c;
    printf("Enter the dimension of matrix\n");
    scanf("%d%d",&n,&m);
    int a[n][m];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter the column numbers to exchange\n");
    scanf("%d%d",&d,&c);
    if(d>=1&&d<=m&&c>=1&&c<=m)
    {
    for(i=0;i<n;i++)
    {
        temp=a[i][c-1];
        a[i][c-1]=a[i][d-1];
        a[i][d-1]=temp;
    }
    }
    else
    {
        printf("Invalid Input");
        exit(0);
    }
    printf("Enter the row numbers to exchange\n");
    scanf("%d%d",&d,&c);
    if(d>=1&&d<=n&&c>=1&&c<=n)
    {
    for(i=0;i<m;i++)
    {
        temp=a[c-1][i];
        a[c-1][i]=a[d-1][i];
        a[d-1][i]=temp;
    }
    }
    else
    {
        printf("Invalid Input");
        exit(0);
    }
    printf("The new matrix is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    return 0;
}
