#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

char isPalindrome(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;
 
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return '0';
        }
    }
    return '1';
}
int main()
{
	int sockfd,newsockfd,retval,i;
	socklen_t actuallen;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;

	char buff[MAXSIZE];
	int a=0;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	if(sockfd==-1)
	{
		printf("\nSocket creation error");
	}
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3389);
	clientaddr.sin_addr.s_addr=htons(INADDR_ANY);


	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);

	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}
	
	for (i = 0; ; i+=1)
	{
		
		actuallen=sizeof(clientaddr);
		recedbytes=recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&clientaddr,&actuallen);

		if(recedbytes==-1)
		{
			printf("Reciving error\n");
			close(sockfd);
		}

		if (buff[0] == 'h' && buff[1] == 'a' && buff[2] == 'u' && buff[3] == 'l' && buff[4] == 't')
		{
			break;
		}		

		char a[100], b[100];
		strcpy(b, buff);
		strcpy(a, buff);  
		
		buff[0]=isPalindrome(a);

		int len=0,x=0,e=0,i=0,o=0,u=0;
		while(b[len]!='\0')
		{
			if(b[len]=='a'|| b[len]=='A')
				x++;
			if(b[len]=='e'|| b[len]=='E')
				e++;
			if(b[len]=='i'|| b[len]=='I')
				i++;
			if(b[len]=='o'|| b[len]=='O')
				o++;
			if(b[len]=='u'|| b[len]=='U')
				u++;
			len++;
		}
		buff[1]=len+'0';
		buff[2]=x+'0';
		buff[3]=e+'0';
		buff[4]=i+'0';
		buff[5]=o+'0';
		buff[6]=u+'0';

		sentbytes=sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
		if(sentbytes==-1)
		{
			printf("sending error");
			close(sockfd);
		}

	}

	
	return 0;
	close(sockfd);
	close(newsockfd);
}

