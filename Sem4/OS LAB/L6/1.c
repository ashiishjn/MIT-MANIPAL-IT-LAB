#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>   
#include <unistd.h>   
	
typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int rem_time;
	    int priority;
}Process;
	
Process* Entry()
{
    printf("No. of Processes:");
    int n;
    scanf("%d", &n);
    Process* p = (Process*) malloc( n+1 * sizeof(Process) );
    printf("Enter PID, Arrival Time, Burst Time, Priority\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d :",i+1);
        scanf("%d %d %d %d", &p[i].pid, &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].rem_time=p[i].burst_time;
    }
    p[n].pid=-1;
    return p;
}
	
int min(Process *p, int n, int timer)
{
    int min_time=9999;
    int min=-1;
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival_time<=timer && p[i].rem_time>0 && p[i].burst_time<min_time)
        {
            min_time=p[i].burst_time;
            min=i;
        }
    }
	   return min;
}	
void SJF()
{
    Process* p =Entry();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    int timer=0;
    float TAT=0;
    float WAT=0;
    int done=0;
    while(done!=n)
    {
        int i = min(p,n,timer);
        int start=timer;
        int j=i;
        int ran = p[i].rem_time;
        while(j==i)
        {
	       timer++;
           p[i].rem_time--;
	       j=min(p,n,timer);
        }
        printf("%d -> (%d %d)\n", p[i].pid, start, timer);
        if(p[i].rem_time==0)
        {
	        TAT+=(timer-p[i].arrival_time);
            WAT+=(timer-p[i].arrival_time-p[i].burst_time);       
            done++;
	    }
    }
    TAT=TAT/n;
    WAT=WAT/n;
    printf("Turnaround Time = %0.2f ms \n", TAT);
    printf("Waiting Time = %0.2f ms\n\n\n", WAT);
}
	
void RR()
{
    Process* p = Entry();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    int q;
    printf("Enter time slice:");
    scanf("%d", &q);
    int timer=0;
    int done=0;
    float TAT=0;
    float WAT=0;
    while(done!=n)
    {
        for(int i=0;i<n;i++)
        {
            int count=q;
            int start=timer;
            while(p[i].rem_time>0 && p[i].arrival_time<=timer && count>0)
            {
                timer++;
                p[i].rem_time--;
    	        count--;
    	    }
            if(start!=timer)
            {
                printf("%d -> (%d %d)\n", p[i].pid, start, timer);
                if(p[i].rem_time==0)
                {
    	            TAT+=(timer-p[i].arrival_time);
                    WAT+=(timer-p[i].arrival_time-p[i].burst_time);;
    	            done++;
        	    }
            }
    	}
    }
	TAT=TAT/n;
    WAT=WAT/n;
    printf("Turnaround Time = %0.2f ms \n", TAT);
    printf("Waiting Time = %0.2f ms\n\n\n", WAT);
}
	
int comparator(const void* p, const void* q) 
{ 
	    return ((Process*)p)->arrival_time > ((Process*)q)->arrival_time && ((Process*)p)->priority > ((Process*)q)->priority;
}
	
void Prior()
{
	    Process* p =Entry();
	    int n=0;
	    while(p[n].pid!=-1) n++;
	    qsort(p, n, sizeof(Process), comparator);
	    int timer=0;
	    float TAT=0;
        float WAT=0;
	    for(int i=0;i<n;i++)
	    {
	        WAT+=(timer-p[i].arrival_time);
	        printf("%d -> (%d %d)\n",p[i].pid, timer, timer+p[i].burst_time);
            timer+=p[i].burst_time;
	        TAT+=(timer-p[i].arrival_time);
	    }
	    TAT=TAT/n;
	    WAT=WAT/n;
	    printf("Turnaround Time = %0.2f ms \n", TAT);
	    printf("Waiting Time = %0.2f ms\n\n\n", WAT);
}
	
int main()
{
    int ch;
    while(1)
    {
        printf("1. Preemptive SJF\n");
        printf("2. Round Robin Scheduling\n");
        printf("3. Priority Scheduling\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                SJF();
                break;
            case 2:
                RR();
                break;
            case 3:
                Prior();
                break;
            default:
                printf("TRY AGAIN! \n");
        }
    }
}
