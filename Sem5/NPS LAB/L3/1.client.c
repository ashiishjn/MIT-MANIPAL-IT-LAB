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
  int s, r, recb, sntb, x;
  struct sockaddr_in server;
  char buff[50], buff2[50];
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == -1) 
  {
    printf("\nSocket creation error.");
    exit(0);
  }
  printf("\nSocket created.");
  server.sin_family = AF_INET;
  server.sin_port = htons(3388);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  r = connect(s, (struct sockaddr * ) & server, sizeof(server));
  if (r == -1) 
  {
    printf("\nConnection error.");
    exit(0);
  }
  printf("\nSocket connected.");
  printf("\n\n");
  int pid;
  printf( "Original Process, PID : %d && PPID : %d\n" ,getpid() , getppid( )) ;
  pid = fork();
  
  while (1) 
  {
    if (pid > 0) 
    {
      printf( "Parent Process, PID : %d && PPID : %d\n" ,getpid() , getppid( )) ;
      //parent
      recb = recv(s, buff, sizeof(buff), 0);
      if (recb == -1) 
      {
        printf("\nMessage Recieving Failed");
        close(s);
        exit(0);
      }
      if (strcmp(buff, "BYE") == 0)
        break;
      printf("\nParent: ");
      printf("%s\n", buff);
    } 
    else 
    {
      printf( "Child Process, PID : %d && PPID : %d\n" ,getpid() , getppid( )) ;
      //child
      printf("\nChild: ");
      scanf("%s", buff2);
      sntb = send(s, buff2, sizeof(buff2), 0);
      if (sntb == -1) 
      {
        close(s);
        printf("\nMessage Sending Failed");
        exit(0);
      }
      if (strcmp(buff2, "BYE") == 0)
        break;
    }
  }
  close(s);
}
