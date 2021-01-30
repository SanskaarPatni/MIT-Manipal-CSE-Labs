#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#define FIFO_NAME "/home/sanskaar/180905134-OS/Lab5/fifosolved"
//#define FIFO_NAME "/home/student/180905134/OS/Lab5/fifo.txt"
#define BUFFER_SIZE PIPE_BUF
#define TEN_MEG 1024 * 1024 * 10

int main()
{
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    int bytes_read = 0;
    char buffer[BUFFER_SIZE + 1];
    memset(buffer, '\0', sizeof(buffer));
    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);
    if (pipe_fd != -1)
    {
        res = read(pipe_fd, buffer, BUFFER_SIZE);
        do
        {
            printf("%s", buffer);
            res = read(pipe_fd, buffer, BUFFER_SIZE);
        } while (res > 0);
        close(pipe_fd);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("Process %d  finished\n", getpid());
    exit(EXIT_SUCCESS);
}