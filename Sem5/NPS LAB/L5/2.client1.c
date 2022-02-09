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
#include<netdb.h>
#include<errno.h>
int main()
{
	int s,r,recb,sntb,x;
	struct sockaddr_in server;
	char buff[50];
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");

	server.sin_family=AF_INET;
	server.sin_port=htons(3388);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

	r=connect(s,(struct sockaddr*)&server,sizeof(server));
	if(r==-1)
	{
		printf("\nConnection error.");
		exit(0);
	}
	printf("\nSocket connected.");
	/*struct hostent *host_entry;
	int hostname;
	char hostbuffer[256];
	char *ipbuffer;
	hostname=gethostname(hostbuffer,sizeof(hostbuffer));
	host_entry=gethostbyname(hostbuffer);
	ipbuffer = inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0]));*/
	char ip[50];
	strcpy(ip,"127.0.0.1");
	sntb=send(s,ip,sizeof(ip),0);
	if(sntb==-1)
	{
		close(s);
		printf("\nMessage Sending Failed");
		exit(0);
	}
	printf("\n\n");
	printf("Type string 1: ");
	scanf("%s", buff);

	sntb=send(s,buff,sizeof(buff),0);
	if(sntb==-1)
	{
		close(s);
		printf("\nMessage Sending Failed");
		exit(0);
	}
	printf("\n\n");
	printf("Type string 2: ");
	scanf("%s", buff);

	sntb=send(s,buff,sizeof(buff),0);
	if(sntb==-1)
	{
		close(s);
		printf("\nMessage Sending Failed");
		exit(0);
	}
	recb=recv(s,buff,sizeof(buff),0);
	if(recb==-1)
	{
		printf("\nMessage Recieving Failed");	
		close(s);
		exit(0);
	}
	
	printf("%s\n", buff);
	printf("\n\n");

	close(s);

}
