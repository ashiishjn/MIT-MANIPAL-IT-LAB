#include <stdio.h>
#include <stdlib.h>
int array_sum(int a[],int n)
{
      int sum=0,i;
      for(i=0;i<n;i++)
      sum=sum+a[i];
      return(sum);
}
int main()
{
    int n,i;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("The sum of the elements in the array is %d",array_sum(a,n));
    return 0;
}
