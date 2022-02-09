#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 90

int main()
{
	int sockfd,retval,i;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr, clientaddr;
	char buff[MAXSIZE];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
		return 0;

	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3389);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	retval=bind(sockfd,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}

	while(1)
	{
		printf("\n\nEnter a string: ");
		fgets(buff,90,stdin);
		int i=0;
		while(buff[i]!='\0')
			i++;
		buff[i-1]='\0';
		sentbytes=sendto(sockfd,buff,sizeof(buff),0,
		(struct sockaddr*)&serveraddr,sizeof(serveraddr));

		if(sentbytes==-1)
		{
		printf("sending error");
		close(sockfd);
		}

		if (buff[0] == 'h' && buff[1] == 'a' && buff[2] == 'u' && buff[3] == 'l' && buff[4] == 't')
		{
			break;
		}
		int size=sizeof(serveraddr);
		recedbytes=recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serveraddr,&size);
		 
		if(buff[0]=='1')
			printf("\nIs a palindrome");
		else
			printf("\nIs not a palindrome");

		printf("\nLenght of string is: %d", buff[1]-'0');

		printf("\nNumber of A's in the string: %d", buff[2]-'0');
		printf("\nNumber of E's in the string: %d", buff[3]-'0');
		printf("\nNumber of I's in the string: %d", buff[4]-'0');
		printf("\nNumber of O's in the string: %d", buff[5]-'0');
		printf("\nNumber of U's in the string: %d", buff[6]-'0');

		
	}
	
	close(sockfd);
	return 0;
}
