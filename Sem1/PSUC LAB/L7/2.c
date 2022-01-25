#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char a[1000];
    printf("Enter a string\n");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>=65 && a[i]<=90)
            a[i]+=32;
        else if (a[i]>=97 && a[i]<=122)
            a[i]-=32;
    }
    printf("The new string is\n");
    puts(a);
    return 0;

}
