#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>

int find_anagram(char array1[], char array2[])
{
    int num1[26] = {0}, num2[26] = {0}, i = 0;
 
    while (array1[i] != '\0')
    {
        num1[array1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (array2[i] != '\0')
    {
        num2[array2[i] -'a']++;
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
}
int main()
{
	int s,r,recb,sntb,x,ns,a=0;
	socklen_t len;
	struct sockaddr_in server,client;
	char buff[50],buff2[50],buff1[50];

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

	r=listen(s,8);
	if(r==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket listening. Waiting for connections..");

	while(1)
	{
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

	printf("\nClient socket address received is: \nPort number: %d\n",x);
	printf("IP address is: %s\n",buff);	

	recb=recv(ns,buff1,sizeof(buff1),0);
	if(recb==-1)
	{
		printf("\nMessage Recieving Failed");		
		close(s);
		close(ns);
		exit(0);
	}	
	printf("\nString 1 Recieved: ");
	printf("%s\n", buff1);

	recb=recv(ns,buff2,sizeof(buff2),0);
	if(recb==-1)
	{
		printf("\nMessage Recieving Failed");		
		close(s);
		close(ns);
		exit(0);
	}	
	printf("\nString 2 Recieved: ");
	printf("%s\n", buff2);

	//check for anagrams
	int flag = find_anagram(buff1, buff2);
    if (flag == 1)
        strcpy(buff,"Strings are anagrams");
    else
        strcpy(buff,"Strings are not anagrams");

	sntb=send(ns,buff,sizeof(buff),0);
	if(sntb==-1)
	{
		printf("\nMessage Sending Failed");
		close(s);
		close(ns);
		exit(0);
	}

	close(ns);
}
 	
	close(s);
}
