#include <stdio.h>
#include <stdlib.h>
int IsPalin(char a[])
{

      int i,l,f=0;
      for(l=0;a[l]!='\0';l++);

      for(i=0;i<l/2;i++)
      {
            if(a[i]!=a[l-i-1]&&a[i]+32!=a[l-i-1]&&a[i]-32!=a[l-i-1])
            {
                  f=1;
                  break;
            }
      }
      return(f);
}
int main()
{
    char a[100];
    printf("Enter the string\n");
    gets(a);
    if(IsPalin(a))
      printf("It is not a palindrome");
    else
      printf("It is a palindrome");
    return 0;
}
