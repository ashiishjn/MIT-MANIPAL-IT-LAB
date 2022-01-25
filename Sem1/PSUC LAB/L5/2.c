#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("The prime numbers are\n");
    for(i=0;i<n;i++)
    {
        int f=0;
        for(j=2;j<a[i];j++)
        {
            if(a[i]%j==0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            printf("%d\n",a[i]);
    }
    return 0;
}
