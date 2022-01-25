#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,n,i,p=0;
    printf("Enter the length of array\n");
    scanf("%d",&l);
    int a[l];
    printf("Enter the elements of array\n");
    for(i=0;i<l;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be deleted\n");
    scanf("%d",&n);
    for(i=0;i<l;i++)
        {
           if(a[i]!=n)
           {
               a[p]=a[i];
               p++;
           }
        }
    printf("The new array is\n");
    for(i=0;i<p;i++)
        printf("%d\n",a[i]);
    return 0;
}
