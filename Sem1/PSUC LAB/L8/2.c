#include <stdio.h>
#include <stdlib.h>
int Largest(int num,int m)
{
      if(num>m)
            m=num;
      return(m);
}
int main()
{
    int n,num,i,m;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("Enter the numbers\n");
    scanf("%d",&num);
    m=num;
    for(i=1;i<=n-1;i++)
    {
          scanf("%d",&num);
          m=Largest(num,m);
    }
    printf("The largest number is %d",m);
    return 0;
}
