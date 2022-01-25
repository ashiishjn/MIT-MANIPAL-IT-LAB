#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,i,f=0,n;
    printf("Enter the length of array\n");
    scanf("%d",&l);
    int a[l];
    printf("Enter the elements of array\n");
    for(i=0;i<l;i++)
        scanf("%d",&a[i]);
    printf("Enter the number to be searched\n");
    scanf("%d",&n);
    for(i=0;i<l;i++)
    {
        if(a[i]==n)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        printf("search successful");
    else
        printf("search unsuccessful");
    return 0;
}
