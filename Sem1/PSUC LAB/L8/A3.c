#include <stdio.h>
#include <stdlib.h>
int toggle(char a[],int n)
{
      int i;
      for(i=0;i<n;i++)
      {
            if(a[i]>=65&&a[i]<=90)
                  a[i]+=32;
            else if(a[i]>=97&&a[i]<=122)
                  a[i]-=32;
      }
      return(a);
}
int main()
{
    int i;
    char a[100];
    printf("Enter the string\n");
    gets(a);
    for(i=0;a[i]!='\0';i++);
    puts(toggle(a,i));
    return 0;
}
