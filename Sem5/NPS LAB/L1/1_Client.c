#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 100

int main()
{
	int sockfd,retval;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr;
	char buff[MAXSIZE];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
	printf("\nSocket Creation Error");

	}
	printf("%i",sockfd);
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
	printf("Connection error");

	}
	int count=0;
	while(1)
	{
		printf("\n\nEnter number of numbers in the array: ");
		int n, a[100],i;
		char x[100];
		scanf("%d", &n);
		buff[0]=n+'0';
		printf("Enter numbers: ");
		for(i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			buff[i+1] = a[i]+'0';
		}
		sentbytes=send(sockfd,buff,sizeof(buff),0);
		if(sentbytes==-1)
		{
			printf("!!");
			close(sockfd);
		}
		printf("Enter\n1. To search for a number\n2. To sort in ascending order\n3. To sort in descending order\n4. To split\n5. To exit\n");
		scanf("%s", buff);
		int m = buff[0]-'0';
		if(m==1)
		{
			printf("\nEnter number to search for: ");
			int xa;
			scanf("%d", &xa);
			buff[1]=xa+'0';
		}
		sentbytes=send(sockfd,buff,sizeof(buff),0);
		if(sentbytes==-1)
		{
			printf("!!");
			close(sockfd);
		}
		if(m==1)
		{
			recedbytes=recv(sockfd,buff,sizeof(buff),0);
			if(recedbytes==-1)
			{
				close(sockfd);
				close(sockfd);
			}
			if(buff[0]=='0')
				printf("\nNumber not found!");
			else{
				int xa=buff[0]-'0';
				printf("\nNumber found at position: %d", xa);
			}
		}
		else if(m==3 || m==2)
		{
			printf("\nSorted array is: ");
			recedbytes=recv(sockfd,buff,sizeof(buff),0);
			if(recedbytes==-1)
			{
				close(sockfd);
				close(sockfd);
			}
			for(i=0;i<n;i++)
			{
				a[i] = buff[i]-'0';
				printf("%d    ", a[i]);
			}
		}
		else if(m==4)
		{
			printf("\nEven array is: ");
			recedbytes=recv(sockfd,buff,sizeof(buff),0);
			if(recedbytes==-1)
			{
				close(sockfd);
				close(sockfd);
			}
			for(i=0;i<buff[0]-'0';i++)
			{
				a[i] = buff[i+1]-'0';
				printf("%d    ", a[i]);
			}
			printf("\nOdd array is: ");
			recedbytes=recv(sockfd,buff,sizeof(buff),0);
			if(recedbytes==-1)
			{
				close(sockfd);
				close(sockfd);
			}
			for(i=0;i<buff[0]-'0';i++)
			{
				a[i] = buff[i+1]-'0';
				printf("%d    ", a[i]);
			}
		}
		else
			break;
	}
	close(sockfd);
}
