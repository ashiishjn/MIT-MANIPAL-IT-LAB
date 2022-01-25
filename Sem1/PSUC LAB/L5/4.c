#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,l,p;
    printf("Enter the length of array\n");
    scanf("%d",&l);
    int a[l+1];
    printf("Enter the elements of array\n");
    for(i=0;i<l;i++)
        scanf("%d",&a[i]);
    printf("Enter the element and the position to be inserted at\n");
    scanf("%d%d",&n,&p);
    for(i=l;i>=p;i--)
        a[i]=a[i-1];
    a[p-1]=n;
    printf("The new array is\n");
    for(i=0;i<=l;i++)
        printf("%d\n",a[i]);
    return 0;
}
