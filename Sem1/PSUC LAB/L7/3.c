#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,f=0;
    char a[1000];
    printf("Enter a string\n");
    gets(a);
    for(i=0;a[i]!='\0';i++);
    n=i+1;
    for(i=0;i<n/2;i++)
    {
        if(a[i]!=a[n-2-i] && a[i]+32!=a[n-2-i] && a[i]-32!=a[n-2-i])
        {
            f=1;
            break;
        }
    }
    if(f==0)
        printf("The string is palindrome");
    else
        printf("The string is not a palindrome");
    return 0;
}
