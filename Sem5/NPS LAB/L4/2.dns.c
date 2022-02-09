#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int s,r,recb,sntb,x,ns;
	int s1,r1,recb1,sntb1,x1;

	s1=socket(AF_INET,SOCK_STREAM,0);
	if(s1==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nDNS Client Socket created.");
	struct sockaddr_in server1;
	server1.sin_family=AF_INET;
	server1.sin_port=htons(3388);
	server1.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=connect(s1,(struct sockaddr*)&server1,sizeof(server1));
	if(r==-1)
	{
		printf("\nConnection error.");
		exit(0);
	}
	printf("\nSocket connected.");


	socklen_t len;
	struct sockaddr_in server,client;
	char buff[100];
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nDNS Server Socket created.");
	server.sin_family=AF_INET;
	server.sin_port=htons(3388);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	r=bind(s,(struct sockaddr*)&server,sizeof(server));
	if(r==-1)
	{
		printf("\nBinding error.");
		exit(0);
	}
	printf("\nDNS Server Socket binded.");
	r=listen(s,1);
	if(r==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nDNS Server Socket listening.");
	len=sizeof(client);
  ns=accept(s,(struct sockaddr*)&client, &len);
	if(ns==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nDNS Server Socket accepting.");

	
	recb=recv(ns,buff,sizeof(buff),0);
		if(recb==-1)
		{
			printf("\nMessage Recieving Failed");	
			close(s);
			exit(0);
		}
	sntb=send(s1,buff,sizeof(buff),0);
		if(sntb==-1)
		{
			close(s);
			printf("\nMessage Sending Failed");
			exit(0);
		}
	recb=recv(s1,buff,sizeof(buff),0);
		if(recb==-1)
		{
			printf("\nMessage Recieving Failed");	
			close(s);
			exit(0);
		}
	sntb=send(ns,buff,sizeof(buff),0);
		if(sntb==-1)
		{
			close(s);
			printf("\nMessage Sending Failed");
			exit(0);
		}	
		close(s);
		close(s1);
		close(ns);
}
