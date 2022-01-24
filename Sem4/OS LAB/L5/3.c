#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
int i,j,status,n,s;
printf("Enter n");
scanf("%d",&n);
char a[5][20],temp[20],sm[20];
printf("Enter the strings\n");
for(i=0;i<n;i++)
    scanf("%s",a[i]);
pid_t pid1,pid2;
pid1=fork();
if(pid1==0)
{
    printf("In child process \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(strcmp(a[j],a[j+1]) > 0 )
            {
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }
    printf("\nThe list in sorted order are \n");
    for(i=0;i<5;i++)
    puts(a[i]);
}
if(pid1==0)
{
    for(i=0;i<n-1;i++)
    {
        s=i;
        strcpy(sm,a[i]);
        for(j=i+1;j<n;j++)
        {
            if(strcmp(sm,a[j]) > 0)
            {
                strcpy(sm,a[j]);
                s=j;
            }
        }
        strcpy(a[s],a[i]);
        strcpy(a[i],sm);
    }
    printf("The list in sorted order are \n");
    for(i=0;i<5;i++)
    puts(a[i]);
}
else if(pid1>0)
{
    pid2=fork();
    if(pid2==0)
    {
        printf("QQQ");
    }
    wait(&status);
    if(WIFEXITED (status))
    printf("Child returned");
    printf("In parents procees\n");
}
return 0;
}

