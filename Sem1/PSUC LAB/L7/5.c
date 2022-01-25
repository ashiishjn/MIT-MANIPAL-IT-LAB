#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j,k,p;
    char a[1000],d[50];
    printf("Enter a sentence\n");
    gets(a);
    printf("Enter the word to be deleted");
    gets(d);
    for(i=0;a[i]!='\0';i++);
    n=i;
    for(i=0;d[i]!='\0';i++);
    p=i;
    for(i=0;i<n;i++)
    {
        int f=0;
        if(a[i-1]==32||i==0)
        {
            for(j=0;d[j]!='\0';j++)
            {
                if(a[j+i]!=d[j]&&a[j+i]+32!=d[j]&&a[j+i]-32!=d[j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0&&a[i+j]==32)
            {
                for(k=i;k<n;k++)
                a[k]=a[k+p];
                n-=p;
            }
        }
    }
    printf("The altered sentence is\n");
    for(i=0;i<n;i++)
        printf("%c",a[i]);
    return 0;
}
