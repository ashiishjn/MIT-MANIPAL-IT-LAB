#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,sum=0,i;
    printf("Enter the number of digits\n");
    scanf("%d",&l);
    int a[l];
    printf("Enter the digits\n");
    for(i=0;i<l;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>9)
        {
            printf("Invalid Input");
            exit(0);
        }
    }
    for(i=l-1;i>=0;i--)
        sum=sum*10+a[i];
    printf("The number is %d",sum);
    return 0;
}
