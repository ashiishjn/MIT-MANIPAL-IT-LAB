#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n;
    char temp[50];
    printf("Enter the number of names\n");
    scanf("%d",&n);
    char a[n][50];
    printf("Enter the names\n");
    fflush(stdin);
    for(i=0;i<n;i++)
        gets(a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(a[j],a[j+1])>0)
            {
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }
    printf("The names in sorted order are\n");
    for(i=0;i<n;i++)
        puts(a[i]);
    return 0;
}
