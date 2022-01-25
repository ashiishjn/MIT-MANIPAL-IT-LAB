#include <stdio.h>
#include <stdlib.h>
int IsPrime(int num)
{
      int i,f=0;
      for(i=2;i<num;i++)
      {
            if(num%i==0)
            {
                  f=1;
                  break;
            }
      }
      return(f);
}
int main()
{
    int n,i,c=0;
    printf("Enter the value of N\n");
    scanf("%d",&n);
    printf("The prime numbers are\n");
    for(i=2;c<n;i++)
    {
        if(IsPrime(i)==0)
        {
            printf("%d\t",i);
            c++;
        }
    }
    return 0;
}
