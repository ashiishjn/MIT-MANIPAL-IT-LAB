#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
struct dns
{
	char ip[15];
	char name[20];
};
int main()
{
	int s,r,recb,sntb,x,ns,a=0;
	socklen_t len;
	struct sockaddr_in server,client;
	char buff[100];

	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");

	server.sin_family=AF_INET;
	server.sin_port=htons(3388);
	server.sin_addr.s_addr=htonl(INADDR_ANY);

	r=bind(s,(struct sockaddr*)&server,sizeof(server));
	if(r==-1)
	{
		printf("\nBinding error.");
		exit(0);
	}
	printf("\nSocket binded.");

	r=listen(s,1);
	if(r==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket listening.");

	len=sizeof(client);

	ns=accept(s,(struct sockaddr*)&client, &len);
	if(ns==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket accepting.");
	recb=recv(ns,buff,sizeof(buff),0);
	if(recb==-1)
	{
		printf("\nMessage Recieving Failed");		
		close(s);
		close(ns);
		exit(0);
	}	
	struct dns d[2];
	strcpy(d[0].ip,"176.0.0.2");
	strcpy(d[1].ip,"176.0.0.1");
	strcpy(d[0].name,"google.com");
	strcpy(d[1].name,"facebook.com");
	if(strcmp(buff,d[0].ip)==0)
		strcpy(buff,d[0].name);
	else if(strcmp(buff,d[1].ip)==0)
		strcpy(buff,d[1].name);
	else
		strcpy(buff,"Could not find IP");
	sntb=send(ns,buff,sizeof(buff),0);
		if(sntb==-1)
		{
			close(s);
			printf("\nMessage Sending Failed");
			exit(0);
		}	
		close(ns);
		close(s);
	}
