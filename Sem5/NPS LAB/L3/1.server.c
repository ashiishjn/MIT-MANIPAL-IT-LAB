#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>

int main() 
{
  int s, r, recb, sntb, x, ns, a = 0;
  socklen_t len;
  struct sockaddr_in server, client;
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
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  r = bind(s, (struct sockaddr * ) & server, sizeof(server));
  if (r == -1) 
  {
    printf("\nBinding error.");
    exit(0);
  }
  printf("\nSocket binded.");
  r = listen(s, 1);
  if (r == -1) 
  {
    close(s);
    exit(0);
  }
  printf("\nSocket listening.");
  len = sizeof(client);
  ns = accept(s, (struct sockaddr * ) & client, & len);
  if (ns == -1) 
  {
    close(s);
    exit(0);
  }
  printf("\nSocket accepting.\n");
  int pid;
  printf( "Original Process, PID : %d && PPID : %d\n" ,getpid() , getppid( )) ;
  pid = fork();
  while (1) 
  {
    if (pid > 0) 
    {
      //parent
      printf( "Parent Process, PID : %d && PPID : %d\n" ,getpid() , getppid( )) ;
      printf("\n\nParent: ");
      scanf("%s", buff2);
      sntb = send(ns, buff2, sizeof(buff2), 0);
      if (sntb == -1) 
      {
        printf("\nMessage Sending Failed");
        close(s);
        close(ns);
        exit(0);
      }
      if (strcmp(buff2, "BYE") == 0)
        break;
    } 
    else 
    {
      //child
      printf( "Child Process, PID : %d && PPID : %d\n" ,getpid() , getppid( )) ;
      recb = recv(ns, buff, sizeof(buff), 0);
      if (recb == -1) 
      {
        printf("\nMessage Recieving Failed");
        close(s);
        close(ns);
        exit(0);
      }
      if (strcmp(buff, "BYE") == 0)
        break;
      printf("\nChild: ");
      printf("%s\n", buff);
    }
  }
  close(ns);
  close(s);
}	
