#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,l,s,i;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    s=a[0];
    l=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>l)
            l=a[i];
        else if (a[i]<s)
            s=a[i];
    }
    printf("The smallest number is %d\n",s);
    printf("The largest number is %d\n",l);
    return 0;
}
