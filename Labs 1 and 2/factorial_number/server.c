#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

main()
{
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;

int buff,buff_ans;
int a=0;
sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("\nSocket creation error");
}

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==1)
{
printf("Binding error");
close(sockfd);
}

retval=listen(sockfd,1);
if(retval==-1)
{
close(sockfd);
}

actuallen=sizeof(clientaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);


if(newsockfd==-1)
{
close(sockfd);
}
recedbytes=recv(newsockfd,&buff,sizeof(buff),0);

if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
}

//getting the input in buff(int)

int factorial=1;
for(int i=1; i<=buff; ++i)
{
    factorial *= i;              
}

buff_ans=factorial;


//send the output in buff_ans(int) to the server


sentbytes=send(newsockfd,&buff_ans,sizeof(buff_ans),0);

if(sentbytes==-1)
{
close(sockfd);
close(newsockfd);
}

close(sockfd);
close(newsockfd);
}