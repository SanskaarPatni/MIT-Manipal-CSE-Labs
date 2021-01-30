#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 5000
#define MAXLINE 1000

// Driver code
int main()
{
    char buffer[100];
    char *message = "Hello Server";
    int sockfd, n, len;
    struct sockaddr_in servaddr, cliaddr;

    // clear servaddr
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    //sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sendto(sockfd, message, MAXLINE, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    len = sizeof(cliaddr);
    // n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
    // waiting for response
    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Message from server is,  %s \n", buffer);
    getchar();

    // close the descriptor
    close(sockfd);
}