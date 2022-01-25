#include <stdio.h>
#include <stdlib.h>
int fact(int n)
{
      int i,f=1;
      for(i=1;i<=n;i++)
            f=f*i;
      return(f);
}
int main()
{
    int n,r,nCr,i,r1=1,r2=1;
    printf("Enter the value of n and r\n");
    scanf("%d%d",&n,&r);

    for(i=1;i<=n;i++)
    {
          if(i<=r)
            r1=r1*i;
          if(i<=(n-r))
            r2=r2*i;
    }
    nCr= fact(n)/(r1*r2);
    printf("nCr is %d",nCr);
    return 0;
}
