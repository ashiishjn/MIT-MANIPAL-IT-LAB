#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char a[50],b[6];
    printf("Enter the user name:  ");
    gets(a);
    printf("Enter the password(6 characters):  ");
    for(i=0;i<6;i++)
    {
          b[i]=getch();
          printf("*");
    }
    return 0;
}
