#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,vol,sa;
    printf("Enter the radius of the sphere\n");
    scanf("%d",&r);
    vol=4*3.14*r*r*r/3;
    sa=4*3.14*r*r;
    printf("\nVolume of the sphere is %d",vol);
    printf("\n Surface area of the sphere is %d",sa);
    return 0;
}
