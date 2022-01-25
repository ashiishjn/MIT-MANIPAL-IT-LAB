#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,s;
    printf("Enter any three numbers\n");
    scanf("%d%d%d",&a,&b,&c);
    s=(a<b)?((a<c)?a:c):((b<c)?b:c);
    printf("The smallest of three numbers is %d",s);
    return 0;
}
