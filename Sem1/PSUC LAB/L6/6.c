#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m,p=0,num;
    printf("Enter the dimension of matrix\n");
    scanf("%d%d",&n,&m);
    int a[n][m];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==num)
                p++;
        }
    }
    if(p>0)
        printf("the number %d appeared %d times",num,p);
    else
        printf("Search unsuccessful");
    return 0;
}
