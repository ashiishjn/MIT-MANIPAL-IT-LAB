#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,f,p=0,c=0;
    printf("Enter numbers\n");
    printf("Enter -1 to terminate the loop\n");
    do
    {
        scanf("%d",&n);
        i=2;
        f=0;
        while(i<n)
        {
            if(n%i==0)
            {
                f=1;
                break;
            }
            i++;
        }
        if(f==0&&n!=1&&n!=-1)
            p++;
        else if(f==1&&n!=1&&n!=-1)
            c++;
    }while(n!=-1);
    printf("Number of prime nos. are %d\n",p);
    printf("Number of composite nos. are %d",c);
    return 0;
}
