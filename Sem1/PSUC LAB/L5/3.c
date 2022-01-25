#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp=0,i,j,n,f=0;
    char ch;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter a for ascending and d for descending sorting\n");
    fflush(stdin);
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a': for(i=0;i<n-1;i++)
                  {
                        for(j=0;j<n-i-1;j++)
                      {
                          if(a[j]>a[j+1])
                          {
                              temp=a[j];
                              a[j]=a[j+1];
                              a[j+1]=temp;
                          }
                      }

                  }
                  f=1;
                  break;
         case 'd':for(i=0;i<n-1;i++)
                  {
                      for(j=0;j<n-i-1;j++)
                      {
                          if(a[j]<a[j+1])
                          {
                              temp=a[j];
                              a[j]=a[j+1];
                              a[j+1]=temp;
                          }
                      }

                  }
                  f=1;
                  break;
         default:printf("Invalid Input");
    }
    if(f==1)
    {
       printf("The numbers in sorted order are\n");
       for(i=0;i<n;i++)
          printf("%d\n",a[i]);
    }
    return 0;
}
