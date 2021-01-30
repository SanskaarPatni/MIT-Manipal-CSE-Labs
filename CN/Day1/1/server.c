#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 5000
#define MAXLINE 1000

int main()
{
    printf("Server code running\n");
    char buffer[100];
    int servsockfd, len, n;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));

    // Create a UDP Socket
    servsockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    // bind server address to socket descriptor
    bind(servsockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    // infinite loop for chat
    for (;;)
    {
        bzero(buffer, 80);
        len = sizeof(cliaddr);
        n = recvfrom(servsockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        // buffer[n] = '\0';
        if ((strncmp(buffer, "exit", 4)) == 0)
        {
            printf("Client Exit...\n");
            break;
        }
        puts(buffer);
    }
    // close the descriptor
    close(servsockfd);
}