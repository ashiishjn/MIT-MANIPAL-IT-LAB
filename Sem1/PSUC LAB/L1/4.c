#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f;
    a=sizeof(int);
    b=sizeof(char);
    c=sizeof(float);
    d=sizeof(double);
    e=sizeof(long int);
    f=sizeof(long double);
    printf("Size of int data type is %d",a);
    printf("\nSize of char data type is %d",b);
    printf("\nSize of float data type is %d",c);
    printf("\nSize of double data type is %d",d);
    printf("\nSize of long int data type is %d",e);
    printf("\nSize of long double data type is %d",f);
    return 0;
}
