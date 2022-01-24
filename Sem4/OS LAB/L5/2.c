#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
char a[5][20],temp[20];
int i,j,status;
printf("Enter the 5 strings\n");
for(int i=0;i<5;i++)
scanf("%s",a[i]);
pid_t pid;
pid=fork();
if(pid==0)
{
printf("In child process \n");
for(i=0;i<4;i++)
{
for(j=0;j<4-i;j++)
{
if(strcmp(a[j],a[j+1]) > 0 )
{
strcpy(temp,a[j]);
strcpy(a[j],a[j+1]);
strcpy(a[j+1],temp);
}
}
}
printf("The list in sorted order are \n");
for(i=0;i<5;i++)
puts(a[i]);
}
else if(pid>0)
{
wait(&status);
if(WIFEXITED (status))
printf("Child returned");
printf("In parents procees\n");
printf("The list in unsorted order are \n");
for(i=0;i<5;i++)
puts(a[i]);
}
return 0;
}

