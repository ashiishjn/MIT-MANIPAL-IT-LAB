#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3;
    printf("Enter three numbers to be arranged\n");
    scanf("%d%d%d",&n1,&n2,&n3);
    if(n1>n2)
    {
        if(n1>n3)
            printf("The largest among the three numbers is %d",n1);
        else
            printf("The largest among the three numbers is %d",n3);
    }
    else if(n2>n3)
        printf("The largest among the three numbers is %d",n2);
    else
        printf("The largest among the three numbers is %d",n3);
    return 0;
}
