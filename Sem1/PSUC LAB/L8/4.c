#include <stdio.h>
#include <stdlib.h>
int CornerSum(int p,int q,int a[][q])
{
      int s=0;
      s=a[0][0]+a[p-1][0]+a[0][q-1]+a[p-1][q-1];
      return(s);
}
int main()
{
    int s1,i,j,p,q,s2=0;
    printf("Enter the dimension of matrix\n");
    scanf("%d%d",&p,&q);
    int a[p][q];
    printf("Enter the elements\n");
    for(i=0;i<p;i++)
      {
            for(j=0;j<q;j++)
                  scanf("%d",&a[i][j]);
      }
    s1=CornerSum(p,q,a);
    s2=a[0][0]+a[p-1][0]+a[0][q-1]+a[p-1][q-1];
    if(s1==s2)
      printf("The Corner sum is correct");
    else
      printf("The corner sum is incorrect");
    return 0;
}
