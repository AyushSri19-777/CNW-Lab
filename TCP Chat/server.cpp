#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

using namespace std;
int main()
{
    int sockfd,newsockfd,retval;
    socklen_t actuallen;
    int recedbytes,sentbytes;
    struct sockaddr_in serveraddr,clientaddr;
    char buff[50];
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        cout<<"hi";
        exit(0);
    }
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(3387);
    serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
    retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    if(retval==-1){
        cout<<"hi1";
        exit(0);
    }
    retval=listen(sockfd,1);
    if(retval==-1){
        cout<<"hi2";
        exit(0);
    }
    actuallen=sizeof(clientaddr);
    newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);
    if(newsockfd==-1){
        cout<<"hi3";
        exit(0);
    }
	int pid;

    	pid = fork();
	string a;
    string hi;
    int flag = 0;
    while(1)
    {	
	if(pid==0){
	//child process
		
		recedbytes=recv(newsockfd,buff,sizeof(buff),0);
		puts(buff);
        hi = buff;
        if(hi=="bye"){
            kill(getppid(),SIGTERM);
            kill(getpid(),SIGTERM);
        }
	}
	else{
	//parent process
	
		getline(cin,a);
		
		strcpy(buff,a.c_str());
		        	
		send(newsockfd,buff,sizeof(buff),0);
        hi = buff;
		if(hi == "bye"){
            //cout<<"hi02";
			kill(pid,SIGTERM);
            kill(getpid(),SIGTERM);
		}
		
	}
    }
    close(newsockfd);
    close(sockfd);
}
