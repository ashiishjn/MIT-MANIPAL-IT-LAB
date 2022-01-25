#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,c=0,d=0,sum=0;
    char a[50];
    printf("Enter a string\n");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
          if(a[i]>=65&&a[i]<=90)
            c++;
          else if(a[i]>=97&&a[i]<=122)
            c++;
          else if(a[i]>=48&&a[i]<=57)
          {
                d++;
                sum=sum+a[i]-48;
          }
    }
    printf("Total number of digits are %d\n",d);
    printf("Total number of characters are %d\n",c);
    printf("Total sum of digits are %d\n",sum);
    return 0;
}
