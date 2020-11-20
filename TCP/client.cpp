#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<iostream>
#include<arpa/inet.h>
#define MAXSIZE 50
using namespace std;
main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
char buff[MAXSIZE];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
cout<<"\nSocket Creation Error";

}
cout<<sockfd;
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
    cout<<"Connection error";

}
    cout<<"enter the text\n";

cin>>buff;


sentbytes=send(sockfd,buff,sizeof(buff),0);

if(sentbytes==-1)
{
    cout<<"!!";
close(sockfd);
}
recedbytes=recv(sockfd,buff,sizeof(buff),0);
cout<<buff;
cout<<"\n";
close(sockfd);
}

