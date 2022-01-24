#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
pid_t getpid(void);
pid_t getppid(void);
int main()
{
pid_t pid;
pid=fork();
if(pid<0)
printf("Child process creation failed");
else if(pid>0)
{
printf("In child process\n");
printf("PID : %d \n",getpid());
printf("Parent's PID: %d  \n",getppid());
}
else
{
printf("In parent process \n");
printf("PID : %d \n",getpid());
printf("Parent's PID : %d \n",getppid());
}
return 0;
}
