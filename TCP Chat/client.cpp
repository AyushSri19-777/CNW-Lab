#include<bits/stdc++.h>
#include<sys/types.h>
//#include <sys/types.h> 
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<signal.h>

using namespace std;
int main()
{
    int sockfd,retval;
    int recedbytes,sentbytes;
    struct sockaddr_in serveraddr;
    char buff[50];
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1)
        exit(0);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(3387);
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    if(retval==-1)
        exit(0);
	
    string name;
    getline(cin,name);
    
	string z;
	int pid = fork();
	//string name;    
	while(1)
    //child
    {
	if(pid == 0){
        getline(cin,name);
    	strcpy(buff,name.c_str());
	sentbytes=send(sockfd,buff,sizeof(buff),0);
	//send
    z = buff;
    if(z=="bye"){
        kill(getppid(),SIGTERM);
        kill(getpid(),SIGTERM);
        
    }
    	
	}
	else{
	//parent
	
	//receive    	
	recedbytes=recv(sockfd,buff,sizeof(buff),0);
    	puts(buff);
       z = buff;
       if(z == "bye"){
            //cout<<"hi02";
			kill(pid,SIGTERM);
            kill(getpid(),SIGTERM);
		}
	
	}

    }
    close(sockfd);

}
