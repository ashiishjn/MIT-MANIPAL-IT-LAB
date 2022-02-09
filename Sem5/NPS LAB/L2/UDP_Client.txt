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
	int s,r,recb,sntb,x;
	int sa;
	socklen_t len;
	printf("INPUT port number: ");
	scanf("%d", &x);
	struct sockaddr_in server,client;
	char buff[50];
	s=socket(AF_INET,SOCK_DGRAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");
	server.sin_family=AF_INET;
	server.sin_port=htons(x);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa=sizeof(server);
	len=sizeof(server);
	printf("\n\n");
	printf("Type File Name: ");
	scanf("%s", buff);
	sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	if(sntb==-1)
	{
		close(s);
		printf("\nMessage sending Failed");
		exit(0);
	}
	recb=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr *)&server,&sa);
	if(recb==-1)
	{
		printf("\nMessage Recieving Failed");	
		close(s);
		exit(0);
	}
	printf("\n");
	printf("%s", buff);
	printf("\n\n");
	if(strcmp(buff,"File does not exist!")==0)
	{
		close(s);
		exit(0);
	}
	int ch=0;
	while(ch!=4)
	{
		printf("\n1.Search\n2.Replace\n3.Reorder\n4.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		buff[0]=ch;
		char str1[50],str2[50];
		int n,i,j;
		switch(ch)
		{
			case 1:printf("\nEnter string to be searched: ");
			scanf("%s",str1);
			n=strlen(str1);
			buff[1]=n;
			for(i=0;i<n;i++)
				buff[i+2]=str1[i];
			buff[i+2]='\0';
			sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	       if(sntb==-1)
	       {
	       	close(s);
	       	printf("\nMessage sending Failed");
	       	exit(0);
	       }
			recb=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr *)&server,&sa);
	       if(recb==-1)
	       {
		      printf("\nMessage Recieving Failed");	
		      close(s);
		      exit(0);
	       }
			n=buff[0];
			printf("\nWord found %d number of times!\n",n);
			break;

			case 2:printf("\nEnter string to be searched and replaced: ");
			scanf("%s",str1);
			n=strlen(str1);
			buff[1]=n;
			for(i=0;i<n;i++)
				buff[i+2]=str1[i];
			buff[i+2]='\0';
			sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	       if(sntb==-1)
	       {
	       	close(s);
	       	printf("\nMessage sending Failed");
	       	exit(0);
	       }
			printf("\nEnter new string: ");
			scanf("%s",str2);
			n=strlen(str2);
			buff[1]=n;
			i=2;
			for(j=0;j<n;j++)
			{
				buff[i]=str2[j];
				i++;
			}
			buff[i]='\0';
			sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	       if(sntb==-1)
	       {
	       	close(s);
	       	printf("\nMessage sending Failed");
	       	exit(0);
	       }
			recb=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr *)&server,&sa);
	       if(recb==-1)
	       {
	       	printf("\nMessage Recieving Failed");	
	       	close(s);
	       	exit(0);
	       }
			printf("%s\n",buff);
			break;

			case 3:sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	       if(sntb==-1)
	       {
	          	close(s);
	       	printf("\nMessage sending Failed");
	       	exit(0);
	       }
					recb=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr *)&server,&sa);
	       if(recb==-1)
	       {
	       	printf("\nMessage Recieving Failed");	
	       	close(s);
	       	exit(0);
	       }
			printf("%s\n",buff);
			break;
			case 4:sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
	       if(sntb==-1)
	       {
	       	close(s);
	              	printf("\nMessage sending Failed");
		      exit(0);
	       }
			break;
			default:
			printf("\n Try Again!\n");
		}
	}
	close(s);

}