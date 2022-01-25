#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(i==j)
                continue;
            printf("%d\t%d\n",i,j);
        }
    }
    printf("\n");
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(i==j)
                break;
            printf("%d\t%d\n",i,j);
        }
    }
    return 0;
}
