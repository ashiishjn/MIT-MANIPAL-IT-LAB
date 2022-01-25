#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,l,p;
    printf("Enter the length of array\n");
    scanf("%d",&l);
    int a[l];
    printf("Enter the elements of array\n");
    for(i=0;i<l;i++)
        scanf("%d",&a[i]);
    printf("Enter the position where number is to be deleted at\n");
    scanf("%d",&p);
    if(p>l)
    {
        printf("Invalid input");
        exit(0);
    }
    for(i=p-1;i<l-1;i++)
        a[i]=a[i+1];
    printf("The new array is\n");
    for(i=0;i<l-1;i++)
        printf("%d\n",a[i]);
    return 0;
}
