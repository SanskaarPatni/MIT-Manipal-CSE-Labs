#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void servfunc(int sockfd)
{
    char buff[MAX];
    int n;
    int num1 = 0;
    int num2 = 0;
    char op;
    int ans = 0;
    // infinite loop for chat
    for (int i = 0; i <= 2; i++)
    {
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        if (i == 0)
        {
            // for (i = 0; buff[i] != '\0'; i++)
            //     num1 = 10 * num1 + buff[i] - '0';
            sscanf(buff, "%d", &num1);
        }
        else if (i == 1)
        {
            op = buff[0];
        }
        else
        {
            sscanf(buff, "%d", &num2);
        }

        bzero(buff, sizeof(buff));
        // and send that buffer to client
        if (i == 2)
        {
            if (op == '+')
            {
                ans = num1 + num2;
            }
            else if (op == '-')
            {
                ans = num1 - num2;
            }
            else if (op == '*')
            {
                ans = num1 * num2;
            }
            else if (op == '/')
            {
                ans = num1 / num2;
            }
            sprintf(buff, "%ld", ans);
            write(sockfd, buff, sizeof(buff));
        }
    }
}

// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)
    {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");

    // Function for chatting between client and server
    servfunc(connfd);

    // After sending exit message close the socket
    close(sockfd);
}