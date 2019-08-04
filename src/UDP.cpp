#include "UDP.h"
#include <stdio.h>

#ifdef __linux__
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#endif

UDPServer::UDPServer(sockaddr_in* addr)
{
   this->server_socket = socket(AF_INET, SOCK_DGRAM, 0);
   int rc = bind(server_socket, (sockaddr *)addr, sizeof(sockaddr_in));
   int i1 =1;
   setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&i1, sizeof(i1));
   printf("socket descriptor %d and result for bind call %d", server_socket, rc);

}

bool UDPServer::isRunning()
{
    return server_socket != -1;
}

#define MAXLINE  1024 
std::string UDPServer::recv()
{
   char buffer[MAXLINE+1]={0};
   socklen_t len, n; 
   sockaddr_in cliaddr;
#ifdef __linux__
    n = recvfrom(server_socket, (char *)buffer, MAXLINE,  
                MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                &len); 
#else
    n = recvfrom(server_socket, (char *)buffer, MAXLINE,  
                0, (sockaddr *) &cliaddr, 
                &len); 
    if(n>0)
       return std::string(buffer);
#endif
   return std::string("");
}