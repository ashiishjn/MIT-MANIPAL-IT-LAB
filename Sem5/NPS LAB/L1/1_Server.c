#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 100

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSortA(int a[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
    for (j = 0; j < n-i-1; j++)
        if (a[j] > a[j+1])
            swap(&a[j], &a[j+1]);
}
void bubbleSortD(int a[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
    for (j = 0; j < n-i-1; j++)
        if (a[j] < a[j+1])
            swap(&a[j], &a[j+1]);
}
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i+1;
    return 0;
}

int main()
{
	int sockfd,newsockfd,retval;
	socklen_t actuallen;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;

	char buff[MAXSIZE];
	int a=0;
	sockfd=socket(AF_INET,SOCK_STREAM,0);

	if(sockfd==-1)
	{
	printf("\nSocket creation error");
	}

	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);  
	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==1)
	{
	printf("Binding error");
	close(sockfd);
	}

	retval=listen(sockfd,1);
	if(retval==-1)
	{
	close(sockfd);
	}
	int count=0;
	actuallen=sizeof(clientaddr);
	newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);


	if(newsockfd==-1)
	{
	close(sockfd);
	}
	int i,j;
	
	while(1)
	{
		recedbytes=recv(newsockfd,buff,sizeof(buff),0);
		if(recedbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		int a[100],n=buff[0]-'0';
		for(i=0;i<n;i++)
		{
			a[i] = buff[i+1]-'0';
		}
		recedbytes=recv(newsockfd,buff,sizeof(buff),0);
		if(recedbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		if(buff[0]=='5')
			break;
		int m =buff[0]-'0';
		int x = buff[1]-'0';
		if(m==1)
		{
			memset(buff, '\0', sizeof(buff));
			x = search(a,n,x);
			buff[0]=x+'0';
			sentbytes=send(newsockfd,buff,sizeof(buff),0);
			if(sentbytes==-1)
			{
				printf("!!");
				close(newsockfd);
			}
			
		}
		else if(m==2)
		{
			memset(buff, '\0', sizeof(buff));
			bubbleSortA(a,n);
			for(i=0;i<n;i++)
			{
				buff[i] = a[i]+'0';
			}
			sentbytes=send(newsockfd,buff,sizeof(buff),0);
			if(sentbytes==-1)
			{
				printf("!!");
				close(newsockfd);
			}
		}
		else if(m==3){
			memset(buff, '\0', sizeof(buff));
			bubbleSortD(a,n);
			for(i=0;i<n;i++)
			{
				buff[i] = a[i]+'0';
			}
			sentbytes=send(newsockfd,buff,sizeof(buff),0);
			if(sentbytes==-1)
			{
				printf("!!");
				close(newsockfd);
			}
		}else if(m==4)
		{
				memset(buff, '\0', sizeof(buff));
				int x[100];
				j=0;
				for(i=0;i<n;i++)
				{
					if(a[i]%2==0)
					{
						x[j]=a[i];
						j++;
					}
				}
				buff[0]=j+'0';
				for(i=0;i<j;i++)
				{
					buff[i+1] = x[i]+'0';
				}
				sentbytes=send(newsockfd,buff,sizeof(buff),0);
				if(sentbytes==-1)
				{
					printf("!!");
					close(newsockfd);
				}
				memset(buff, '\0', sizeof(buff));
				j=0;
				for(i=0;i<n;i++)
				{
					if(a[i]%2!=0)
					{
						x[j]=a[i];
						j++;
					}
				}
				buff[0]=j+'0';
				for(i=0;i<j;i++)
				{
					buff[i+1] = x[i]+'0';
				}
				sentbytes=send(newsockfd,buff,sizeof(buff),0);
				if(sentbytes==-1)
				{
					printf("!!");
					close(newsockfd);
				}
			}
		
	}

	close(sockfd);
	close(newsockfd);
}

